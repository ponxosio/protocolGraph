/*
 * SetContinousFlow.cpp
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#include "SetContinousFlow.h"

SetContinousFlow::SetContinousFlow() :
        FinishableOperation() {
	this->idSource = -1;
	this->idTarget = -1;
	this->rate = std::shared_ptr<MathematicOperable>();
    this->rateUnits = units::l/units::s;
}

SetContinousFlow::SetContinousFlow(const SetContinousFlow& obj) :
        FinishableOperation(obj) {
	this->idSource = obj.idSource;
	this->idTarget = obj.idTarget;
	this->rate = obj.rate;
    this->rateUnits = obj.rateUnits;
}

SetContinousFlow::SetContinousFlow(
        int idContainer,
        const std::string & idSource,
        const std::string & idTarget,
        std::shared_ptr<MathematicOperable> rate,
        units::Volumetric_Flow rateUnits) :
    FinishableOperation(idContainer)
{

	this->idSource = idSource;
	this->idTarget = idTarget;
	this->rate = rate;
    this->rateUnits = rateUnits;
}

SetContinousFlow::~SetContinousFlow() {
}

std::string SetContinousFlow::toText() {
    return std::to_string(containerID) + "[label=\"setContinousFlow("
            + idSource + ", " + idTarget + ", "
            + (rate ? rate->toString() : "?")
            + ")\"];";
}

void SetContinousFlow::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument)  {
    actuatorInterface->setContinuosFlow(idSource, idTarget, rate.get()->getValue() * rateUnits);
}

void SetContinousFlow::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->stopContinuosFlow(idSource, idTarget);
}
