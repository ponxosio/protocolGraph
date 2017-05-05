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
#include "protocolGraph/operables/mathematics/VariableEntry.h"

#include "protocolGraph/operations/container/actuatorsoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class TRANSFER_EXPORT Transfer: public ActuatorsOperation {
public:
	//Node methods
	Transfer();
	Transfer(const Transfer & node) ;
	virtual ~Transfer();

	virtual std::string toText();
	//

    Transfer(int idContainer,
             const std::string & idSource,
             const std::string & idTarget,
             std::shared_ptr<MathematicOperable> volume,
             units::Volume volumeUnits,
             std::shared_ptr<VariableEntry> opDuration);

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);

protected:
    std::string idSource;
    std::string idTarget;

    std::shared_ptr<MathematicOperable> volume;
    units::Volume volumeUnits;

    std::shared_ptr<VariableEntry> opDuration;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_TRANSFER_H_ */
