#ifndef ARITHMETICARRAYOPERATION_H
#define ARITHMETICARRAYOPERATION_H

#include <memory>
#include <string>

//local
#include <utils/Utils.h>
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operables/mathematics/ConstantNumber.h"

#include "protocolGraph/protocolgraph_global.h"

class ArithmeticArrayOperation : public MathematicOperable
{
public:
    /**
     * Enum for the type of arithmetic operator
     */
    typedef enum ArithmeticArrayOperator_ {
        plus, // +
        minus, // -
        multiply, // *
        max,
        min
    } ArithmeticArrayOperator;

    ArithmeticArrayOperation();
    ArithmeticArrayOperation(const ArithmeticArrayOperation & aop);
    ArithmeticArrayOperation(const std::vector<std::shared_ptr<MathematicOperable>> & array, ArithmeticArrayOperator op);

    virtual ~ArithmeticArrayOperation();

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
    virtual bool isPhysical() const throw (std::invalid_argument);
    virtual  std::string toString() const;

    inline virtual MathematicOperable* clone() const {
        return new ArithmeticArrayOperation(*this);
    }

protected:
    static const std::string PLUS_STRING_SRC;
    static const std::string MINUS_STRING_SRC;
    static const std::string MULTIPLY_STRING_SRC;
    static const std::string MAX_STRING_SRC;
    static const std::string MIN_STRING_SRC;

    //Attributes
    /**
     * Variable on the left of the operation
     */
    std::vector<std::shared_ptr<MathematicOperable>> array;
    /**
     * Operator between variables
     */
    ArithmeticArrayOperator op;

    std::string getStringOp() const;
};

#endif // ARITHMETICARRAYOPERATION_H
