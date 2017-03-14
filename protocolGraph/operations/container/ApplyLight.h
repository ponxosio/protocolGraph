/*
 * ApplyLight.h
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_APPLYLIGHT_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_APPLYLIGHT_H_

//local
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/container/ContainerOperation.h"

//units
#include <utils/units.h>

#include "protocolGraph/protocolgraph_global.h"

class APPLYLIGHT_EXPORT ApplyLight: public ActuatorsOperation {
public:
	// Node methods
	ApplyLight();
	ApplyLight(const ApplyLight & node);

	virtual std::string toText();
	//

	ApplyLight(int idContainer,
            int sourceID,
            std::shared_ptr<MathematicOperable> wavelength,
            units::Length wavelengthUnits,
            std::shared_ptr<MathematicOperable> intensity,
            units::LuminousIntensity intensityUnits);

	virtual ~ApplyLight();

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);

protected:
	int sourceId;
	std::shared_ptr<MathematicOperable> wavelength;
	std::shared_ptr<MathematicOperable> intensity;

    units::Length wavelengthUnits;
    units::LuminousIntensity intensityUnits;
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_APPLYLIGHT_H_ */
