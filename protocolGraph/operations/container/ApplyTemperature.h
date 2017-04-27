/*
 * ApplyTemperature.h
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_APPLYTEMPERATURE_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_APPLYTEMPERATURE_H_

#pragma warning( disable : 4290 )

//local
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/container/finishableoperation.h"

//units
#include <utils/units.h>

#include "protocolGraph/protocolgraph_global.h"

class APPLYTEMPERATURE_EXPORT ApplyTemperature: public FinishableOperation {
public:
	// Node methods
	ApplyTemperature();
	ApplyTemperature(const ApplyTemperature & node);

	virtual std::string toText();
	//

    ApplyTemperature(int containerId,
                     const std::string & sourceId,
                     std::shared_ptr<MathematicOperable> temperature,
                     units::Temperature temperatureUnits);
	virtual ~ApplyTemperature();

    virtual void execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument);
    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);

protected:
    std::string sourceId;
    std::shared_ptr<MathematicOperable> temperature;
    units::Temperature temperatureUnits;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_APPLYTEMPERATURE_H_ */
