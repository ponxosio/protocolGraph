/*
 * Mix.cpp
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#include "Mix.h"

Mix::Mix() :
    ActuatorsOperation()
{
	this->idSource1 = -1;
	this->idSource2 = -1;
	this->idTarget = -1;
	this->volume1 = std::shared_ptr<MathematicOperable>();
	this->volume2 = std::shared_ptr<MathematicOperable>();
    this->unitsVolume1 = units::l;
    this->unitsVolume2 = units::l;
}

Mix::Mix(const Mix& node) :
    ActuatorsOperation(node)
{
	this->idSource1 = node.idSource1;
	this->idSource2 = node.idSource2;
	this->idTarget = node.idTarget;
	this->volume1 = node.volume1;
	this->volume2 = node.volume2;
    this->unitsVolume1 = node.unitsVolume1;
    this->unitsVolume2 = node.unitsVolume2;
}

Mix::Mix(int idConatiner,
         int idSource1,
         int idSource2,
         int idTarget,
         std::shared_ptr<MathematicOperable> volume1,
         units::Volume unitsVolume1,
         std::shared_ptr<MathematicOperable> volume2,
         units::Volume unitsVolume2) :
    ActuatorsOperation(idConatiner)
{
	this->idSource1 = idSource1;
	this->idSource2 = idSource2;
	this->idTarget = idTarget;
	this->volume1 = volume1;
	this->volume2 = volume2;
    this->unitsVolume1 = unitsVolume1;
    this->unitsVolume2 = unitsVolume2;
}

Mix::~Mix() {
}

std::string Mix::toText() {
    return std::to_string(containerID) + "[label=\"Mix("
            + std::to_string(idSource1) + ", " + std::to_string(idSource2)
            + ", " + std::to_string(idTarget) + ", "
			+ volume1.get()->toString() + ", " + volume2.get()->toString()
			+ ")\"];";
}

void Mix::execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument)  {
    actuatorsInterface->mix(idSource1,
                            idSource2,
                            idTarget,
                            volume1.get()->getValue() * unitsVolume1,
                            volume2.get()->getValue() * unitsVolume2);
}
