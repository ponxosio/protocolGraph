/*
 * TimeStep.h
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_TIMESTEP_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_TIMESTEP_H_

#include <utils/units.h>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/VariableEntry.h"
#include "protocolGraph/operations/container/actuatorsoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class TIMESTEP_EXPORT TimeStep: public ActuatorsOperation {
public:
	// Node methods
	TimeStep();
	TimeStep(const TimeStep & node);

	virtual std::string toText();
	//
    TimeStep(int containerId, std::shared_ptr<VariableEntry> receiver);

	virtual ~TimeStep();
    virtual void execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument);

protected:
	std::shared_ptr<VariableEntry> receiver;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_TIMESTEP_H_ */
