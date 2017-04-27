/*
 * Stir.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_STIR_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_STIR_H_

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/container/finishableoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class STIR_EXPORT Stir: public FinishableOperation {
public:
	// Node methods
	Stir();
	Stir(const Stir & node);

	virtual std::string toText();
	//

    Stir(int containerId, const std::string & sourceId, std::shared_ptr<MathematicOperable> intensity, units::Frequency intensityUnits);
	virtual ~Stir();

    virtual void execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument);
    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);

protected:
    std::string sourceId;
	std::shared_ptr<MathematicOperable> intensity;
    units::Frequency intensityUnits;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_STIR_H_ */
