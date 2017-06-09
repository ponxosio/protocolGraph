#ifndef GENERALPROTOCOLEXECUTOR_H
#define GENERALPROTOCOLEXECUTOR_H


#include "protocolGraph/execution_interface/protocolexecutorinterface.h"

class GeneralProtocolExecutor : public ProtocolExecutorInterface
{
public:
    GeneralProtocolExecutor(std::shared_ptr<ProtocolGraph> protocol);
    virtual ~GeneralProtocolExecutor();

    virtual void executeProtocol(std::shared_ptr<ActuatorsExecutionInterface> executor,int nargs, ...) throw (std::runtime_error);
};

#endif // GENERALPROTOCOLEXECUTOR_H
