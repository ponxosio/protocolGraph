#include "shakeoperation.h"

ShakeOperation::ShakeOperation() :
    FinishableOperation()
{
    this->sourceID = "";
    this->shakeValue = NULL;
    this->shakeUnits = units::Hz;
}

ShakeOperation::ShakeOperation(const ShakeOperation & node) :
    FinishableOperation(node), sourceID(node.sourceID)
{
    this->shakeValue = node.shakeValue;
    this->shakeUnits = node.shakeUnits;
}

ShakeOperation::ShakeOperation(
        int idContainer,
        const std::string & sourceID,
        std::shared_ptr<MathematicOperable> shakeValue,
        units::Frequency shakeUnits) :
    FinishableOperation(idContainer) , sourceID(sourceID)
{
    this->shakeValue = shakeValue;
    this->shakeUnits = shakeUnits;
}

ShakeOperation::~ShakeOperation() {

}

std::string ShakeOperation::toText() {
    return std::to_string(containerID) + "[label=\"shake("
            + sourceID + ", " + shakeValue->toString()
            + ")\"];";
}

void ShakeOperation::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->shake(sourceID, shakeValue->getValue() * shakeUnits);
}

void ShakeOperation::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->stopShake(sourceID);
}
