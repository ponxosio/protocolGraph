/*
 * VariableEntry.cpp
 *
 *  Created on: 15 de mar. de 2016
 *      Author: angel
 */

#include "VariableEntry.h"

using namespace std;

VariableEntry::VariableEntry() {
	this->name = "undefined";
    this->variableTable = std::shared_ptr<VariableTable>();
}

VariableEntry::VariableEntry(const std::string & name, std::shared_ptr<VariableTable> varTable) :
    name(name)
{
    this->variableTable = varTable;
    if (!variableTable->containsKey(name)) {
        variableTable->setValue(name, 0.0);
    }
}   

double VariableEntry::getValue() throw (std::invalid_argument)  {
    return variableTable->getVaue(name);
}

bool VariableEntry::isPhysical() throw (std::invalid_argument)  {
    return variableTable->getPhysical(name);
}

bool VariableEntry::equal(const MathematicOperable* obj) const{
	bool vuelta = false;
	if (Utils::IsType<VariableEntry, MathematicOperable>(obj)) {
		const VariableEntry* cast = dynamic_cast<const VariableEntry*>(obj);
		vuelta = (cast->name == this->name);
	}
	return vuelta;
}

void VariableEntry::setValue(double value) throw (std::invalid_argument)  {
    variableTable->setValue(name, value);
}

void VariableEntry::setPhysical(bool physical) throw (std::invalid_argument)  {
    variableTable->setPhysical(name, physical);
}
