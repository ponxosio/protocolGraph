/*
 * SetContinousFlow.cpp
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#include "SetContinousFlow.h"

SetContinousFlow::SetContinousFlow() :
		ActuatorsOperation() {
	this->idSource = -1;
	this->idTarget = -1;
	this->rate = std::shared_ptr<MathematicOperable>();
    this->rateUnits = units::l/units::s;
}

SetContinousFlow::SetContinousFlow(const SetContinousFlow& obj) :
		ActuatorsOperation(obj) {
	this->idSource = obj.idSource;
	this->idTarget = obj.idTarget;
	this->rate = obj.rate;
    this->rateUnits = obj.rateUnits;
}

SetContinousFlow::SetContinousFlow(
        int idContainer,
        int idSource,
        int idTarget,
        std::shared_ptr<MathematicOperable> rate,
        units::Volumetric_Flow rateUnits) :
    ActuatorsOperation(idContainer)
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
            + std::to_string(idSource) + ", " + std::to_string(idTarget)
			+ ", " + rate.get()->toString() + ")\"];";
}

void SetContinousFlow::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument)  {
    actuatorInterface->setContinuosFlow(idSource, idTarget, rate.get()->getValue() * rateUnits);
}
