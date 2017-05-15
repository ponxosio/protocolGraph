#ifndef ELECTROPHORESISOPERATION_H
#define ELECTROPHORESISOPERATION_H

#include <memory>
#include <string>

//local
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operables/mathematics/VariableEntry.h"
#include "protocolGraph/operations/container/finishableoperation.h"

//units
#include <utils/electrophoresisresult.h>
#include <utils/units.h>

#include "protocolGraph/protocolgraph_global.h"

class ElectrophoresisOperation : public FinishableOperation
{
public:
    // Node methods
    ElectrophoresisOperation();
    ElectrophoresisOperation(const ElectrophoresisOperation & node);

    virtual std::string toText();
    //

    ElectrophoresisOperation(int id,
                             const std::string & sourceId,
                             std::shared_ptr<MathematicOperable> fieldStrength,
                             units::ElectricField fieldUnits,
                             std::shared_ptr<VariableEntry> dataReference);
    virtual ~ElectrophoresisOperation();

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);

protected:
    std::string sourceId;
    std::shared_ptr<MathematicOperable> fieldStrength;
    units::ElectricField fieldUnits;
    std::shared_ptr<VariableEntry> dataReference;

    void saveElectrophoresisResult(std::shared_ptr<ElectrophoresisResult> result, std::shared_ptr<VariableEntry> dataReference);
};

#endif // ELECTROPHORESISOPERATION_H
