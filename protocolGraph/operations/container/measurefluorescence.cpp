#include "measurefluorescence.h"

MeasureFluorescence::MeasureFluorescence() :
    FinishableOperation()
{
    this->sourceId = "";
    this->receiver = NULL;
    this->measurmentFrequency = NULL;
    this->measurmentFrequencyUnits = units::Hz;

    this->excitation = NULL;
    this->excitationUnits = units::m;

    this->emission = NULL;
    this->emissionUnits = units::m;
}

MeasureFluorescence::MeasureFluorescence(const MeasureFluorescence & node) :
    FinishableOperation(node), sourceId(node.sourceId)
{
    this->receiver = node.receiver;
    this->measurmentFrequency = node.measurmentFrequency;
    this->measurmentFrequencyUnits = node.measurmentFrequencyUnits;

    this->excitation = node.excitation;
    this->excitationUnits = node.excitationUnits;

    this->emission = node.emission;
    this->emissionUnits = node.emissionUnits;
}

MeasureFluorescence::MeasureFluorescence(
        int containerId,
        const std::string & sourceId,
        std::shared_ptr<VariableEntry> receiver,
        std::shared_ptr<MathematicOperable> measurmentFrequency,
        units::Frequency measurmentFrequencyUnits,
        std::shared_ptr<MathematicOperable> excitation,
        units::Length execitationUnits,
        std::shared_ptr<MathematicOperable> emission,
        units::Length emissionUnits) :
    FinishableOperation(containerId), sourceId(sourceId)
{
    this->receiver = receiver;
    this->measurmentFrequency = measurmentFrequency;
    this->measurmentFrequencyUnits = measurmentFrequencyUnits;

    this->excitation = excitation;
    this->excitationUnits = execitationUnits;

    this->emission = emission;
    this->emissionUnits = emissionUnits;
}

MeasureFluorescence::~MeasureFluorescence() {

}

std::string MeasureFluorescence::toText() {
    return std::to_string(containerID) + "[label=\""
        + receiver.get()->toString() + " = measureFluorescence("
        + sourceId + ")\"];";
}

void MeasureFluorescence::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->startMeasureFluorescence(sourceId,
                                                measurmentFrequency->getValue() * measurmentFrequencyUnits,
                                                excitation->getValue() * excitationUnits,
                                                emission->getValue() * emissionUnits);
}

void MeasureFluorescence::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    receiver->setValue(actuatorInterface->getMeasureFluorescence(sourceId).to(units::cd));
}
