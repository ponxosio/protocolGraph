/*
 * UnaryOperation.h
 *
 *  Created on: 4 de abr. de 2016
 *      Author: angel
 */

#ifndef SRC_OPERABLES_MATHEMATICS_UNARYOPERATION_H_
#define SRC_OPERABLES_MATHEMATICS_UNARYOPERATION_H_

#define ABSOLUTE_VALUE_STRING "fabs"
#define FLOOR_VALUE_STRING "floor"

//boost
#include <memory>
#include <cmath>

//local
#include <utils/Utils.h>

#include "protocolGraph/operables/mathematics/MathematicOperable.h"

#include "protocolGraph/protocolgraph_global.h"

class UNARYOPERATION_EXPORT UnaryOperation: public MathematicOperable {
public:
    /*** Enum for the type of unary operator ***/
    typedef enum UnaryOperator_ {
        absoluteValue, //abs()
        floor
    }UnaryOperator;

	UnaryOperation();
    UnaryOperation(std::shared_ptr<MathematicOperable> variable, UnaryOperator op);

	virtual ~UnaryOperation();

	/**
	 * Returns the numeric value of the variable
	 * @return the numeric value of the variable
	 */
	virtual double getValue() throw (std::invalid_argument);
	/**
	 * Check if the variable stores physical values
	 * @return true if the variable stores physical values, false otherwise
	 */
	virtual bool isPhysical() throw (std::invalid_argument);
	/**
	 * Compares two Objects implementing this interface
	 * @param obj other object to be compared to
	 * @return true if both are the same, false otherwise.
	 */
	virtual bool equal(const MathematicOperable* obj) const;

	inline virtual std::string toString() {
		return getStringOp() + "(" + variable.get()->toString() + ")";
	}
protected:
	std::shared_ptr<MathematicOperable> variable;
    UnaryOperator op;

	std::string getStringOp();
};
#endif /* SRC_OPERABLES_MATHEMATICS_UNARYOPERATION_H_ */
