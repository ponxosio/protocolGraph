#include "finishoperation.h"

FinishOperation::FinishOperation() :
    ActuatorsOperation()
{
    this->operation = NULL;
}

FinishOperation::FinishOperation(const FinishOperation & obj) :
    ActuatorsOperation(obj)
{
    this->operation = obj.operation;
}

FinishOperation::FinishOperation(int idConatiner, std::shared_ptr<FinishableOperation> operation) :
    ActuatorsOperation(idConatiner)
{
    this->operation = operation;
}

FinishOperation::~FinishOperation() {

}

std::string FinishOperation::toText() {
    return std::to_string(containerID)
            + "[label=\"finish("
            + (operation ? std::to_string(operation->getContainerId()) : "?")
            + ")\"];";
}

void FinishOperation::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    operation->finish(actuatorInterface);
}
