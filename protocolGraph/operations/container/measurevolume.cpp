#include "measurevolume.h"

MeasureVolume::MeasureVolume() :
    FinishableOperation()
{
    this->sourceId = -1;
    this->receiver = std::shared_ptr<VariableEntry>();

    this->measurmentFrequency = std::shared_ptr<MathematicOperable>();
    this->measurmentFrequencyUnits = units::Hz;
}

MeasureVolume::MeasureVolume(const MeasureVolume& node) :
    FinishableOperation(node)
{
    this->sourceId = node.sourceId;
    this->receiver = node.receiver;

    this->measurmentFrequency = node.measurmentFrequency;
    this->measurmentFrequencyUnits = node.measurmentFrequencyUnits;
}

MeasureVolume::MeasureVolume(
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

MeasureVolume::~MeasureVolume() {}

void MeasureVolume::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->startMeasureVolume(sourceId, measurmentFrequency->getValue() * measurmentFrequencyUnits);
}

void MeasureVolume::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    units::Volume value = actuatorInterface->getMeasureVolume(sourceId);
    receiver->setValue(Utils::toDefaultUnits(value));
}

std::string MeasureVolume::toText() {
    return std::to_string(containerID) + "[label=\""
        + (receiver ? receiver->toString() : "?")
        + " = measureVolume("
        + sourceId + ")\"];";
}
