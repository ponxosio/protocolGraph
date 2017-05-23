#ifndef MEASUREFLUORESCENCE_H
#define MEASUREFLUORESCENCE_H

//units
#include <utils/units.h>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operables/mathematics/VariableEntry.h"
#include "protocolGraph/operations/container/finishableoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class MeasureFluorescence : public FinishableOperation
{
public:
    // Node methods
    MeasureFluorescence();
    MeasureFluorescence(const MeasureFluorescence & node);

    virtual std::string toText();
    //

    MeasureFluorescence(int containerId,
                        const std::string & sourceId,
                        std::shared_ptr<VariableEntry> receiver,
                        std::shared_ptr<MathematicOperable> measurmentFrequency,
                        units::Frequency measurmentFrequencyUnits,
                        std::shared_ptr<MathematicOperable> excitation,
                        units::Length excitationUnits,
                        std::shared_ptr<MathematicOperable> emission,
                        units::Length emissionUnits);
    virtual ~MeasureFluorescence();

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void simulate(ActuatorsSimulationInterface* simulatorInterface) throw(std::invalid_argument);

    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void finish(ActuatorsSimulationInterface* simulatorInterface) throw(std::invalid_argument);

protected:
    std::string sourceId;
    std::shared_ptr<VariableEntry> receiver;

    std::shared_ptr<MathematicOperable> measurmentFrequency;
    std::shared_ptr<MathematicOperable> excitation;
    std::shared_ptr<MathematicOperable> emission;

    units::Frequency measurmentFrequencyUnits;
    units::Length excitationUnits;
    units::Length emissionUnits;
};

#endif // MEASUREFLUORESCENCE_H
