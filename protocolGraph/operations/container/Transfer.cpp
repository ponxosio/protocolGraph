/*
 * Transfer.cpp
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#include "Transfer.h"

Transfer::Transfer() :
		ActuatorsOperation() {
	this->idSource = -1;
	this->idTarget = -1;
	this->volume = std::shared_ptr<MathematicOperable>();
    this->volumeUnits = units::l;
}

Transfer::Transfer(const Transfer& obj)  :
		ActuatorsOperation(obj) {

	this->idSource = obj.idSource;
	this->idTarget = obj.idTarget;
	this->volume = obj.volume;
    this->volumeUnits = obj.volumeUnits;
}

Transfer::Transfer(int idContainer, int idSource, int idTarget, std::shared_ptr<MathematicOperable> volume, units::Volume volumeUnits) :
		ActuatorsOperation(idContainer) {

	this->idSource = idSource;
	this->idTarget = idTarget;
	this->volume = volume;
    this->volumeUnits = volumeUnits;
}

std::string Transfer::toText() {
    return std::to_string(containerID) + "[label=\"Transfer("
            + std::to_string(idSource) + ", " + std::to_string(idTarget)
			+ ", " + volume.get()->toString() + ")\"];";
}

Transfer::~Transfer() {
	// TODO Auto-generated destructor stub
}

void Transfer::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument)  {
    actuatorInterface->transfer(idSource, idTarget, volume.get()->getValue() * volumeUnits);
}
