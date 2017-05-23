#ifndef STOPCONTINUOSFLOW_H
#define STOPCONTINUOSFLOW_H

#include <string>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operations/container/actuatorsoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class StopContinuosFlow : public ActuatorsOperation
{
public:
    // Node methods
    StopContinuosFlow();
    StopContinuosFlow(const StopContinuosFlow & node);

    virtual std::string toText();
    //

    StopContinuosFlow(int idContainer, const std::string & idSource, const std::string & idTarget);
    virtual ~StopContinuosFlow();

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void simulate(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument);

protected:
    std::string idSource;
    std::string idTarget;
};

#endif // STOPCONTINUOSFLOW_H
