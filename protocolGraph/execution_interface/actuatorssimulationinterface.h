#ifndef ACTUATORSSIMULATIONINTERFACE_H
#define ACTUATORSSIMULATIONINTERFACE_H

#include <memory>
#include <string>
#include <vector>

//local
#include <utils/units.h>
#include <utils/electrophoresisresult.h>

#include"protocolGraph/operables/mathematics/MathematicOperable.h"

class ActuatorsSimulationInterface {
public:
    virtual ~ActuatorsSimulationInterface(){}

    virtual void applyLigth(const std::string & sourceId,
                            std::shared_ptr<MathematicOperable> wavelength,
                            units::Length wavelengthUnits,
                            std::shared_ptr<MathematicOperable> intensity,
                            units::LuminousIntensity intensityUnits) = 0;
    virtual void stopApplyLigth(const std::string & sourceId) = 0;

    virtual void applyTemperature(const std::string & sourceId,
                                  std::shared_ptr<MathematicOperable> temperature,
                                  units::Temperature temperatureUnits) = 0;
    virtual void stopApplyTemperature(const std::string & sourceId) = 0;

    virtual void stir(const std::string & idSource,
                      std::shared_ptr<MathematicOperable> intensity,
                      units::Frequency intensityUnits) = 0;
    virtual void stopStir(const std::string & idSource) = 0;

    virtual void centrifugate(const std::string & idSource,
                              std::shared_ptr<MathematicOperable> intensity,
                              units::Frequency intensityUnits) = 0;
    virtual void stopCentrifugate(const std::string & idSource) = 0;

    virtual void shake(const std::string & idSource,
                       std::shared_ptr<MathematicOperable> intensity,
                       units::Frequency intensityUnits) = 0;
    virtual void stopShake(const std::string & idSource) = 0;

    virtual void startElectrophoresis(const std::string & idSource,
                                      std::shared_ptr<MathematicOperable> fieldStrenght,
                                      units::ElectricField fieldStrenghtUnits) = 0;
    virtual std::shared_ptr<ElectrophoresisResult> stopElectrophoresis(const std::string & idSource) = 0;

    virtual units::Volume getVirtualVolume(const std::string & sourceId) = 0;
    virtual void loadContainer(const std::string & sourceId, units::Volume initialVolumeUnits) = 0;

    virtual void startMeasureOD(const std::string & sourceId,
                                std::shared_ptr<MathematicOperable> measurementFrequency,
                                units::Frequency measurementFrequencyUnits,
                                std::shared_ptr<MathematicOperable> wavelegthn,
                                units::Length wavelengthUnits) = 0;
    virtual double getMeasureOD(const std::string & sourceId) = 0;

    virtual void startMeasureTemperature(const std::string & sourceId,
                                         std::shared_ptr<MathematicOperable> measurementFrequency,
                                         units::Frequency measurementFrequencyUnits) = 0;
    virtual units::Temperature getMeasureTemperature(const std::string & sourceId) = 0;

    virtual void startMeasureLuminiscense(const std::string & sourceId,
                                          std::shared_ptr<MathematicOperable> measurementFrenquency,
                                          units::Frequency measurementFrequencyUnits) = 0;
    virtual units::LuminousIntensity getMeasureLuminiscense(const std::string & sourceId) = 0;

    virtual void startMeasureVolume(const std::string & sourceId,
                                    std::shared_ptr<MathematicOperable> measurementFrequency,
                                    units::Frequency measurementFrequencyUnits) = 0;
    virtual units::Volume getMeasureVolume(const std::string & sourceId) = 0;

    virtual void startMeasureFluorescence(const std::string & sourceId,
                                          std::shared_ptr<MathematicOperable> measurementFrequency,
                                          units::Frequency measurementFrequencyUnits,
                                          std::shared_ptr<MathematicOperable> excitation,
                                          units::Length excitationUnits,
                                          std::shared_ptr<MathematicOperable> emission,
                                          units::Length emissionUnits) = 0;
    virtual units::LuminousIntensity getMeasureFluorescence(const std::string & sourceId) = 0;

    virtual void setContinuosFlow(const std::string & idSource,
                                  const std::string & idTarget,
                                  std::shared_ptr<MathematicOperable> rate,
                                  units::Volumetric_Flow rateUnits) = 0;
    virtual void stopContinuosFlow(const std::string & idSource, const std::string & idTarget) = 0;

    virtual units::Time transfer(const std::string & idSource,
                                 const std::string & idTarget,
                                 std::shared_ptr<MathematicOperable> volume,
                                 units::Volume volumeUnits) = 0;
    virtual void stopTransfer(const std::string & idSource, const std::string & idTarget) = 0;

    virtual units::Time mix(const std::string & idSource1,
                            const std::string & idSource2,
                            const std::string & idTarget,
                            std::shared_ptr<MathematicOperable> volume1,
                            units::Volume volume1Units,
                            std::shared_ptr<MathematicOperable> volume2,
                            units::Volume volume2Units) = 0;

    virtual void stopMix(const std::string & idSource1,
                         const std::string & idSource2,
                         const std::string & idTarget) = 0;

    virtual void setTimeStep(units::Time time) = 0;
    virtual units::Time timeStep() = 0;
};

#endif // ACTUATORSSIMULATIONINTERFACE_H
