#ifndef CENTRIFUGATEOPERATION_H
#define CENTRIFUGATEOPERATION_H

//local
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/container/finishableoperation.h"

//units
#include <utils/units.h>

#include "protocolGraph/protocolgraph_global.h"

class CentrifugateOperation : public FinishableOperation
{
public:
    // Node methods
    CentrifugateOperation();
    CentrifugateOperation(const CentrifugateOperation & node);

    virtual std::string toText();
    //

    CentrifugateOperation(int idContainer,
            const std::string & sourceID,
            std::shared_ptr<MathematicOperable> speed,
            units::Frequency speedUnits);

    virtual ~CentrifugateOperation();

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);

protected:
    std::string sourceID;
    std::shared_ptr<MathematicOperable> speed;
    units::Frequency speedUnits;
};

#endif // CENTRIFUGATEOPERATION_H
