#ifndef CHARACTERISTICCHECK_H
#define CHARACTERISTICCHECK_H

#define ODD_STR "isOdd";
#define EVEN_STR "isEven";
#define PRIME_STR "isPrime";
#define WHOLE_STR "isWhole";
#define POSITIVE_STR "isPositive";
#define NEGATIVE_STR "isNegative";

#include <memory>

//local
#include <utils/Utils.h>

#include "protocolGraph/operables/comparison/ComparisonOperable.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"

#include "protocolGraph/protocolgraph_global.h"

class CHARACTERISTICCHECK_EXPORT CharacteristicCheck : public ComparisonOperable
{
public:

    /*** Enum for the type of boolean operator ***/
    typedef enum CheckOperations_ {
        odd, // odd
        even, // even
        prime, //prime
        whole, //whole
        positive, //positive
        negative //negative
    } CheckOperations;

    CharacteristicCheck();
    CharacteristicCheck(const CharacteristicCheck & obj);
    CharacteristicCheck(bool negation,
                        std::shared_ptr<MathematicOperable> value,
                        CheckOperations op);
    virtual ~CharacteristicCheck();

    /**
     * Check if the comparison is true o false
     * @return true if the comparison is true, false otherwise
     */
    virtual bool conditionMet() const;
    /**
     * Check if the comparison used physical values
     * @return true if the comparison uses physical values, false otherwise
     */
    inline virtual bool isPhysical() const {
        return (value->isPhysical());
    }
    /**
     * Checks if two ComparisonOperable are the same
     * @param obj other ComparisonOperable to be compared
     * @return true if they are the same, false otherwise
     */
    virtual bool equals(ComparisonOperable* obj) const;

    /**
     * negates this comparison, not(comparison)
     */
    inline virtual void negate() {negation = !negation;}

    inline virtual std::string toString() const {
        std::string neg = negation ? "!" : "";
        return neg + getStringOp() + "(" + value->toString() + ")";
    }

    inline virtual ComparisonOperable* clone() const {
        return new CharacteristicCheck(*this);
    }

protected:
    std::string getStringOp() const;

    //ATTRIBUTES
    std::shared_ptr<MathematicOperable> value;
    CheckOperations op;
    bool negation;
};

#endif // CHARACTERISTICCHECK_H
