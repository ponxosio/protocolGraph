/*
 * Mix.cpp
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#include "Mix.h"

Mix::Mix() :
    FinishableOperation()
{
    this->idSource1 = "";
    this->idSource2 = "";
    this->idTarget = "";
    this->volume1 = NULL;
    this->volume2 = NULL;
    this->unitsVolume1 = units::l;
    this->unitsVolume2 = units::l;
    this->opDuration = NULL;
}

Mix::Mix(const Mix& node) :
    FinishableOperation(node)
{
	this->idSource1 = node.idSource1;
	this->idSource2 = node.idSource2;
	this->idTarget = node.idTarget;
	this->volume1 = node.volume1;
	this->volume2 = node.volume2;
    this->unitsVolume1 = node.unitsVolume1;
    this->unitsVolume2 = node.unitsVolume2;
    this->opDuration = node.opDuration;
}

Mix::Mix(int idConatiner,
         const std::string & idSource1,
         const std::string & idSource2,
         const std::string & idTarget,
         std::shared_ptr<MathematicOperable> volume1,
         units::Volume unitsVolume1,
         std::shared_ptr<MathematicOperable> volume2,
         units::Volume unitsVolume2,
         std::shared_ptr<VariableEntry> opDuration) :
    FinishableOperation(idConatiner)
{
	this->idSource1 = idSource1;
	this->idSource2 = idSource2;
	this->idTarget = idTarget;
	this->volume1 = volume1;
	this->volume2 = volume2;
    this->unitsVolume1 = unitsVolume1;
    this->unitsVolume2 = unitsVolume2;
    this->opDuration = opDuration;
}

Mix::~Mix() {
}

std::string Mix::toText() {
    return std::to_string(containerID) + "[label=\"Mix("
            + idSource1 + ", " + idSource2 + ", " + idTarget + ", "
            + (volume1 ? volume1->toString() : "?")
            + ", "
            + (volume2 ? volume2->toString() : "?")
            + ")\"];";
}

void Mix::execute(ActuatorsExecutionInterface* actuatorsInterface) throw(std::invalid_argument)  {
    units::Time duration = actuatorsInterface->mix(
                            idSource1,
                            idSource2,
                            idTarget,
                            volume1.get()->getValue() * unitsVolume1,
                            volume2.get()->getValue() * unitsVolume2);
    opDuration->setValue(Utils::toDefaultUnits(duration));
}

void Mix::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->stopMix(idSource1, idSource2, idTarget);
}
