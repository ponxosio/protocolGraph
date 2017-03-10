/*
 * VariableEntry.h
 *
 *  Created on: 15 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_OPERABLES_MATHEMATICS_VARIABLEENTRY_H_
#define SRC_OPERABLES_MATHEMATICS_VARIABLEENTRY_H_

#include <string>
#include <memory>
#include <stdexcept>

//local
#include <utils/Utils.h>

#include "protocolGraph/operables/VariableTable.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"

#include "protocolGraph/protocolgraph_global.h"

/**
 * Represents a variable stored in the VariableTable.
 */
class VARIABLEENTRY_EXPORT VariableEntry: public MathematicOperable {
public:
    /**
     * @brief VariableEntry creates undefined variable
     */
	VariableEntry();
    /**
     * @brief VariableEntry creates a new variable entry
     * @param name name of the variable, if does not already exist on the variable table a new one is created
     * @param variableTable object where the value of this variable is stored.
     */
    VariableEntry(const std::string & name, std::shared_ptr<VariableTable> variableTable);
	/**
	 * Does not deallocates the sharedTable
	 */
	virtual ~VariableEntry() {}

	/**
	 * Returns the value from the variable table
	 * @return
	 */
	virtual double getValue() throw (std::invalid_argument);
	/**
	 * Check if the variable stores physical values
	 * @return true if the variable stores physical values, false otherwise
	 */
	virtual bool isPhysical() throw (std::invalid_argument);
    /**
     * @brief equal check if two variable entries has the same name.
     * @param obj other mathemetaic operable to check
     * @return true if both are VariableEntry and has the same name, false otherwise.
     */
	virtual bool equal(const MathematicOperable* obj) const;
	/**
	 * Sets the value of this variable at the variable table to the given value
	 * @param value
	 */
	void setValue(double value) throw (std::invalid_argument);
	/**
	 * Sets the physical flag of this variable at the variable table to the given value
	 * @param value
	 */
	void setPhysical(bool physical) throw (std::invalid_argument);
    /**
     * @brief toString returns the name of the variable
     * @return a constant reference to the name of the variable
     */
    inline virtual std::string toString() {
		return name;
	}
protected:
	/**
	 * name of the variable in the table
	 */
	std::string name;
    /**
     * @brief variableTable pointer to the variable table where this entry is stored
     */
    std::shared_ptr<VariableTable> variableTable;
};
#endif /* SRC_OPERABLES_MATHEMATICS_VARIABLEENTRY_H_ */
