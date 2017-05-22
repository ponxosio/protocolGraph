#ifndef PROTOCOLSIMULATIONINTERFACE_H
#define PROTOCOLSIMULATIONINTERFACE_H

#include <stdexcept>

#include "protocolGraph/execution_interface/actuatorssimulationinterface.h"
#include "protocolGraph/ProtocolGraph.h"

class ProtocolSimulatorInterface {
public:
    ProtocolSimulatorInterface(std::shared_ptr<ProtocolGraph> protocol)
    {
        this->protocol = protocol;
    }

    virtual ~ProtocolSimulatorInterface();

    virtual void simulateProtocol(std::shared_ptr<ActuatorsSimulationInterface> executor) throw (std::runtime_error) = 0;

protected:
    std::shared_ptr<ProtocolGraph> protocol;
};

#endif // PROTOCOLSIMULATIONINTERFACE_H
