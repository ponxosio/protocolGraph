#include "measuretemperature.h"

MeasureTemperature::MeasureTemperature() :
    FinishableOperation()
{
    this->sourceId = -1;
    this->receiver = std::shared_ptr<VariableEntry>();

    this->measurmentFrequency = std::shared_ptr<MathematicOperable>();
    this->measurmentFrequencyUnits = units::Hz;
}

MeasureTemperature::MeasureTemperature(const MeasureTemperature& node) :
    FinishableOperation(node)
{
    this->sourceId = node.sourceId;
    this->receiver = node.receiver;

    this->measurmentFrequency = node.measurmentFrequency;
    this->measurmentFrequencyUnits = node.measurmentFrequencyUnits;
}

MeasureTemperature::MeasureTemperature(
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

MeasureTemperature::~MeasureTemperature() {}

void MeasureTemperature::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->startMeasureTemperature(sourceId, measurmentFrequency->getValue() * measurmentFrequencyUnits);
}

void MeasureTemperature::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    units::Temperature value = actuatorInterface->getMeasureTemperature(sourceId);
    receiver->setValue(Utils::toDefaultUnits(value));
}

std::string MeasureTemperature::toText() {
    return std::to_string(containerID) + "[label=\""
        + (receiver ? receiver->toString() : "?")
        + " = measureTemperature(" + sourceId + ")\"];";
}
