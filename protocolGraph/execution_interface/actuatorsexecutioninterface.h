#ifndef ACTUATORSEXECUTIONINTERFACE_H
#define ACTUATORSEXECUTIONINTERFACE_H

#include <string>
#include <vector>

//local

#include <utils/units.h>

#include "protocolGraph/execution_interface/electrophoresisresult.h"

class ActuatorsExecutionInterface
{
public:
    virtual void applyLigth(const std::string & sourceId, units::Length wavelength, units::LuminousIntensity intensity) = 0;
    virtual void stopApplyLigth(const std::string & sourceId) = 0;

    virtual void applyTemperature(const std::string & sourceId, units::Temperature temperature) = 0;
    virtual void stopApplyTemperature(const std::string & sourceId) = 0;

    virtual void stir(const std::string & idSource, units::Frequency intensity) = 0;
    virtual void stopStir(const std::string & idSource) = 0;

    virtual void centrifugate(const std::string & idSource, units::Frequency intensity) = 0;
    virtual void stopCentrifugate(const std::string & idSource) = 0;

    virtual void shake(const std::string & idSource, units::Frequency intensity) = 0;
    virtual void stopShake(const std::string & idSource) = 0;

    virtual void startElectrophoresis(const std::string & idSource, units::ElectricField fieldStrenght) = 0;
    virtual ElectrophoresisResult stopElectrophoresis(const std::string & idSource) = 0;

    virtual units::Volume getVirtualVolume(const std::string & sourceId) = 0;
    virtual void loadContainer(const std::string & sourceId, units::Volume initialVolume) = 0;

    virtual void startMeasureOD(const std::string & sourceId, units::Frequency measurementFrequency, units::Length wavelength) = 0;
    virtual double getMeasureOD(const std::string & sourceId) = 0;

    virtual void startMeasureTemperature(const std::string & sourceId, units::Frequency measurementFrequency) = 0;
    virtual units::Temperature getMeasureTemperature(const std::string & sourceId) = 0;

    virtual void startMeasureLuminiscense(const std::string & sourceId, units::Frequency measurementFrequency) = 0;
    virtual units::LuminousIntensity getMeasureLuminiscense(const std::string & sourceId) = 0;

    virtual void startMeasureVolume(const std::string & sourceId, units::Frequency measurementFrequency) = 0;
    virtual units::Volume getMeasureVolume(const std::string & sourceId) = 0;

    virtual void startMeasureFluorescence(const std::string & sourceId,
                                          units::Frequency measurementFrequency,
                                          units::Length excitation,
                                          units::Length emission) = 0;
    virtual units::LuminousIntensity getMeasureFluorescence(const std::string & sourceId) = 0;

    virtual void setContinuosFlow(const std::string & idSource, const std::string & idTarget, units::Volumetric_Flow rate) = 0;
    virtual void stopContinuosFlow(const std::string & idSource, const std::string & idTarget) = 0;

    virtual units::Time transfer(const std::string & idSource, const std::string & idTarget, units::Volume volume) = 0;
    virtual units::Time mix(const std::string & idSource1,
                            const std::string & idSource2,
                            const std::string & idTarget,
                            units::Volume volume1,
                            units::Volume volume2) = 0;

    virtual void setTimeStep(units::Time time) = 0;
    virtual units::Time timeStep() = 0;
};

#endif // ACTUATORSEXECUTIONINTERFACE_H
