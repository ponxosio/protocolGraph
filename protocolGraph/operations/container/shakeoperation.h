#ifndef SHAKEOPERATION_H
#define SHAKEOPERATION_H

//local
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/container/finishableoperation.h"

//units
#include <utils/units.h>

#include "protocolGraph/protocolgraph_global.h"

class ShakeOperation : public FinishableOperation
{
public:
    // Node methods
    ShakeOperation();
    ShakeOperation(const ShakeOperation & node);

    virtual std::string toText();
    //

    ShakeOperation(int idContainer,
                   const std::string & sourceID,
                   std::shared_ptr<MathematicOperable> shakeValue,
                   units::Frequency shakeUnits);

    virtual ~ShakeOperation();

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void simulate(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument);

    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void finish(ActuatorsSimulationInterface* simulateInterface) throw(std::invalid_argument);

protected:
    std::string sourceID;
    std::shared_ptr<MathematicOperable> shakeValue;
    units::Frequency shakeUnits;
};

#endif // SHAKEOPERATION_H
