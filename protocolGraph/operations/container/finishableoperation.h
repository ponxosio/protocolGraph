#ifndef FINISHABLEOPERATION_H
#define FINISHABLEOPERATION_H

#include "protocolGraph/operations/container/actuatorsoperation.h"

class FinishableOperation: public ActuatorsOperation {
public:
    FinishableOperation() : ActuatorsOperation() {}
    FinishableOperation(const FinishableOperation & obj) : ActuatorsOperation(obj) {}
    FinishableOperation(int idConatiner) : ActuatorsOperation(idConatiner) {}

    virtual ~FinishableOperation() {}

    //pure virtual
    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) = 0;
    virtual void finish(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument) = 0;
};

#endif // FINISHABLEOPERATION_H
