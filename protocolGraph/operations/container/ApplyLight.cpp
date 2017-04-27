/*
 * ApplyLight.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#include "ApplyLight.h"

ApplyLight::ApplyLight() : FinishableOperation() {
	this->sourceId = -1;
	this->wavelength = std::shared_ptr<MathematicOperable>();
	this->intensity = std::shared_ptr<MathematicOperable>();
    this->wavelengthUnits = units::nm;
    this->intensityUnits = units::cd;
}

ApplyLight::ApplyLight(const ApplyLight& node) : FinishableOperation(node) {
	this->sourceId = node.sourceId;
	this->wavelength = node.wavelength;
	this->intensity = node.intensity;
    this->wavelengthUnits = node.wavelengthUnits;
    this->intensityUnits = node.intensityUnits;
}

ApplyLight::ApplyLight(
        int idContainer,
        const std::string & sourceID,
        std::shared_ptr<MathematicOperable> wavelength,
        units::Length wavelengthUnits,
        std::shared_ptr<MathematicOperable> intensity,
        units::LuminousIntensity intensityUnits) :
    FinishableOperation(idContainer)
{
	this->sourceId = sourceID;
	this->wavelength = wavelength;
	this->intensity = intensity;
    this->wavelengthUnits = wavelengthUnits;
    this->intensityUnits = intensityUnits;
}

ApplyLight::~ApplyLight() {

}

std::string ApplyLight::toText() {
    return std::to_string(containerID) + "[label=\"applyLigth("
            + sourceId + ", " + wavelength.get()->toString()
            + ", " + intensity.get()->toString() + ")\"];";
}

void ApplyLight::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument)  {
    actuatorInterface->applyLigth(sourceId, wavelength.get()->getValue() * wavelengthUnits, intensity.get()->getValue() * intensityUnits);
}

void ApplyLight::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->stopApplyLigth(sourceId);
}
