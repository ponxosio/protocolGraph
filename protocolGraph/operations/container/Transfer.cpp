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
    this->volume = NULL;
    this->volumeUnits = units::l;
    this->opDuration = NULL;
}

Transfer::Transfer(const Transfer& obj)  :
		ActuatorsOperation(obj) {

	this->idSource = obj.idSource;
	this->idTarget = obj.idTarget;
	this->volume = obj.volume;
    this->volumeUnits = obj.volumeUnits;
    this->opDuration = obj.opDuration;
}

Transfer::Transfer(
        int idContainer,
        const std::string & idSource,
        const std::string & idTarget,
        std::shared_ptr<MathematicOperable> volume,
        units::Volume volumeUnits,
        std::shared_ptr<VariableEntry> opDuration) :
    ActuatorsOperation(idContainer)
{
    this->idSource = idSource;
    this->idTarget = idTarget;
    this->volume = volume;
    this->volumeUnits = volumeUnits;
    this->opDuration = opDuration;
}

std::string Transfer::toText() {
    return std::to_string(containerID) + "[label=\"Transfer("
            + idSource + ", " + idTarget + ", " + volume.get()->toString() + ")\"];";
}

Transfer::~Transfer() {
	// TODO Auto-generated destructor stub
}

void Transfer::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument)  {
    units::Time duration = actuatorInterface->transfer(idSource, idTarget, volume.get()->getValue() * volumeUnits);
    opDuration->setValue(Utils::toDefaultUnits(duration));
}
