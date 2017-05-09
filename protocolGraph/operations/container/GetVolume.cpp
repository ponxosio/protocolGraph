/*
 * GetVolume.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#include "GetVolume.h"

GetVolume::GetVolume() : ActuatorsOperation() {
	this->sourceId = -1;
	this->receiver = std::shared_ptr<VariableEntry>();
}

GetVolume::GetVolume(const GetVolume& node) : ActuatorsOperation(node){
	this->sourceId = node.sourceId;
	this->receiver = node.receiver;
}

GetVolume::GetVolume(
        int containerId,
        const std::string & sourceId,
        std::shared_ptr<VariableEntry> receiver) :
    ActuatorsOperation(containerId)
{
    this->sourceId = sourceId;
	this->receiver = receiver;
}

GetVolume::~GetVolume() {}

std::string GetVolume::toText() {
    return std::to_string(containerID) + "[label=\""
            + (receiver ? receiver->toString() : "?")
            + " = getVolume(" + sourceId + ")\"];";
}

void GetVolume::execute(ActuatorsExecutionInterface* actuatorsExecution) throw(std::invalid_argument)  {
    units::Volume virtualVolume = actuatorsExecution->getVirtualVolume(sourceId);
    receiver.get()->setValue(Utils::toDefaultUnits(virtualVolume));
}
