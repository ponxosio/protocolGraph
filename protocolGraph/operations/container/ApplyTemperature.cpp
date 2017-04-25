/*
 * ApplyTemperature.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#include "ApplyTemperature.h"

ApplyTemperature::ApplyTemperature() : ActuatorsOperation() {
	this->sourceId = -1;
	this->temperature = std::shared_ptr<MathematicOperable>();
    this->temperatureUnits = units::K;
}

ApplyTemperature::ApplyTemperature(const ApplyTemperature& node) : ActuatorsOperation(node) {
	this->sourceId = node.sourceId;
	this->temperature = node.temperature;
    this->temperatureUnits = node.temperatureUnits;
}

std::string ApplyTemperature::toText() {
    return std::to_string(containerID) + "[label=\"applyTemperature("
            + sourceId + ", " + temperature.get()->toString()
			+ ")\"];";
}

ApplyTemperature::ApplyTemperature(
        int containerId,
        const std::string & sourceId,
        std::shared_ptr<MathematicOperable> temperature,
        units::Temperature temperatureUnits) :
    ActuatorsOperation(containerId)
{
	this->sourceId = sourceId;
    this->temperature = temperature;
    this->temperatureUnits = temperatureUnits;
}

ApplyTemperature::~ApplyTemperature() {}

void ApplyTemperature::execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument)  {
    actuatorsInterface->applyTemperature(sourceId, temperature.get()->getValue() * temperatureUnits);
}
