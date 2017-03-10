/*
 * Transfer.h
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_TRANSFER_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_TRANSFER_H_

#include <utils/units.h>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/container/ContainerOperation.h"

#include "protocolGraph/protocolgraph_global.h"

class TRANSFER_EXPORT Transfer: public ActuatorsOperation {
public:
	//Node methods
	Transfer();
	Transfer(const Transfer & node) ;
	virtual ~Transfer();

	virtual std::string toText();
	//

    Transfer(int idContainer, int idSource, int idTarget, std::shared_ptr<MathematicOperable> volume, units::Volume volumeUnits);

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);

protected:
	int idSource;
	int idTarget;
    std::shared_ptr<MathematicOperable> volume;
    units::Volume volumeUnits;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_TRANSFER_H_ */
