#ifndef ACTUATORSEXECUTIONINTERFACE_H
#define ACTUATORSEXECUTIONINTERFACE_H

#include <string>

#include <utils/units.h>

class ActuatorsExecutionInterface
{
public:
    virtual void applyLigth(const std::string & sourceId, units::Length wavelength, units::LuminousIntensity intensity) = 0;
    virtual void applyTemperature(const std::string & sourceId, units::Temperature temperature) = 0;
    virtual void stir(const std::string & idSource, units::Frequency intensity) = 0;

    virtual units::Volume getVirtualVolume(const std::string & sourceId) = 0;
    virtual void loadContainer(const std::string & sourceId, units::Volume initialVolume) = 0;

    virtual double measureOD(const std::string & sourceId, units::Time duration, units::Frequency measurementFrequency, units::Length wavelength) = 0;
    virtual units::Temperature measureTemperature(const std::string & sourceId, units::Time duration, units::Frequency measurementFrequency) = 0;
    virtual units::LuminousIntensity measureLuminiscense(const std::string & sourceId, units::Time duration, units::Frequency measurementFrequency) = 0;
    virtual units::Volume measureVolume(const std::string & sourceId, units::Time duration, units::Frequency measurementFrequency) = 0;
    virtual units::LuminousIntensity measureFluorescence(const std::string & sourceId, units::Time duration, units::Frequency measurementFrequency) = 0;

    virtual void mix(const std::string & idSource1,
                     const std::string & idSource2,
                     const std::string & idTarget,
                     units::Volume volume1,
                     units::Volume volume2) = 0;
    virtual void setContinuosFlow(const std::string & idSource, const std::string & idTarget, units::Volumetric_Flow rate) = 0;
    virtual void stopContinuosFlow(const std::string & idSource, const std::string & idTarget) = 0;
    virtual void transfer(const std::string & idSource, const std::string & idTarget, units::Volume volume) = 0;

    virtual void setTimeStep(units::Time time) = 0;
    virtual units::Time timeStep() = 0;
};

#endif // ACTUATORSEXECUTIONINTERFACE_H
