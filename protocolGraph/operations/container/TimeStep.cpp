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
    units::Time time = actuatorsInterface->timeStep();
    receiver.get()->setValue(receiver.get()->getValue() + time.to(units::s));
}
