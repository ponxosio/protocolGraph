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

ArithmeticOperation::ArithmeticOperation(const ArithmeticOperation & aop) {
    this->leftVariable = aop.leftVariable;
    this->rightVariable = aop.rightVariable;
    this->op = aop.op;
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

double ArithmeticOperation::getValue() const throw (std::invalid_argument)  {
	MathematicOperable* left = leftVariable.get();
	MathematicOperable* right = rightVariable.get();

    double vuelta = 0.0;
    switch (op) {
    case plus:
        vuelta = left->getValue() + right->getValue();
        break;
    case minus:
        vuelta = left->getValue() - right->getValue();
        break;
    case multiply:
        vuelta = left->getValue() * right->getValue();
        break;
    case divide:
        vuelta = left->getValue() / right->getValue();
        break;
    case module:
        vuelta = std::fmod(left->getValue(), right->getValue());
        break;
    case max:
        vuelta = std::max(left->getValue(), right->getValue());
        break;
    case min:
        vuelta = std::min(left->getValue(), right->getValue());
        break;
    case power:
        vuelta = std::pow(left->getValue(), right->getValue());
        break;
    }
    return vuelta;
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

std::string ArithmeticOperation::getStringOp() const {
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
        case module:
            vuelta = MODULE_STRING;
            break;
        case max:
            vuelta = MAX_STRING;
            break;
        case min:
            vuelta = MIN_STRING;
            break;
        case power:
            vuelta = POWER_STRING;
            break;
		}
		return vuelta;
}
