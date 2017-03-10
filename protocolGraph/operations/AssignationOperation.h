/*
 * AsignationOperation.h
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_ASSIGNATIONOPERATION_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_ASSIGNATIONOPERATION_H_

#include <utils/Utils.h>

#include "protocolGraph/operables/mathematics/VariableEntry.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/cpuoperation.h"

#include "protocolGraph/protocolgraph_global.h"

/**
 * Implements a variable assignation, for example "t = 3 + d*2"
 */
class ASSIGNATIONOPERATION_EXPORT AssignationOperation: public CPUOperation {
public:
	//methods of node
	AssignationOperation();
	AssignationOperation(const AssignationOperation & node);

	virtual string toText();
	//
	/**
	 *
	 * @param idContainer id of the node
	 * @param receiver variable whose value is going to be changed
	 * @param value numeric value to assign to the variable
	 */
	AssignationOperation(int idContainer,
			std::shared_ptr<VariableEntry> receiver,
			std::shared_ptr<MathematicOperable> value);

	virtual ~AssignationOperation();

	/**
	 * Executes the assignation
	 */
	virtual void execute() throw(std::invalid_argument);
protected:
	/**
	 * variable whose value is going to be changed
	 */
	std::shared_ptr<VariableEntry> receiver;
	/**
	 * numeric value to assign to the variable
	 */
	std::shared_ptr<MathematicOperable> value;
};

#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_ASSIGNATIONOPERATION_H_ */
