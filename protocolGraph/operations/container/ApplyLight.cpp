/*
 * ApplyLight.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#include "ApplyLight.h"

ApplyLight::ApplyLight() : ActuatorsOperation() {
	this->sourceId = -1;
	this->wavelength = std::shared_ptr<MathematicOperable>();
	this->intensity = std::shared_ptr<MathematicOperable>();
    this->wavelengthUnits = units::nm;
    this->intensityUnits = units::cd;
}

ApplyLight::ApplyLight(const ApplyLight& node) : ActuatorsOperation(node) {
	this->sourceId = node.sourceId;
	this->wavelength = node.wavelength;
	this->intensity = node.intensity;
    this->wavelengthUnits = node.wavelengthUnits;
    this->intensityUnits = node.intensityUnits;
}

std::string ApplyLight::toText() {
    return std::to_string(containerID) + "[label=\"applyLigth("
            + sourceId + ", " + wavelength.get()->toString()
			+ ", " + intensity.get()->toString() + ")\"];";
}

ApplyLight::ApplyLight(
        int idContainer,
        const std::string & sourceID,
        std::shared_ptr<MathematicOperable> wavelength,
        units::Length wavelengthUnits,
        std::shared_ptr<MathematicOperable> intensity,
        units::LuminousIntensity intensityUnits) :
    ActuatorsOperation(idContainer)
{
	this->sourceId = sourceID;
	this->wavelength = wavelength;
	this->intensity = intensity;
    this->wavelengthUnits = wavelengthUnits;
    this->intensityUnits = intensityUnits;
}

ApplyLight::~ApplyLight() {

}

void ApplyLight::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument)  {
    actuatorInterface->applyLigth(sourceId, wavelength.get()->getValue() * wavelengthUnits, intensity.get()->getValue() * intensityUnits);
}
