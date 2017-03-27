/*
 * AsignationOperation.cpp
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#include "AssignationOperation.h"

AssignationOperation::AssignationOperation() :
    CPUOperation()
{
	receiver = std::shared_ptr<VariableEntry>();
	value = std::shared_ptr<MathematicOperable>();
}

AssignationOperation::AssignationOperation(const AssignationOperation& obj) :
        CPUOperation(obj)
{
	this->receiver = obj.receiver;
	this->value = obj.value;
}

AssignationOperation::AssignationOperation(int idContainer,
		std::shared_ptr<VariableEntry> receiver,
		std::shared_ptr<MathematicOperable> value) :
    CPUOperation(idContainer)
{
	this->receiver = receiver;
	this->value = value;
}

AssignationOperation::~AssignationOperation() {
}

std::string AssignationOperation::toText() {
    return std::to_string(containerID) + "[label=\""
			+ receiver.get()->toString() + " = " + value.get()->toString()
			+ "\"];";
}

void AssignationOperation::execute() throw(std::invalid_argument)  {
	receiver.get()->setValue(value.get()->getValue());
}
