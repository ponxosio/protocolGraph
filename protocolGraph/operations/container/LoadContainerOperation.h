/*
 * LoadContainer.h
 *
 *  Created on: 5 de abr. de 2016
 *      Author: angel
 */

#ifndef SRC_PROTOCOLGRAPH_OPERATIONS_CONTAINER_GETVOLUME_H_
#define SRC_PROTOCOLGRAPH_OPERATIONS_CONTAINER_GETVOLUME_H_

#include <utils/units.h>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/container/actuatorsoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class LOADCONTAINEROPERATION_EXPORT LoadContainerOperation: public ActuatorsOperation {
public:
	//methods for node
	LoadContainerOperation();
	LoadContainerOperation(const LoadContainerOperation & obj);

	virtual std::string toText();
	//

    LoadContainerOperation(int idConatiner, const std::string & idSource, std::shared_ptr<MathematicOperable> volume, units::Volume volumeUnits);

	virtual ~LoadContainerOperation();

    virtual void execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument);
    virtual void simulate(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument);

protected:
    std::string idSource;
    std::shared_ptr<MathematicOperable> volume;
    units::Volume volumeUnits;
};
#endif /* SRC_PROTOCOLGRAPH_OPERATIONS_CONTAINER_GETVOLUME_H_ */
