#ifndef SETTIMESTEP_H
#define SETTIMESTEP_H

#include <utils/units.h>

//local
#include "protocolGraph/execution_interface/actuatorsexecutioninterface.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operations/container/ContainerOperation.h"

#include "protocolGraph/protocolgraph_global.h"

class SETTIMESTEP_EXPORT SetTimeStep: public ActuatorsOperation {
public:
    // Node methods
    SetTimeStep();
    SetTimeStep(const SetTimeStep & node);

    virtual std::string toText();
    //
    SetTimeStep(int containerId, std::shared_ptr<MathematicOperable> timeSlice, units::Time timeSliceUnits);

    virtual ~SetTimeStep();
    virtual void execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument);

protected:
    std::shared_ptr<MathematicOperable> timeSlice;
    units::Time timeSliceUnits;
};
#endif // SETTIMESTEP_H
