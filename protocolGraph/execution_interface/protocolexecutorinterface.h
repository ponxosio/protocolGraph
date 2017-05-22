#ifndef PROTOCOLEXECUTORINTERFACE_H
#define PROTOCOLEXECUTORINTERFACE_H

#include <stdexcept>

#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/ProtocolGraph.h"

class ProtocolExecutorInterface {
public:
    ProtocolExecutorInterface(std::shared_ptr<ProtocolGraph> protocol)
    {
        this->protocol = protocol;
    }

    virtual ~ProtocolExecutorInterface(){}

    virtual void executeProtocol(std::shared_ptr<ActuatorsExecutionInterface> executor) throw (std::runtime_error) = 0;

protected:
    std::shared_ptr<ProtocolGraph> protocol;
};

#endif // PROTOCOLEXECUTORINTERFACE_H
