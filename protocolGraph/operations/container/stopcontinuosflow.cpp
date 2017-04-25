#include "stopcontinuosflow.h"

StopContinuosFlow::StopContinuosFlow() :
    ActuatorsOperation()
{
    idSource = "";
    idTarget = "";
}
StopContinuosFlow::StopContinuosFlow(const StopContinuosFlow & node) :
    ActuatorsOperation(node), idSource(node.idSource), idTarget(node.idTarget)
{

}

StopContinuosFlow::StopContinuosFlow(int idContainer, const std::string & idSource, const std::string & idTarget) :
    ActuatorsOperation(idContainer), idSource(idSource), idTarget(idTarget)
{

}

StopContinuosFlow::~StopContinuosFlow() {

}

void StopContinuosFlow::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->stopContinuosFlow(idSource, idTarget);
}

std::string StopContinuosFlow::toText() {
    return std::to_string(containerID) + "[label=\"stopContinousFlow("
            + idSource + ", " + idTarget + ")\"];";
}
