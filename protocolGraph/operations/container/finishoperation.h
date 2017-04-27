#ifndef FINISHOPERATION_H
#define FINISHOPERATION_H

//local
#include "protocolGraph/operations/container/actuatorsoperation.h"
#include "protocolGraph/operations/container/finishableoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class FinishOperation : public ActuatorsOperation
{
public:
    FinishOperation();
    FinishOperation(const FinishOperation & obj);
    FinishOperation(int idConatiner, std::shared_ptr<FinishableOperation> operation);
    virtual ~FinishOperation();

    virtual std::string toText();

    //interface implementation
    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);

protected:
    std::shared_ptr<FinishableOperation> operation;
};

#endif // FINISHOPERATION_H
