/*
 * DivergeNode.h
 *
 *  Created on: 11 de abr. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_DIVERGENODE_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_DIVERGENODE_H_

#pragma warning( disable : 4290 )

//types strings
#define DIVERGE_STRING "if"

#include <utils/Utils.h>

//local
#include "protocolGraph/operables/comparison/ComparisonOperable.h"
#include "protocolGraph/operations/cpuoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class DIVERGENODE_EXPORT DivergeNode: public CPUOperation {
public:
	//Methods for Node
	DivergeNode();
	DivergeNode(const DivergeNode & node);

	virtual string toText();
	//

	DivergeNode(int containerId,
			std::shared_ptr<ComparisonOperable> conditionIN);
	virtual ~DivergeNode();

	virtual void execute();

	//GETTERS & SETTERS
	const std::shared_ptr<ComparisonOperable>& getConditionIN() const {
		return conditionIN;
	}

protected:
	std::shared_ptr<ComparisonOperable> conditionIN;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_DIVERGENODE_H_ */
