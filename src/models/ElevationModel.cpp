/*
 * ElevationModel.cpp
 *
 *  Created on: Sep 19, 2013
 *      Author: sim-paf
 */

#include <dirent.h>
#include "FGFDMExec.h"
#include "ElevationModel.h"
using namespace std;
namespace JSBSim{

ElevationModel::ElevationModel(FGFDMExec *fdmex):FGModel(fdmex) {
}

bool ElevationModel::InitModel(){

	cout<<"In elevation costructor!"<<endl;
    CalculatedAGL = 0;
	ElevationCalcFlag = false;
	GDALAllRegister();

    rootPath.assign("../../srtm/");
	DIR *dp;
	struct dirent *dirp;

	if ((dp = opendir(rootPath.c_str()))==NULL){
		cout<<"SRTM Data: No such directory!"<<endl;
	}

	while ((dirp = readdir(dp))!=NULL){

		if (!strcmp(dirp->d_name,"..")||
			!strcmp(dirp->d_name,".")) continue;

		srtmInfo temp(rootPath+dirp->d_name+"/"+dirp->d_name+".tif");
		srtmFiles.push_back(temp);

	}
	currentSRTM = srtmFiles.begin();
	bind();
	return true;
}

ElevationModel::~ElevationModel() {
	// TODO Auto-generated destructor stub
}


void ElevationModel::searchRegion(double Lat, double Lng){

	exist = true;
	if ( currentSRTM->isContain(Lat, Lng)) return;
	vector<srtmInfo>::iterator itr=srtmFiles.begin();
	for (;itr->isContain(Lat, Lng)!=true &&
		  itr!=srtmFiles.end();
		  itr++);//itr->printInfo();
	if (itr != srtmFiles.end()){
		currentSRTM = itr;

	}else exist = false;

}



void ElevationModel::printAllSRTMs(){

	for (vector<srtmInfo>::iterator itr=srtmFiles.begin();
			itr!=srtmFiles.end();
			itr++)
		itr->printInfo();
}

bool ElevationModel::Run(bool Holding){


	if (FGModel::Run(Holding)) return true;  // Fast return if we have nothing to do ...
	if (Holding) return false;
	currentLat = FDMExec->GetPropagate()->GetLatitudeDeg();
	currentLng = FDMExec->GetPropagate()->GetLongitudeDeg();
	searchRegion(currentLat, currentLng);
	//currentSRTM->printInfo();
	if (exist)
	{
		ElevationCalcFlag = true;
        double asl = PropertyManager->GetNode()->GetDouble("position/h-sl-ft",0)*fttom;
        elevation = currentSRTM->getElevation(currentLat, currentLng);
        double asl1 = PropertyManager->GetNode()->GetDouble("position/h-sl-ft",0);
        //CalculatedAGL = asl1 - 61.0;
        CalculatedAGL = asl1 - elevation*3.280;
        //cout<<"Elevation: "<<elevation<<endl;
        //cout<<"Calculated AGL: "<<CalculatedAGL<<endl<<"Calculated ASL: "<<asl1<<endl;
	}
	else
	{
        ElevationCalcFlag = false;
	}


}

void ElevationModel::bind(){

	PropertyManager->Tie("ElevationModel/elevation_srtm_m",&elevation);
	PropertyManager->Tie("ElevationModel/CalculatedAGL",&CalculatedAGL);
	PropertyManager->Tie("ElevationModel/ElevationCalcFlag",&ElevationCalcFlag);
}

}
