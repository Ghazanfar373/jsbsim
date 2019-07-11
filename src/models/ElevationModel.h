/*
 * ElevationModel.h
 *
 *  Created on: Sep 19, 2013
 *      Author: sim-paf
 */

#ifndef ELEVATIONMODEL_H_
#define ELEVATIONMODEL_H_

#include <gdal/gdal.h>
#include <gdal/cpl_conv.h>
#include <gdal/gdal_priv.h>
#include <gdal/cpl_vsi_virtual.h>
#include <iostream>

#include <string>
#include <algorithm>


#include "FGModel.h"
using namespace std;

#define EARTH_RADIUS 6378137.0

namespace JSBSim{


class ElevationModel:public FGModel {

public:

	class srtmInfo{
	private:
		double minLat;
		double minLng;
		double maxLat;
		double maxLng;
		GDALDataset *dataset;
		double geoTransform[6];
		GDALRasterBand *rasterBand;
		int lat_index, lng_index;
		string filePath;

	public:
		srtmInfo(string path){
			setFilePath(path);

			dataset = (GDALDataset *) GDALOpen( filePath.c_str(), GA_ReadOnly );
			if (dataset == NULL)	{
					cout<<"Can't Open srtm file  "<<filePath<<endl;
					minLat = minLng = maxLat = maxLng = 0.0;
			}else{
				dataset->GetGeoTransform(geoTransform);
				double temp = geoTransform[0]+geoTransform[1]*dataset->GetRasterXSize();
				cout<<filePath<<endl;
				cout<<geoTransform[0]<<" "<<geoTransform[1]<<" "<<dataset->GetRasterXSize()<<endl;
				if (geoTransform[1] < 0.0){
					minLng = temp;
					maxLng = geoTransform[0];
				}else{
					minLng = geoTransform[0];
					maxLng = temp;
				}

				temp = geoTransform[3]+geoTransform[5]*dataset->GetRasterYSize();
				cout<<geoTransform[3]<<" "<<geoTransform[5]<<" "<<dataset->GetRasterYSize()<<endl;
				if (geoTransform[5] < 0.0){
					minLat = temp;
					maxLat = geoTransform[3];
				}else{
					minLat = geoTransform[3];
					maxLat = temp;
				}

				cout<<"min "<<minLat<<", "<<minLng<<" max "<<maxLat<<", "<<maxLng<<endl;
				rasterBand = dataset->GetRasterBand(1);
				//getchar();
//				GDALClose(dataset);
			}
		}


		bool isContain(double lat, double lng){
			return (lat>=minLat &&
					 lat<=maxLat &&
					 lng>=minLng &&
					 lng<=maxLng);
		}

		void setFilePath(string path){
			filePath.assign(path);
		}

		void calculateIndex(double lat, double lng){

			lng_index = (lng-geoTransform[0])/geoTransform[1];
			lat_index = (lat-geoTransform[3])/geoTransform[5];


		}

		int getElevation(double lat, double lng){
			calculateIndex(lat, lng);
			int nBlockXSize,nBlockYSize;
			rasterBand->GetBlockSize( &nBlockXSize, &nBlockYSize );
			int nXBlocks = (rasterBand->GetXSize() + nBlockXSize - 1) / nBlockXSize;
			int nYBlocks = (rasterBand->GetYSize() + nBlockYSize - 1) / nBlockYSize;
			GInt16 *pabyData1 = (GInt16 *) CPLMalloc(nBlockXSize * nBlockYSize*sizeof(GInt16));
			GInt16 *pabyData2 = (GInt16 *) CPLMalloc(nBlockXSize * nBlockYSize*sizeof(GInt16));
			rasterBand->ReadBlock(0, lat_index, pabyData1);
			rasterBand->ReadBlock(0, lat_index+1, pabyData2);

			double lat1 = lat_index * geoTransform[5] + geoTransform[3];
			double lat2 = (lat_index+1) * geoTransform[5] + geoTransform[3];
			double lng1 = lng_index * geoTransform[1] + geoTransform[0];
			double lng2 = (lng_index+1) * geoTransform[1] + geoTransform[0];

////////////////////////////////////////////////////////////////////
//						lng1		lng		lng2
//			________________________________________________
//					|
//			lat1	|	elevation11 		elevation21
//					|
//			lat		|
//					|
//			lat2	|	elevation12			elevation22
//			________|________________________________________
//
////////////////////////////////////////////////////////////////////


			int elevation11 = pabyData1[lng_index];
			int elevation21 = pabyData1[lng_index+1];
			int elevation12 = pabyData2[lng_index];
			int elevation22 = pabyData2[lng_index+1];
			double elevation;
			double dlat = (lat1 - lat)/geoTransform[1];
			double dlng = (lng1 - lng)/geoTransform[5];
//			cout<<lat_index<<","<<lng_index<<" "<<lat<<","<<lng<<": "<<endl;
//
//			cout<<"\t\t"<<lng1<<"\t\t"<<lng2<<endl;
//			cout<<lat1<<"\t"<<elevation11<<"\t\t\t"<<elevation21<<endl;
//			cout<<lat2<<"\t"<<elevation12<<"\t\t\t"<<elevation22<<endl;



			//Bi-Linear Interpolation
			elevation = 1/((lat2-lat1)*(lng2-lng1))*(elevation11*(lng2-lng)*(lat2-lat)+
													 elevation21*(lng-lng1)*(lat2-lat)+
													 elevation12*(lng2-lng)*(lat-lat1)+
													 elevation22*(lng-lng1)*(lat-lat1));
//			cout<<"interpolated value = "<<elevation<<endl;
			delete pabyData1;
			delete pabyData2;
			return elevation;

		}
		void printInfo(){

//			cout<<"File Path: "<<filePath.c_str()<<endl;
//			cout<<"minimum (Lat, Lng): "<<minLat<<","<<minLng<<endl;
//			cout<<"maximum (Lat, Lng): "<<maxLat<<","<<maxLng<<endl;
//			cout<<"Origin  (Lat, Lng): "<<geoTransform[0]<<","<<geoTransform[3]<<endl;
//			cout<<"Res     (Lat, Lng): "<<geoTransform[1]<<","<<geoTransform[5]<<endl<<endl;

		}

	};

	ElevationModel(FGFDMExec*);
	bool InitModel(void);
	bool Run(bool Holding);
	void searchRegion(double, double);
	void printAllSRTMs();

	virtual ~ElevationModel();

private:
	string rootPath;
	int lat_index;
	int lng_index;
	int elevation;
	double CalculatedAGL;
	bool ElevationCalcFlag;

	GDALDataset *currentDataset;
	double currentGeoTransform[6];
	GDALRasterBand *currentRasterBand;
	vector<srtmInfo>::iterator currentSRTM;
	bool exist;

	double currentLat, currentLng;

	VSIFilesystemHandler *fileHandle;
	vector<string> allFiles;
	//typedef allocator<srtmInfo> srtm_allocator;
	vector<srtmInfo> srtmFiles;

	void bind(void);
};

}
#endif /* ELEVATIONMODEL_H_ */
