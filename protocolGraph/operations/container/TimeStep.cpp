/*
 * TimeStep.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#include "TimeStep.h"

TimeStep::TimeStep() :
		ActuatorsOperation() {
	this->receiver = std::shared_ptr<VariableEntry>();
}

TimeStep::TimeStep(const TimeStep& node) :
		ActuatorsOperation(node) {
	this->receiver = node.receiver;
}

TimeStep::TimeStep(int containerId, std::shared_ptr<VariableEntry> receiver) :
		ActuatorsOperation(containerId) {
	this->receiver = receiver;
}

TimeStep::~TimeStep() {
}

std::string TimeStep::toText() {
    return std::to_string(containerID) + "[label=\"TimeStep()\"];";
}

void TimeStep::execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument)  {
    units::Time time = Utils::toDefaultUnits(actuatorsInterface->timeStep());
    double newTimeValue = Utils::pround(receiver->getValue() + time(), 5); //set precision to 5 decimals, avoid floating point representation erros in the time variable.
    receiver->setValue(newTimeValue);
}

void TimeStep::simulate(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument)  {
    units::Time time = Utils::toDefaultUnits(simulationInterface->timeStep());
    double newTimeValue = Utils::pround(receiver->getValue() + time(), 5); //set precision to 5 decimals, avoid floating point representation erros in the time variable.
    receiver->setValue(newTimeValue);
}
