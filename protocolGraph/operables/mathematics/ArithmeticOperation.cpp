/*
 * AritmeticOperation.cpp
 *
 *  Created on: 21 de mar. de 2016
 *      Author: angel
 */

#include "ArithmeticOperation.h"

ArithmeticOperation::ArithmeticOperation() {
	this->leftVariable = shared_ptr<MathematicOperable>();
	this->rightVariable = shared_ptr<MathematicOperable>();
    this->op = plus;
}

ArithmeticOperation::ArithmeticOperation(
		std::shared_ptr<MathematicOperable> left,
        ArithmeticOperator op,
        std::shared_ptr<MathematicOperable> right)
{
	this->leftVariable = left;
	this->rightVariable = right;
	this->op = op;
}

ArithmeticOperation::~ArithmeticOperation() {

}

double ArithmeticOperation::getValue() throw (std::invalid_argument)  {
	MathematicOperable* left = leftVariable.get();
	MathematicOperable* right = rightVariable.get();
    std::function<double(double, double)> op = getFunctionType(this->op);

	return (op(left->getValue(), right->getValue()));
}

bool ArithmeticOperation::equal(const MathematicOperable* obj) const {
	bool vuelta = false;
	if (Utils::IsType<ArithmeticOperation, MathematicOperable>(obj)) {
		const ArithmeticOperation* cast = dynamic_cast<const ArithmeticOperation*>(obj);
		vuelta = ((this->leftVariable.get()->equal(cast->leftVariable.get()))
				&& (this->rightVariable.get()->equal(cast->rightVariable.get()))
				&& (this->op == cast->op));
	}
	return vuelta;
}

std::function<double(double, double)> ArithmeticOperation::getFunctionType(ArithmeticOperator op) {
    std::function<double(double, double)> vuelta;
	switch (op) {
    case plus:
		vuelta = std::plus<double>();
		break;
    case minus:
		vuelta = std::minus<double>();
		break;
    case multiply:
		vuelta = std::multiplies<double>();
		break;
    case divide:
		vuelta = std::divides<double>();
		break;
	}
	return vuelta;
}

std::string ArithmeticOperation::getStringOp() {
	std::string vuelta;
		switch (op) {
        case plus:
			vuelta = PLUS_STRING;
			break;
        case minus:
			vuelta = MINUS_STRING;
			break;
        case multiply:
			vuelta = MULTIPLY_STRING;
			break;
        case divide:
			vuelta = DIVIDE_STRING;
			break;
		}
		return vuelta;
}
