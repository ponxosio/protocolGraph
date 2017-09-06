/*
 * ConstantNumber.cpp
 *
 *  Created on: 15 de mar. de 2016
 *      Author: angel
 */

#include "../mathematics/ConstantNumber.h"

const double ConstantNumber::INFINITE  = std::numeric_limits<double>::max();
const double ConstantNumber::M_INFINITE  = std::numeric_limits<double>::min();

std::shared_ptr<ConstantNumber> ConstantNumber::getInfinite() {
    return std::make_shared<ConstantNumber>(INFINITE);
}

ConstantNumber::ConstantNumber() {
	this->value = -1.0;
}

ConstantNumber::ConstantNumber(const ConstantNumber & cn) {
    this->value = cn.value;
}

ConstantNumber::ConstantNumber(int value) {
	this->value = value;
}

ConstantNumber::ConstantNumber(double value) {
	this->value = value;
}

bool ConstantNumber::equal(const MathematicOperable* obj) const {
	bool vuelta = false;
	if (Utils::IsType<ConstantNumber, MathematicOperable>(obj)) {
		const ConstantNumber* cast = dynamic_cast<const ConstantNumber*>(obj);
		vuelta = (cast->value == this->value);
	}
	return vuelta;
}
