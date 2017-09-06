/*
 * ConstantNumber.h
 *
 *  Created on: 15 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_OPERABLES_MATHEMATICS_CONSTANTNUMBER_H_
#define SRC_OPERABLES_MATHEMATICS_CONSTANTNUMBER_H_

#include <limits>
#include <memory>
#include <string>

#include <utils/Utils.h>

#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/protocolgraph_global.h"

/**
 * Represents a constant number.
 */
class CONSTANTNUMBER_EXPORT ConstantNumber: public MathematicOperable {
public:
    static const double INFINITE;
    static const double M_INFINITE;
    static std::shared_ptr<ConstantNumber> getInfinite();

	ConstantNumber();
    ConstantNumber(const ConstantNumber & cn);
	ConstantNumber(int value);
	ConstantNumber(double value);
    virtual ~ConstantNumber(){}

	virtual bool equal ( const MathematicOperable* obj ) const;

    inline virtual double getValue() const {
        return value;
    }

    inline virtual bool isPhysical() const {
        return false;
    }

    inline virtual std::string toString() const {
        return value == INFINITE ? "Infinite" : std::to_string(value);
	}

    inline virtual MathematicOperable* clone() const {
        return new ConstantNumber(*this);
    }
protected:
	double value;
};
#endif /* SRC_OPERABLES_MATHEMATICS_CONSTANTNUMBER_H_ */
