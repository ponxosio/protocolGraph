#ifndef TESTOPERATION_H
#define TESTOPERATION_H

#include <memory>

//local
#include <utils/Utils.h>
#include "protocolGraph/operables/comparison/ComparisonOperable.h"
#include "protocolGraph/operables/comparison/Tautology.h"
#include "protocolGraph/operables/mathematics/ConstantNumber.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"

#include "protocolGraph/protocolgraph_global.h"

class TESTOPERATION_EXPORT TestOperation : public MathematicOperable
{
public:
    TestOperation();
    TestOperation(const TestOperation & aop);
    TestOperation(std::shared_ptr<ComparisonOperable> condition,
                  std::shared_ptr<MathematicOperable> trueValue,
                  std::shared_ptr<MathematicOperable> falseValue);

    virtual ~TestOperation();

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
        return (trueValue->isPhysical() || falseValue->isPhysical());
    }

    inline virtual  std::string toString() const {
        return (condition ? condition->toString() : "null") + " ? "
                           + (trueValue ? trueValue->toString() : "null")
                           + " : "
                           + (falseValue ? falseValue->toString() :  "null");
    }

    inline virtual MathematicOperable* clone() const {
        return new TestOperation(*this);
    }

protected:
    std::shared_ptr<ComparisonOperable> condition;
    std::shared_ptr<MathematicOperable> trueValue;
    std::shared_ptr<MathematicOperable> falseValue;
};

#endif // TESTOPERATION_H
