/*
 * Mix.h
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_MIX_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_MIX_H_

#include <utils/units.h>

//local
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/container/ContainerOperation.h"

#include "protocolGraph/protocolgraph_global.h"

class MIX_EXPORT Mix: public ActuatorsOperation {
public:
	// Node methods
	Mix();
	Mix(const Mix & node);

	virtual std::string toText();
	//

    Mix(int idConatiner,
        int idSource1,
        int idSource2,
        int idTarget,
        std::shared_ptr<MathematicOperable> volume1,
        units::Volume unitsVolume1,
        std::shared_ptr<MathematicOperable> volume2,
        units::Volume unitsVolume2);

	virtual ~Mix();

    virtual void execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument);

protected:
	int idSource1;
	int idSource2;
	int idTarget;

    std::shared_ptr<MathematicOperable> volume1;
	std::shared_ptr<MathematicOperable> volume2;

    units::Volume unitsVolume1;
    units::Volume unitsVolume2;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_MIX_H_ */
