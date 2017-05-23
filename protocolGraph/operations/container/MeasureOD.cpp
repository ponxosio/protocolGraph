/*
 * MeasureOD.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#include "MeasureOD.h"

MeasureOD::MeasureOD() : 
    FinishableOperation()
{
	this->sourceId = -1;
	this->receiver = std::shared_ptr<VariableEntry>();

    this->measurmentFrequency = std::shared_ptr<MathematicOperable>();
    this->measurmentFrequencyUnits = units::Hz;

    this->wavelength = std::shared_ptr<MathematicOperable>();
    this->wavelengthUnits = units::nm;
}

MeasureOD::MeasureOD(const MeasureOD& node) : 
    FinishableOperation(node)
{
	this->sourceId = node.sourceId;
	this->receiver = node.receiver;

    this->measurmentFrequency = node.measurmentFrequency;
    this->measurmentFrequencyUnits = node.measurmentFrequencyUnits;

    this->wavelength = node.wavelength;
    this->wavelengthUnits = node.wavelengthUnits;
}

MeasureOD::MeasureOD(
        int containerId,
        const std::string & sourceId,
        std::shared_ptr<VariableEntry> receiver,
        std::shared_ptr<MathematicOperable> measurmentFrequency,
        units::Frequency measurmentFrequencyUnits,
        std::shared_ptr<MathematicOperable> wavelength,
        units::Length wavelengthUnits) :
    FinishableOperation(containerId)
{
	this->sourceId = sourceId;
	this->receiver = receiver;

    this->measurmentFrequency = measurmentFrequency;
    this->measurmentFrequencyUnits = measurmentFrequencyUnits;

    this->wavelength = wavelength;
    this->wavelengthUnits = wavelengthUnits;
}

MeasureOD::~MeasureOD() {}

void MeasureOD::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->startMeasureOD(sourceId,
                                      measurmentFrequency->getValue() * measurmentFrequencyUnits,
                                      wavelength->getValue() * wavelengthUnits);
}

void MeasureOD::simulate(ActuatorsSimulationInterface* simulateInterface) throw(std::invalid_argument) {
    simulateInterface->startMeasureOD(sourceId,
                                      measurmentFrequency, measurmentFrequencyUnits,
                                      wavelength, wavelengthUnits);
}

void MeasureOD::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    receiver.get()->setValue(actuatorInterface->getMeasureOD(sourceId));
}

void MeasureOD::finish(ActuatorsSimulationInterface* simulateInterface) throw(std::invalid_argument) {
    receiver.get()->setValue(simulateInterface->getMeasureOD(sourceId));
}

std::string MeasureOD::toText() {
    return std::to_string(containerID) + "[label=\""
        + (receiver ? receiver->toString() : "?")
        + " = measureOD(" + sourceId + ")\"];";
}
