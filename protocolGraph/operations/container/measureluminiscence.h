#ifndef MEASURELUMINISCENCE_H
#define MEASURELUMINISCENCE_H

//units
#include <utils/units.h>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operables/mathematics/VariableEntry.h"
#include "protocolGraph/operations/container/finishableoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class MeasureLuminiscence : public FinishableOperation
{
public:
    // Node methods
    MeasureLuminiscence();
    MeasureLuminiscence(const MeasureLuminiscence & node);

    virtual std::string toText();
    //

    MeasureLuminiscence(int containerId,
              const std::string & sourceId,
              std::shared_ptr<VariableEntry> receiver,
              std::shared_ptr<MathematicOperable> measurmentFrequency,
              units::Frequency measurmentFrequencyUnits);
    virtual ~MeasureLuminiscence();

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void simulate(ActuatorsSimulationInterface* simulateInterface) throw(std::invalid_argument);

    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void finish(ActuatorsSimulationInterface* simulateInterface) throw(std::invalid_argument);

protected:
    std::string sourceId;
    std::shared_ptr<VariableEntry> receiver;

    std::shared_ptr<MathematicOperable> measurmentFrequency;
    units::Frequency measurmentFrequencyUnits;
};

#endif // MEASURELUMINISCENCE_H
