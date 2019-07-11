/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 Module:       FGAircraft.cpp
 Author:       Jon S. Berndt
 Date started: 12/12/98
 Purpose:      Encapsulates an aircraft
 Called by:    FGFDMExec

 ------------- Copyright (C) 1999  Jon S. Berndt (jon@jsbsim.org) -------------

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU Lesser General Public License as published by the Free Software
 Foundation; either version 2 of the License, or (at your option) any later
 version.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 details.

 You should have received a copy of the GNU Lesser General Public License along with
 this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 Place - Suite 330, Boston, MA  02111-1307, USA.

 Further information about the GNU Lesser General Public License can also be found on
 the world wide web at http://www.gnu.org.

FUNCTIONAL DESCRIPTION
--------------------------------------------------------------------------------
Models the aircraft reactions and forces. This class is instantiated by the
FGFDMExec class and scheduled as an FDM entry.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
COMMENTS, REFERENCES,  and NOTES
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
INCLUDES
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/


#include <iostream>
#include <cmath>

#include "ElectricalSystem.h"
#include "FGFDMExec.h"
#include "input_output/FGPropertyManager.h"

using namespace std;

namespace JSBSim {

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
DEFINITIONS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
GLOBAL DATA
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

static const char *IdSrc = "$Id: ElectricalSystem.cpp";
static const char *IdHdr = ID_ELECTRICAL;

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
CLASS IMPLEMENTATION
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

ElectricalSystem::ElectricalSystem(FGFDMExec* fdmex) : FGModel(fdmex)
{
  bind();
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ElectricalSystem::~ElectricalSystem()
{

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

bool ElectricalSystem::InitModel(void)
{
    GeneratorSwitch = false;
    GeneratorStatus = false;
    GeneratorIndicatorLight = false;
    ACBusVoltage = 0;
    ACBusIndicatorLight = false;
    InverterSwitch = false;
    DCBusVoltage = 0;
    DCBusIndicatorLight = false;
    BatteryStatus = false;
    BatteryVoltage = 0;

    // EngineRPM
    EngineRPM = 0;

  return true;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

bool ElectricalSystem::Run(bool Holding)
{
  if (FGModel::Run(Holding)) return true;
  if (Holding) return false;

    EngineRPM = PropertyManager->GetNode()->GetLong("propulsion/engine[0]//propeller.rpm",0);
    GeneratorOperation();
    ACBusOperation();
    DCBusOperation();
    BatteryOperation();

  return false;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void ElectricalSystem::GeneratorOperation()
{   if (EngineRPM>=1000 && GeneratorSwitch)
    {
        GeneratorStatus = true;
    }
    else
    {
        GeneratorStatus = false;
    }
    if (GeneratorStatus)
    {
        GeneratorIndicatorLight = true;
    }
    else
    {
        GeneratorIndicatorLight = false;
    }
}

void ElectricalSystem::ACBusOperation()
{
    if (GeneratorStatus)
    {
        ACBusVoltage = 120.0;
    }
    else
    {
        ACBusVoltage = 0;
    }
    if (ACBusVoltage>100)
    {
        ACBusIndicatorLight = true;
    }
    else
    {
        ACBusIndicatorLight = false;
    }
}

void ElectricalSystem::DCBusOperation()
{
    if (InverterSwitch && ACBusVoltage>100)
    {
        DCBusVoltage = 28.0;
    }
    else
    {
        DCBusVoltage = 0;
    }
    if (DCBusVoltage<24.0)
    {
        DCBusVoltage = BatteryVoltage;
    }
    if (DCBusVoltage>15)
    {
        DCBusIndicatorLight = true;
    }
    else
    {
        DCBusIndicatorLight = false;
    }
}

void ElectricalSystem::BatteryOperation()
{
    if (BatteryStatus)
    {
        BatteryVoltage = 24;
    }
    else
    {
        BatteryVoltage = 0;
    }
}


void ElectricalSystem::bind(void)
{
    //Generator
    PropertyManager->Tie("ElectricalSystem/Generator/Status",&GeneratorStatus);
    PropertyManager->Tie("ElectricalSystem/Generator/GeneratorIndicatorLight",&GeneratorIndicatorLight);
    PropertyManager->Tie("ElectricalSystem/Generator/GeneratorSwitch",&GeneratorSwitch);
    PropertyManager->Tie("ElectricalSystem/Generator/Status",&GeneratorStatus);
    //AC Bus
    PropertyManager->Tie("ElectricalSystem/ACBus/ACBusIndicatorLight",&ACBusIndicatorLight);
    PropertyManager->Tie("ElectricalSystem/ACBus/ACBusVoltage",&ACBusVoltage);
    //DC Bus
    PropertyManager->Tie("ElectricalSystem/DCBus/InverterSwitch",&InverterSwitch);
    PropertyManager->Tie("ElectricalSystem/DCBus/DCBusVoltage",&DCBusVoltage);
    PropertyManager->Tie("ElectricalSystem/DCBus/DCBusIndicatorLight",&DCBusIndicatorLight);
    //Battery Bus
    PropertyManager->Tie("ElectricalSystem/Battery/BatteryStatus",&BatteryStatus);
    PropertyManager->Tie("ElectricalSystem/Battery/BatteryVoltage",&BatteryVoltage);
}



} // namespace JSBSim
