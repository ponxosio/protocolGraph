#include "electrophoresisoperation.h"

ElectrophoresisOperation::ElectrophoresisOperation() :
    FinishableOperation()
{
    sourceId = "";
    fieldStrength = NULL;
    fieldUnits = units::V / units::m;
}

ElectrophoresisOperation::ElectrophoresisOperation(const ElectrophoresisOperation & node) :
    FinishableOperation(node), sourceId(node.sourceId)
{
    this->fieldStrength = node.fieldStrength;
    this->fieldUnits = node.fieldUnits;
    this->dataReference = node.dataReference;
}

ElectrophoresisOperation::ElectrophoresisOperation(
        int id,
        const std::string & sourceId,
        std::shared_ptr<MathematicOperable> fieldStrength,
        units::ElectricField fieldUnits,
         std::shared_ptr<VariableEntry> dataReference) :
    FinishableOperation(id), sourceId(sourceId)
{
   this->fieldStrength = fieldStrength;
   this->fieldUnits = fieldUnits;
   this->dataReference = dataReference;
}

ElectrophoresisOperation::~ElectrophoresisOperation() {

}

std::string ElectrophoresisOperation::toText() {
    return std::to_string(containerID) + "[label=\"" + dataReference->toString() +" = electrophoresis("
            + sourceId + ", " + fieldStrength.get()->toString() + ")\"];";
}

void ElectrophoresisOperation::execute(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    actuatorInterface->startElectrophoresis(sourceId, fieldStrength->getValue() * fieldUnits);
}

void ElectrophoresisOperation::finish(ActuatorsExecutionInterface* actuatorInterface) throw(std::invalid_argument) {
    saveElectrophoresisResult(actuatorInterface->stopElectrophoresis(sourceId), dataReference);
}

void ElectrophoresisOperation::saveElectrophoresisResult(const ElectrophoresisResult & result, std::shared_ptr<VariableEntry> dataReference) {
    //TODO:
}
