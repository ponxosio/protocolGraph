/*
 * ContainerOperation.h
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_CONTAINEROPERATION_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_CONTAINEROPERATION_H_

#include <string>
#include <stdexcept>

#include <graph/Node.h>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"

/**
 * Interface that represents all the operations that can be made over the machine containers
 */
class ActuatorsOperation: public Node {
public:
    ActuatorsOperation() : Node() {}
    ActuatorsOperation(const ActuatorsOperation & obj) : Node(obj) {}
    ActuatorsOperation(int idConatiner) : Node(idConatiner) {}

    virtual ~ActuatorsOperation() {}

    //pure virtual
    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) = 0;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_CONTAINEROPERATION_H_ */
