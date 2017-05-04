#include "centrifugateoperation.h"

CentrifugateOperation::CentrifugateOperation() :
    FinishableOperation()
{
    sourceID = "";
    speed = NULL;
    speedUnits = units::Hz;
}

CentrifugateOperation::CentrifugateOperation(const CentrifugateOperation & node) :
    FinishableOperation(node), sourceID(node.sourceID)
{
    this->speed = node.speed;
    this->speedUnits = node.speedUnits;
}

CentrifugateOperation::CentrifugateOperation(
        int idContainer,
        const std::string & sourceID,
        std::shared_ptr<MathematicOperable> speed,
        units::Frequency speedUnits) :
    FinishableOperation(idContainer), sourceID(sourceID)
{
    this->speed = speed;
    this->speedUnits = speedUnits;
}

CentrifugateOperation::~CentrifugateOperation() {

}

std::string CentrifugateOperation::toText() {
    return std::to_string(containerID) + "[label=\"centrifugate("
            + sourceID + ", " + speed.get()->toString()
            + ")\"];";
}

void CentrifugateOperation::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->centrifugate(sourceID, speed->getValue() * speedUnits);
}

void CentrifugateOperation::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->stopCentrifugate(sourceID);
}
