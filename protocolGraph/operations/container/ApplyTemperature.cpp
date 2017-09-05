/*
 * ApplyTemperature.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#include "ApplyTemperature.h"

ApplyTemperature::ApplyTemperature() : FinishableOperation() {
	this->sourceId = -1;
	this->temperature = std::shared_ptr<MathematicOperable>();
    this->temperatureUnits = units::C;
}

ApplyTemperature::ApplyTemperature(const ApplyTemperature& node) : FinishableOperation(node) {
	this->sourceId = node.sourceId;
	this->temperature = node.temperature;
    this->temperatureUnits = node.temperatureUnits;
}

ApplyTemperature::ApplyTemperature(
        int containerId,
        const std::string & sourceId,
        std::shared_ptr<MathematicOperable> temperature,
        units::Temperature temperatureUnits) :
    FinishableOperation(containerId)
{
	this->sourceId = sourceId;
    this->temperature = temperature;
    this->temperatureUnits = temperatureUnits;
}

ApplyTemperature::~ApplyTemperature() {}

std::string ApplyTemperature::toText() {
    return std::to_string(containerID) + "[label=\"applyTemperature("
            + sourceId + ", "
            + (temperature ? temperature->toString() : "?")
            + ")\"];";
}

void ApplyTemperature::execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument)  {
    actuatorsInterface->applyTemperature(sourceId, temperature.get()->getValue() * temperatureUnits);
}

void ApplyTemperature::simulate(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument)  {
    simulationInterface->applyTemperature(sourceId, temperature, temperatureUnits);
}

void ApplyTemperature::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->stopApplyTemperature(sourceId);
}

void ApplyTemperature::finish(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument) {
    simulationInterface->stopApplyTemperature(sourceId);
}
