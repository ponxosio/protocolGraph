#include "measureluminiscence.h"

MeasureLuminiscence::MeasureLuminiscence() :
    FinishableOperation()
{
    this->sourceId = -1;
    this->receiver = std::shared_ptr<VariableEntry>();

    this->measurmentFrequency = std::shared_ptr<MathematicOperable>();
    this->measurmentFrequencyUnits = units::Hz;
}

MeasureLuminiscence::MeasureLuminiscence(const MeasureLuminiscence& node) :
    FinishableOperation(node)
{
    this->sourceId = node.sourceId;
    this->receiver = node.receiver;

    this->measurmentFrequency = node.measurmentFrequency;
    this->measurmentFrequencyUnits = node.measurmentFrequencyUnits;
}

MeasureLuminiscence::MeasureLuminiscence(
        int containerId,
        const std::string & sourceId,
        std::shared_ptr<VariableEntry> receiver,
        std::shared_ptr<MathematicOperable> measurmentFrequency,
        units::Frequency measurmentFrequencyUnits) :
    FinishableOperation(containerId)
{
    this->sourceId = sourceId;
    this->receiver = receiver;

    this->measurmentFrequency = measurmentFrequency;
    this->measurmentFrequencyUnits = measurmentFrequencyUnits;
}

MeasureLuminiscence::~MeasureLuminiscence() {}

void MeasureLuminiscence::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->startMeasureLuminiscense(sourceId, measurmentFrequency->getValue() * measurmentFrequencyUnits);
}

void MeasureLuminiscence::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    receiver->setValue(actuatorInterface->getMeasureFluorescence(sourceId).to(units::cd));
}

std::string MeasureLuminiscence::toText() {
    return std::to_string(containerID) + "[label=\""
        + receiver.get()->toString() + " = measureLuminiscence("
        + sourceId + ")\"];";
}
