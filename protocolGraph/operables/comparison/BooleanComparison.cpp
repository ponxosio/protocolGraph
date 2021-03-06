/*
 * LogicalComparison.cpp
 *
 *  Created on: 22 de mar. de 2016
 *      Author: angel
 */

#include "BooleanComparison.h"

BooleanComparison::BooleanComparison() :
    ComparisonOperable()
{
    this->left = std::shared_ptr<ComparisonOperable>();
    this->right = std::shared_ptr<ComparisonOperable>();
    this->op = conjunction;
    this->negation = false;
}

BooleanComparison::BooleanComparison(const BooleanComparison & obj) :
    ComparisonOperable(obj)
{
    this->left = std::shared_ptr<ComparisonOperable>(obj.left->clone());
    this->right = std::shared_ptr<ComparisonOperable>(obj.right->clone());
    this->op = obj.op;
    this->negation = obj.negation;
}

BooleanComparison::BooleanComparison(
        bool negation,
        std::shared_ptr<ComparisonOperable> left,
        BooleanOperator op,
        std::shared_ptr<ComparisonOperable> right) :
    ComparisonOperable()
{
	this->left = left;
	this->right = right;
	this->op = op;
	this->negation = negation;
}

BooleanComparison::~BooleanComparison() {
}

bool BooleanComparison::conditionMet() const {
	bool leftValue = left.get()->conditionMet();
	bool rightValue = right.get()->conditionMet();
    std::function<bool(bool, bool)> fun = getFunctionType(op);

	bool vuelta = fun(leftValue, rightValue);
	return negation == true ? !vuelta : vuelta;
}

bool BooleanComparison::equals(ComparisonOperable* obj) const {
	bool vuelta = false;
	if (Utils::IsType<BooleanComparison, ComparisonOperable>(obj)) {
		const BooleanComparison* cast = dynamic_cast<const BooleanComparison*>(obj);
        vuelta = ((cast->left.get()->equals(this->left.get()))
                && (cast->right.get()->equals(this->right.get()))
				&& (cast->op == this->op)
				&& (cast->negation == this->negation));
	}
	return vuelta;
}

std::function<bool(bool, bool)> BooleanComparison::getFunctionType(BooleanOperator op) const {
    std::function<bool(bool, bool)> vuelta;
	switch (op) {
        case conjunction:
			vuelta = std::logical_and<bool>();
			break;
        case disjunction:
			vuelta = std::logical_or<bool>();
			break;
	}
	return vuelta;
}

std::string BooleanComparison::getStringOp() const {
	std::string vuelta;
	switch (op) {
    case conjunction:
		vuelta = CONJUNCTION_STRING;
		break;
    case disjunction:
		vuelta = DISJUNCTION_STRING;
		break;
	}
	return vuelta;
}
