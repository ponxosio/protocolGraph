/*
 * ControlNode.h
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_LOOPNODE_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_LOOPNODE_H_

#pragma warning( disable : 4290 )

//types strings
#define LOOP_STRING "loop"

#include <memory>

//local lib
#include <utils/Utils.h>
#include <graph/Node.h>

//local
#include "protocolGraph/operations/cpuoperation.h"
#include "protocolGraph/operables/comparison/ComparisonOperable.h"

#include "protocolGraph/protocolgraph_global.h"

/**
 * Implements a flow control operation, if or while
 */
class LOOPNODE_EXPORT LoopNode: public CPUOperation {
public:
	//Methods for Node
	LoopNode();
	LoopNode(const LoopNode & node);

	virtual string toText();
	//
	LoopNode(int containerId, std::shared_ptr<ComparisonOperable> conditionIN);

	virtual ~LoopNode();

	virtual void execute();

	//GETTERS & SETTERS
	const std::shared_ptr<ComparisonOperable>& getConditionIN() const {
		return conditionIN;
	}
protected:
	std::shared_ptr<ComparisonOperable> conditionIN;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_LOOPNODE_H_ */
