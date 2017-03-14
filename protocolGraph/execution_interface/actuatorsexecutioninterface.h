#ifndef ACTUATORSEXECUTIONINTERFACE_H
#define ACTUATORSEXECUTIONINTERFACE_H

#include <utils/units.h>

class ActuatorsExecutionInterface
{
public:
    virtual void applyLigth(int sourceId, units::Length wavelength, units::LuminousIntensity intensity) = 0;
    virtual void applyTemperature(int sourceId, units::Temperature temperature) = 0;
    virtual void stir(int idSource, units::Frequency intensity) = 0;

    virtual units::Volume getVirtualVolume(int sourceId) = 0;
    virtual void loadContainer(int sourceId, units::Volume initialVolume) = 0;

    virtual double measureOD(int sourceId, units::Time duration, units::Frequency measurementFrequency, units::Length wavelength) = 0;
    virtual units::Temperature measureTemperature(int sourceId, units::Time duration, units::Frequency measurementFrequency) = 0;
    virtual units::LuminousIntensity measureLuminiscense(int sourceId, units::Time duration, units::Frequency measurementFrequency) = 0;
    virtual units::Volume measureVolume(int sourceId, units::Time duration, units::Frequency measurementFrequency) = 0;
    virtual units::LuminousIntensity measureFluorescence(int sourceId, units::Time duration, units::Frequency measurementFrequency) = 0;

    virtual void mix(int idSource1, int idSource2, int idTarget, units::Volume volume1, units::Volume volume2) = 0;
    virtual void setContinuosFlow(int idSource, int idTarget, units::Volumetric_Flow rate) = 0;
    virtual void transfer(int idSource, int idTarget, units::Volume volume) = 0;

    virtual void setTimeStep(units::Time time) = 0;
    virtual units::Time timeStep() = 0;
};

#endif // ACTUATORSEXECUTIONINTERFACE_H
