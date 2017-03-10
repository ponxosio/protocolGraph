/*
 * LogicalComparison.h
 *
 *  Created on: 22 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_OPERABLES_COMPARISON_BOOLEANCOMPARISON_H_
#define SRC_OPERABLES_COMPARISON_BOOLEANCOMPARISON_H_

#pragma warning( disable : 4290 )

//string operations
#define CONJUNCTION_STRING "&&"
#define DISJUNCTION_STRING "||"

//boost
#include <functional>
#include <memory>

//local
#include <utils/Utils.h>

#include "protocolGraph/operables/comparison/ComparisonOperable.h"

#include "protocolGraph/protocolgraph_global.h"

/**
 * Class that represent a boolean operation between simple comparisons, for example: (t > 3) && (t < 5)
 */
class BOOLEANCOMPARISON_EXPORT BooleanComparison: public ComparisonOperable {
public:

    /*** Enum for the type of boolean operator ***/
    typedef enum BooleanOperator_ {
        conjunction, // and
        disjunction, // or
    } BooleanOperator;

	BooleanComparison() {
		this->left = std::shared_ptr<ComparisonOperable>();
		this->right = std::shared_ptr<ComparisonOperable>();
        this->op = conjunction;
		this->negation = false;
	}
	BooleanComparison(bool negation,
			std::shared_ptr<ComparisonOperable> left,
            BooleanOperator op,
			std::shared_ptr<ComparisonOperable> right);
	virtual ~BooleanComparison();

	/**
	 * Check if the comparison is true o false
	 * @return true if the comparison is true, false otherwise
	 */
	virtual bool conditionMet();
	/**
	 * Check if the comparison used physical values
	 * @return true if the comparison uses physical values, false otherwise
	 */
	inline virtual bool isPhysical() {
		return (left.get()->isPhysical() || right.get()->isPhysical());
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

	inline virtual std::string toString() {
		std::string neg = negation ? "!" : "";
		return neg + left.get()->toString() + " " + getStringOp() + " " + right.get()->toString();
	}

protected:
	std::string getStringOp();
	/**
	 * Returns a function that implements the boolean operator op
	 * @param op the boolean operation
	 * @return a function that implements the desired operation
	 */
    std::function<bool(bool, bool)> getFunctionType(BooleanOperator op);

	//ATTRIBUTES
	std::shared_ptr<ComparisonOperable> left;
	std::shared_ptr<ComparisonOperable> right;
    BooleanOperator op;
	bool negation;
};
#endif /* SRC_OPERABLES_COMPARISON_BOOLEANCOMPARISON_H_ */
