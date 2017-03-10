#include "settimestep.h"

// Node methods
SetTimeStep::SetTimeStep() :
    ActuatorsOperation()
{
    this->timeSlice = std::shared_ptr<MathematicOperable>();
    this->timeSliceUnits = units::s;
}

SetTimeStep::SetTimeStep(const SetTimeStep & node) :
    ActuatorsOperation(node)
{
    this->timeSlice = node.timeSlice;
    this->timeSliceUnits = node.timeSliceUnits;
}

SetTimeStep::SetTimeStep(int containerId, std::shared_ptr<MathematicOperable> timeSlice, units::Time timeSliceUnits) :
    ActuatorsOperation(containerId)
{
    this->timeSlice = timeSlice;
    this->timeSliceUnits = timeSliceUnits;
}

SetTimeStep::~SetTimeStep() {

}

std::string SetTimeStep::toText() {
    return std::to_string(containerID) + "[label=\"SetTimeStep(" + (timeSlice ? std::to_string(timeSlice->getValue()) : "null") + ")\"]";
}

void SetTimeStep::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->setTimeStep(timeSlice->getValue() * timeSliceUnits);
}
