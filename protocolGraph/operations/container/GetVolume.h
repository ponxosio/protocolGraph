/*
 * GetVolume.h
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_GETVOLUME_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_GETVOLUME_H_

//local

#include <utils/units.h>
#include <utils/utils.h>

#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/VariableEntry.h"
#include "protocolGraph/operations/container/actuatorsoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class GETVOLUME_EXPORT GetVolume: public ActuatorsOperation {
public:
	// Node methods
	GetVolume();
	GetVolume(const GetVolume & node);

	virtual std::string toText();
	//

    GetVolume(int containerId, const std::string & sourceId, std::shared_ptr<VariableEntry> receiver);
	virtual ~GetVolume();

    virtual void execute(ActuatorsExecutionInterface* actuatorsExecution) throw(std::invalid_argument);
    virtual void simulate(ActuatorsSimulationInterface* simulationExecution) throw(std::invalid_argument);

protected:
    std::string sourceId;
	std::shared_ptr<VariableEntry> receiver;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_GETVOLUME_H_ */
