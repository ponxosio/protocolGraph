/*
 * Stir.cpp
 *
 *  Created on: 4 de may. de 2016
 *      Author: angel
 */

#include "Stir.h"

Stir::Stir() : ActuatorsOperation() {
	this->sourceId = -1;
	this->intensity = std::shared_ptr<MathematicOperable>();
    this->intensityUnits = units::Hz;
}

Stir::Stir(const Stir& node) :
		ActuatorsOperation(node) {
	this->sourceId = node.sourceId;
	this->intensity = node.intensity;
    this->intensityUnits = node.intensityUnits;
}

Stir::Stir(
        int containerId,
        const std::string & sourceId,
        std::shared_ptr<MathematicOperable> intensity,
        units::Frequency intensityUnits) :
    ActuatorsOperation(containerId)
{
	this->sourceId = sourceId;
	this->intensity = intensity;
    this->intensityUnits = intensityUnits;
}

Stir::~Stir() {}

std::string Stir::toText() {
    return std::to_string(containerID) + "[label=\"applyTemperature("
            + sourceId + ", " + intensity.get()->toString()
			+ ")\"];";
}

void Stir::execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument) {
    actuatorsInterface->stir(sourceId, intensity.get()->getValue() * intensityUnits);
}
