/*
 * SimpleComparison.h
 *
 *  Created on: 22 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_OPERABLES_COMPARISON_SIMPLECOMPARISON_H_
#define SRC_OPERABLES_COMPARISON_SIMPLECOMPARISON_H_

//Operators string
#define LESS_EQUAL_STRING "<="
#define LESS_STRING "<"
#define GREAT_EQUAL_STRING ">="
#define GREAT_STRING ">"
#define EQUAL_STRING "="

//boost
#include <memory>
#include <functional>

//local
#include <utils/Utils.h>

#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operables/comparison/ComparisonOperable.h"

#include "protocolGraph/protocolgraph_global.h"

/**
 * Class that represents a simple comparison between two variables, for example "a > 3"
 */
class SIMPLECOMPARISON_EXPORT SimpleComparison: public ComparisonOperable {
public:

    /*** Enum for the type of comparison operator ***/
    typedef enum ComparisonOperator_ {
        less_equal, // <=
        less, // <
        greater_equal, //>=
        greater, // >
        equal // ==
    } ComparisonOperator;

	SimpleComparison() {
		this->left = std::shared_ptr<MathematicOperable>();
		this->right = std::shared_ptr<MathematicOperable>();
        this->op = less_equal;
		this->negation = false;
	}

    SimpleComparison(bool negation,
			std::shared_ptr<MathematicOperable> left,
            ComparisonOperator op,
			std::shared_ptr<MathematicOperable> right);

    virtual ~SimpleComparison();

	/**
	 * Check if the comparison is true o false
	 * @return true if the comparison is true, false otherwise
	 */
	virtual bool conditionMet();
	/**
	 * Check if the comparison used physical values
	 * @return true if the comparison uses physical values, false otherwise
	 */
	inline virtual bool isPhysical() {return (left.get()->isPhysical() || right.get()->isPhysical());}
	/**
	 * Checks if two ComparisonOperable are the same
	 * @param obj other ComparisonOperable to be compared
	 * @return true if they are the same, false otherwise
	 */
    virtual bool equals(ComparisonOperable* obj) const;

	/**
	 * negates this comparison, not(comparison)
	 */
	inline virtual void negate() {
		negation = !negation;
	}

	inline virtual std::string toString() {
		std::string neg = negation ? "!" : "";
		return  neg + left.get()->toString() + " " + getStingOp() + " " + right.get()->toString();
	}

protected:
	std::string getStingOp();
	/**
	 * Returns a function that implements the comparison op
	 * @param op the comparison operation
	 * @return a function that implements the desired comparison
	 */
    std::function<bool(double, double)> getFunctionType(ComparisonOperator op);

	//ATRIBUTES
	std::shared_ptr<MathematicOperable> left;
	std::shared_ptr<MathematicOperable> right;
    ComparisonOperator op;
	bool negation;
};
#endif /* SRC_OPERABLES_COMPARISON_SIMPLECOMPARISON_H_ */
