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
#define ROUND_VALUE_STRING "round"
#define CEILING_VALUE_STRING "ceiling"
#define SQRT_VALUE_STRING "squareRoot"
#define LN_VALUE_STRING "ln"
#define LOG10_VALUE_STRING "log10"
#define EXP_E_VALUE_STRING "e^"
#define EXP_10_VALUE_STRING "10^"
#define MINUS_VALUE_STRING "-"
#define SIN_VALUE_STRING "sin"
#define COS_VALUE_STRING "cos"
#define TAN_VALUE_STRING "tan"
#define ASIN_VALUE_STRING "asin"
#define ACOS_VALUE_STRING "acos"
#define ATAN_VALUE_STRING "atan"

//boost
#include <memory>
#include <cmath>

//local
#include <utils/Utils.h>

#include "protocolGraph/operables/mathematics/ConstantNumber.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"

#include "protocolGraph/protocolgraph_global.h"

class UNARYOPERATION_EXPORT ProtocolUnaryOperation: public MathematicOperable {
public:
    /*** Enum for the type of unary operator ***/
    typedef enum UnaryOperator_ {
        absoluteValue, //abs()
        floor,
        round,
        ceiling,
        sqrt, //square root
        ln, //natural logarithm
        log10, //logarithm base 10
        exp_e, //e^
        exp_10, // 10^
        minus, // -
        sin_op,
        cos_op,
        tan_op,
        asin_op,
        acos_op,
        atan_op
    }UnaryOperator;

    ProtocolUnaryOperation();
    ProtocolUnaryOperation(const ProtocolUnaryOperation & uop);
    ProtocolUnaryOperation(std::shared_ptr<MathematicOperable> variable, UnaryOperator op);

    virtual ~ProtocolUnaryOperation();

	/**
	 * Returns the numeric value of the variable
	 * @return the numeric value of the variable
	 */
    virtual double getValue() const throw (std::invalid_argument);
	/**
	 * Check if the variable stores physical values
	 * @return true if the variable stores physical values, false otherwise
	 */
    virtual bool isPhysical() const throw (std::invalid_argument);
	/**
	 * Compares two Objects implementing this interface
	 * @param obj other object to be compared to
	 * @return true if both are the same, false otherwise.
	 */
	virtual bool equal(const MathematicOperable* obj) const;

    inline virtual std::string toString() const {
        return getStringOp() + "(" + (variable ? variable->toString() : "?") + ")";
	}

    inline virtual MathematicOperable* clone() const {
        return new ProtocolUnaryOperation(*this);
    }
protected:
	std::shared_ptr<MathematicOperable> variable;
    UnaryOperator op;

    std::string getStringOp() const;
};
#endif /* SRC_OPERABLES_MATHEMATICS_UNARYOPERATION_H_ */
