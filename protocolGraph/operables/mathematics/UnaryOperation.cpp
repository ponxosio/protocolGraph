/*
 * UnaryOperation.cpp
 *
 *  Created on: 4 de abr. de 2016
 *      Author: angel
 */

#include "UnaryOperation.h"

ProtocolUnaryOperation::ProtocolUnaryOperation() {
	this->variable = shared_ptr<MathematicOperable>();
    this->op = absoluteValue;
}

ProtocolUnaryOperation::ProtocolUnaryOperation(const ProtocolUnaryOperation & uop) {
    this->variable = uop.variable;
    this->op = uop.op;
}

ProtocolUnaryOperation::ProtocolUnaryOperation(std::shared_ptr<MathematicOperable> variable, UnaryOperator op) {
	this->variable = variable;
	this->op = op;
}

ProtocolUnaryOperation::~ProtocolUnaryOperation() 
{

}

double ProtocolUnaryOperation::getValue() const throw (std::invalid_argument)  {
	MathematicOperable* value = variable.get();

    double vuelta = 0.0;
    if (value->getValue() == ConstantNumber::INFINITE) {
        vuelta = ConstantNumber::INFINITE;
    } else {
        switch(this->op) {
        case UnaryOperator::absoluteValue:
            vuelta = std::fabs(value->getValue());
            break;
        case UnaryOperator::floor:
            vuelta = std::floor(value->getValue());
            break;
        case UnaryOperator::round:
            vuelta = std::round(value->getValue());
            break;
        case UnaryOperator::ceiling:
            vuelta = std::ceil(value->getValue());
            break;
        case UnaryOperator::sqrt:
            vuelta = std::sqrt(value->getValue());
            break;
        case UnaryOperator::ln:
            vuelta = std::log(value->getValue());
            break;
        case UnaryOperator::log10:
            vuelta = std::log10(value->getValue());
            break;
        case UnaryOperator::exp_e:
            vuelta = std::exp(value->getValue());
            break;
        case UnaryOperator::exp_10:
            vuelta = std::pow(value->getValue(), 10);
            break;
        case UnaryOperator::minus:
            vuelta = -1.0 * value->getValue();
            break;
        case UnaryOperator::sin_op:
            vuelta = std::sin(value->getValue());
            break;
        case UnaryOperator::cos_op:
            vuelta = std::cos(value->getValue());
            break;
        case UnaryOperator::tan_op:
            vuelta = std::tan(value->getValue());
            break;
        case UnaryOperator::asin_op:
            vuelta = std::asin(value->getValue());
            break;
        case UnaryOperator::acos_op:
            vuelta = std::acos(value->getValue());
            break;
        case UnaryOperator::atan_op:
            vuelta = std::atan(value->getValue());
            break;
        }
    }
	return vuelta;
}

bool ProtocolUnaryOperation::isPhysical() const throw (std::invalid_argument) {
	return (variable.get()->isPhysical());
}

bool ProtocolUnaryOperation::equal(const MathematicOperable* obj) const {
	bool vuelta = false;
	if (Utils::IsType<ProtocolUnaryOperation, MathematicOperable>(obj)) {
		const ProtocolUnaryOperation* cast = dynamic_cast<const ProtocolUnaryOperation*>(obj);
		vuelta = ((this->variable.get()->equal(cast->variable.get()))
				&& (this->op == cast->op));
	}
	return vuelta;
}

std::string ProtocolUnaryOperation::getStringOp() const{
	std::string vuelta;
	switch (this->op) {
    case UnaryOperator::absoluteValue:
		vuelta = ABSOLUTE_VALUE_STRING;
		break;
    case UnaryOperator::floor:
		vuelta = FLOOR_VALUE_STRING;
		break;
    case UnaryOperator::round:
        vuelta = ROUND_VALUE_STRING;
        break;
    case UnaryOperator::ceiling:
        vuelta = CEILING_VALUE_STRING;
        break;
    case UnaryOperator::sqrt:
        vuelta = SQRT_VALUE_STRING;
        break;
    case UnaryOperator::ln:
        vuelta = LN_VALUE_STRING;
        break;
    case UnaryOperator::log10:
        vuelta = LOG10_VALUE_STRING;
        break;
    case UnaryOperator::exp_e:
        vuelta = EXP_E_VALUE_STRING;
        break;
    case UnaryOperator::exp_10:
        vuelta = EXP_10_VALUE_STRING;
        break;
    case UnaryOperator::minus:
        vuelta = MINUS_VALUE_STRING;
        break;
    case UnaryOperator::sin_op:
        vuelta = SIN_VALUE_STRING;
        break;
    case UnaryOperator::cos_op:
        vuelta = COS_VALUE_STRING;
        break;
    case UnaryOperator::tan_op:
        vuelta = TAN_VALUE_STRING;
        break;
    case UnaryOperator::asin_op:
        vuelta = ASIN_VALUE_STRING;
        break;
    case UnaryOperator::acos_op:
        vuelta = ACOS_VALUE_STRING;
        break;
    case UnaryOperator::atan_op:
        vuelta = ATAN_VALUE_STRING;
        break;
	}
	return vuelta;
}
