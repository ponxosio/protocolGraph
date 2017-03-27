/*
 * SimpleComparison.cpp
 *
 *  Created on: 22 de mar. de 2016
 *      Author: angel
 */

#include "SimpleComparison.h"

SimpleComparison::SimpleComparison() :
    ComparisonOperable()
{
    this->left = std::shared_ptr<MathematicOperable>();
    this->right = std::shared_ptr<MathematicOperable>();
    this->op = less_equal;
    this->negation = false;
}

SimpleComparison::SimpleComparison(const SimpleComparison & obj) :
    ComparisonOperable(obj)
{
    this->left = obj.left;
    this->right = obj.right;
    this->op = obj.op;
    this->negation = obj.negation;
}

SimpleComparison::SimpleComparison(
        bool negation,
        std::shared_ptr<MathematicOperable> left,
        ComparisonOperator op,
        std::shared_ptr<MathematicOperable> right)
{
	this->left = left;
	this->right = right;
	this->op = op;
	this->negation = negation;
}

SimpleComparison::~SimpleComparison() {
	// TODO Auto-generated destructor stub
}

bool SimpleComparison::conditionMet() const {
	double leftValue = left.get()->getValue();
	double rightValue = right.get()->getValue();
    std::function<bool(double, double)> fun = getFunctionType(op);

	bool vuelta = fun(leftValue, rightValue);
	return negation ? !vuelta : vuelta;
}

bool SimpleComparison::equals(ComparisonOperable* obj) const {
	bool vuelta = false;
	if (Utils::IsType<SimpleComparison, ComparisonOperable>(obj)) {
		const SimpleComparison* cast = dynamic_cast<const SimpleComparison*>(obj);
		vuelta = ((cast->left.get()->equal(this->left.get()))
				&& (cast->right.get()->equal(this->right.get()))
				&& (cast->op == this->op)
				&& (cast->negation == this->negation));
	}
	return vuelta;
}

std::function<bool(double, double)> SimpleComparison::getFunctionType(ComparisonOperator op) const {
    std::function<bool(double, double)> vuelta;
	switch (op) {
    case less_equal:
		vuelta = std::less_equal<double>();
		break;
    case less:
		vuelta = std::less<double>();
		break;
    case greater_equal:
		vuelta = std::greater_equal<double>();
		break;
    case greater:
		vuelta = std::greater<double>();
		break;
    case equal:
		vuelta = std::equal_to<double>();
	}
	return vuelta;
}

std::string SimpleComparison::getStingOp() const {
	std::string vuelta;
	switch (op) {
    case less_equal:
		vuelta = LESS_EQUAL_STRING;
		break;
    case less:
		vuelta = LESS_STRING;
		break;
    case greater_equal:
		vuelta = GREAT_EQUAL_STRING;
		break;
    case greater:
		vuelta = GREAT_STRING;
		break;
    case equal:
		vuelta = EQUAL_STRING;
	}
	return vuelta;
}
