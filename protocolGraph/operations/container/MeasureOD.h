/*
 * MeasureOD.h
 *
 *  Created on: 28 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_MEASUREOD_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_MEASUREOD_H_

//units
#include <utils/units.h>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operables/mathematics/VariableEntry.h"
#include "protocolGraph/operations/container/finishableoperation.h"

#include "protocolGraph/protocolgraph_global.h"

class MEASUREOD_EXPORT MeasureOD: public FinishableOperation {
public:
	// Node methods
	MeasureOD();
	MeasureOD(const MeasureOD & node);

	virtual std::string toText();
	//

    MeasureOD(int containerId,
              const std::string & sourceId,
              std::shared_ptr<VariableEntry> receiver,
              std::shared_ptr<MathematicOperable> measurmentFrequency,
              units::Frequency measurmentFrequencyUnits,
              std::shared_ptr<MathematicOperable> wavelength,
              units::Length wavelengthUnits);
	virtual ~MeasureOD();

    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void simulate(ActuatorsSimulationInterface* simulateInterface) throw(std::invalid_argument);

    virtual void finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);
    virtual void finish(ActuatorsSimulationInterface* simulateInterface) throw(std::invalid_argument);

protected:
    std::string sourceId;
	std::shared_ptr<VariableEntry> receiver;

    std::shared_ptr<MathematicOperable> wavelength;
    std::shared_ptr<MathematicOperable> measurmentFrequency;

    units::Frequency measurmentFrequencyUnits;
    units::Length wavelengthUnits;
};

#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_OPERATIONS_CONTAINER_MEASUREOD_H_ */
