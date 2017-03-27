/*
 * MeasureOD.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#include "MeasureOD.h"

MeasureOD::MeasureOD() : 
	ActuatorsOperation() 
{
	this->sourceId = -1;
	this->receiver = std::shared_ptr<VariableEntry>();

    this->duration = std::shared_ptr<MathematicOperable>();
    this->durationUnits = units::s;

    this->measurmentFrequency = std::shared_ptr<MathematicOperable>();
    this->measurmentFrequencyUnits = units::Hz;

    this->wavelength = std::shared_ptr<MathematicOperable>();
    this->wavelengthUnits = units::nm;
}

MeasureOD::MeasureOD(const MeasureOD& node) : 
	ActuatorsOperation(node) 
{
	this->sourceId = node.sourceId;
	this->receiver = node.receiver;

    this->duration = node.duration;
    this->durationUnits = node.durationUnits;

    this->measurmentFrequency = node.measurmentFrequency;
    this->measurmentFrequencyUnits = node.measurmentFrequencyUnits;

    this->wavelength = node.wavelength;
    this->wavelengthUnits = node.wavelengthUnits;
}

MeasureOD::MeasureOD(
        int containerId,
        int sourceId,
        std::shared_ptr<VariableEntry> receiver,
        std::shared_ptr<MathematicOperable> duration,
        units::Time durationUnits,
        std::shared_ptr<MathematicOperable> measurmentFrequency,
        units::Frequency measurmentFrequencyUnits,
        std::shared_ptr<MathematicOperable> wavelength,
        units::Length wavelengthUnits) :
	ActuatorsOperation(containerId) 
{
	this->sourceId = sourceId;
	this->receiver = receiver;

    this->duration = duration;
    this->durationUnits = durationUnits;

    this->measurmentFrequency = measurmentFrequency;
    this->measurmentFrequencyUnits = measurmentFrequencyUnits;

    this->wavelength = wavelength;
    this->wavelengthUnits = wavelengthUnits;
}

MeasureOD::~MeasureOD() {}

void MeasureOD::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    receiver.get()->setValue(actuatorInterface->measureOD(sourceId,
                                                          duration->getValue() * durationUnits,
                                                          measurmentFrequency->getValue() * measurmentFrequencyUnits,
                                                          wavelength->getValue() * wavelengthUnits));
}

std::string MeasureOD::toText() {
    return std::to_string(containerID) + "[label=\""
		+ receiver.get()->toString() + " = measureOD("
        + std::to_string(sourceId) + ")\"];";
}
