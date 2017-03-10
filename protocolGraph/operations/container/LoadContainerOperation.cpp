/*
 * LoadContainer.cpp
 *
 *  Created on: 5 de abr. de 2016
 *      Author: angel
 */

#include "LoadContainerOperation.h"

LoadContainerOperation::LoadContainerOperation(): ActuatorsOperation() {
    this->volume = std::shared_ptr<MathematicOperable>();
	this->idSource = -1;
    this->volumeUnits = units::l;
}

LoadContainerOperation::LoadContainerOperation(const LoadContainerOperation& obj) : ActuatorsOperation(obj) {
    this->volume = obj.volume;
	this->idSource = obj.idSource;
    this->volumeUnits = obj.volumeUnits;
}

LoadContainerOperation::LoadContainerOperation(
        int idConatiner,
		int idSource,
        std::shared_ptr<MathematicOperable> value,
        units::Volume volumeUnits) :
    ActuatorsOperation(idConatiner)
{
    this->volume = value;
	this->idSource = idSource;
    this->volumeUnits = volumeUnits;
}

LoadContainerOperation::~LoadContainerOperation() {
}

std::string LoadContainerOperation::toText() {
    return std::to_string(containerID) + "[label=\"loadContainer("
            + std::to_string(idSource) + ", " + volume.get()->toString()
			+ ")\"];";
}

void LoadContainerOperation::execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument)  {
    actuatorsInterface->loadContainer(this->idSource, volume.get()->getValue() * volumeUnits);
}
