#ifndef MEASUREVOLUME_H
#define MEASUREVOLUME_H

//units
#include <utils/units.h>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operables/mathematics/VariableEntry.h"
#include "protocolGraph/operations/container/finishableoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class MeasureVolume : public FinishableOperation
{
public:
    // Node methods
    MeasureVolume();
    MeasureVolume(const MeasureVolume & node);

    virtual std::string toText();
    //

    MeasureVolume(int containerId,
              const std::string & sourceId,
              std::shared_ptr<VariableEntry> receiver,
              std::shared_ptr<MathematicOperable> measurmentFrequency,
              units::Frequency measurmentFrequencyUnits);
    virtual ~MeasureVolume();

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void simulate(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument);

    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void finish(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument);

protected:
    std::string sourceId;
    std::shared_ptr<VariableEntry> receiver;

    std::shared_ptr<MathematicOperable> measurmentFrequency;
    units::Frequency measurmentFrequencyUnits;
};

#endif // MEASUREVOLUME_H
