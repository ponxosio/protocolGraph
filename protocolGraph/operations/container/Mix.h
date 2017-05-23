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
#include "protocolGraph/operables/mathematics/VariableEntry.h"
#include "protocolGraph/operations/container/finishableoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class MIX_EXPORT Mix: public FinishableOperation {
public:
	// Node methods
	Mix();
	Mix(const Mix & node);

	virtual std::string toText();
	//

    Mix(int idConatiner,
        const std::string & idSource1,
        const std::string & idSource2,
        const std::string & idTarget,
        std::shared_ptr<MathematicOperable> volume1,
        units::Volume unitsVolume1,
        std::shared_ptr<MathematicOperable> volume2,
        units::Volume unitsVolume2,
        std::shared_ptr<VariableEntry> opDuration);

	virtual ~Mix();

    virtual void execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument);
    virtual void simulate(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument);

    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void finish(ActuatorsSimulationInterface* simulationInterface) throw(std::invalid_argument);

protected:
    std::string idSource1;
    std::string idSource2;
    std::string idTarget;

    std::shared_ptr<MathematicOperable> volume1;
	std::shared_ptr<MathematicOperable> volume2;
    std::shared_ptr<VariableEntry> opDuration;

    units::Volume unitsVolume1;
    units::Volume unitsVolume2;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_MIX_H_ */
