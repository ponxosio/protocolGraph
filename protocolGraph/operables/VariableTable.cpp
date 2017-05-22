/*
 * VariableTable.cpp
 *
 *  Created on: 15 de mar. de 2016
 *      Author: angel
 */

#include "VariableTable.h"

using namespace std;

VariableTable::VariableTable() {

}

VariableTable::VariableTable(const VariableTable & varTable) :
    table(varTable.table)
{

}

VariableTable::~VariableTable() {
}

double VariableTable::getVaue(const std::string& name)
		throw (std::invalid_argument) {

	double vuelta = 0.0;
	auto entry = table.find(name);
	if (entry != table.end()) {
        vuelta =entry->second.getValue();
	} else {
		throw(invalid_argument("the key:\"" + name + "\" does not exits"));
	}
	return vuelta;
}

bool VariableTable::getPhysical(const std::string& name)
		throw (std::invalid_argument) {

	bool vuelta = false;
	auto entry = table.find(name);
	if (entry != table.end()) {
        vuelta = entry->second.getIsPhysical();
	} else {
		throw(invalid_argument("the key:\"" + name + "\" does not exits"));
	}
	return vuelta;
}

bool VariableTable::hasBeenWritten(const std::string & name) {
    auto entry = table.find(name);
    if (entry != table.end()) {
        return entry->second.getHasBeenWritten();
    } else {
        throw(invalid_argument("the key:\"" + name + "\" does not exits"));
    }
}

void VariableTable::setValue(const string& name, double value) {
    auto entry = table.find(name);
	if (entry != table.end()) {
        VariableState & state = entry->second;
        if (state.getIsWritable()) {
            state.setValue(value);
        }
        state.setHasBeenWritten(true);
	} else {
        VariableState newState;
        newState.setValue(value);
        newState.setHasBeenWritten(true);

        table.insert(make_pair(name, newState));
	}
}

void VariableTable::setPhysical(const string& name, bool physical) {
	auto entry = table.find(name);
	if (entry != table.end()) {
        entry->second.setPhysical(physical);
	} else {
        VariableState newState;
        newState.setPhysical(physical);

        table.insert(make_pair(name, newState));
	}
}

void VariableTable::setHasBeenWritten(const std::string & name, bool hasBeenWritten) {
    auto entry = table.find(name);
    if (entry != table.end()) {
        entry->second.setHasBeenWritten(hasBeenWritten);
    } else {
        VariableState newState;
        newState.setHasBeenWritten(hasBeenWritten);

        table.insert(make_pair(name, newState));
    }
}

void VariableTable::setIsWritable(const std::string & name, bool isWritable) {
    auto entry = table.find(name);
    if (entry != table.end()) {
        entry->second.setWritable(isWritable);
    } else {
        VariableState newState;
        newState.setWritable(isWritable);

        table.insert(make_pair(name, newState));
    }
}

std::shared_ptr<Memento<VariableTable>> VariableTable::createMemento() const {
    return std::make_shared<Memento<VariableTable>>(*this);
}

void VariableTable::restoreMememnto(const Memento<VariableTable> & memento) {
    restoreVariableTable(memento.getState());
}

void VariableTable::restoreVariableTable(const VariableTable & table) {
    this->table.clear();

    for (auto actualPair : table.table) {
        this->table.insert(actualPair);
    }
}





