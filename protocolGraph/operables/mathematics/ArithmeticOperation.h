/*
 * AritmeticOperation.h
 *
 *  Created on: 21 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_OPERABLES_MATHEMATICS_ARITHMETICOPERATION_H_
#define SRC_OPERABLES_MATHEMATICS_ARITHMETICOPERATION_H_

#pragma warning( disable : 4290 )

//operators strings
#define PLUS_STRING "+"
#define MINUS_STRING "-"
#define MULTIPLY_STRING "*"
#define DIVIDE_STRING "/"
#define MODULE_STRING "%"
#define MAX_STRING "max"
#define MIN_STRING "min"
#define POWER_STRING "power"

#include <memory>

//local
#include <utils/Utils.h>
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operables/mathematics/ConstantNumber.h"

#include "protocolGraph/protocolgraph_global.h"

/**
 * Class that represents an arithmetic operation between two MathematicVariable s, operator available are + - * \
 */
class ARITHMETICOPERATION_EXPORT ArithmeticOperation: public MathematicOperable {

public:
    /**
     * Enum for the type of arithmetic operator
     */
    typedef enum ArithmeticOperator_ {
        plus, // +
        minus, // -
        multiply, // *
        divide, // /
        module, // %
        power, // ^
        max,
        min
    } ArithmeticOperator;

	ArithmeticOperation();
    ArithmeticOperation(const ArithmeticOperation & aop);
    ArithmeticOperation(std::shared_ptr<MathematicOperable> left,
                        ArithmeticOperator op,
                        std::shared_ptr<MathematicOperable> right);

	virtual ~ArithmeticOperation();

	/**
	 * Returns the numeric value of the variable, resulting from the mathematical operation
	 * @return the numeric value of the variable
	 */
    virtual double getValue() const throw (std::invalid_argument);

	/**
	 * Compares two Objects implementing this interface
	 * @param obj other object to be compared to
	 * @return true if both are the same, false otherwise.
	 */
	virtual bool equal(const MathematicOperable* obj) const;

    inline virtual bool isPhysical() const throw (std::invalid_argument) {
        return (leftVariable.get()->isPhysical() || rightVariable.get()->isPhysical());
    }

    inline virtual  std::string toString() const {
		return leftVariable.get()->toString() + " " + getStringOp() + " " + rightVariable.get()->toString();
	}

    inline virtual MathematicOperable* clone() const {
        return new ArithmeticOperation(*this);
    }

protected:
	//Attributes
	/**
	 * Variable on the left of the operation
	 */
	std::shared_ptr<MathematicOperable> leftVariable;
	/**
	 * Variable on the right of the operation
	 */
	std::shared_ptr<MathematicOperable> rightVariable;
	/**
	 * Operator between variables
	 */
    ArithmeticOperator op;

    std::string getStringOp() const;
};
#endif /* SRC_OPERABLES_MATHEMATICS_ARITHMETICOPERATION_H_ */
