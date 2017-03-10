/*
 * SetContinousFlow.h
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONATINER_SETCONTINOUSFLOW_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONATINER_SETCONTINOUSFLOW_H_

//local lib
#include <utils/units.h>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/container/ContainerOperation.h"

#include "protocolGraph/protocolgraph_global.h"

class SETCONTINOUSFLOW_EXPORT SetContinousFlow: public ActuatorsOperation {
public:
	// Node methods
	SetContinousFlow();
	SetContinousFlow(const SetContinousFlow & node);

	virtual std::string toText();
	//

    SetContinousFlow(int idContainer,
                     int idSource,
                     int idTarget,
                     std::shared_ptr<MathematicOperable> rate,
                     units::Volumetric_Flow rateUnits);
	virtual ~SetContinousFlow();

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);

protected:
	int idSource;
	int idTarget;
	std::shared_ptr<MathematicOperable> rate;
    units::Volumetric_Flow rateUnits;
};

#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONATINER_SETCONTINOUSFLOW_H_ */
