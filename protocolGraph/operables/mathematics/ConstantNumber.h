/*
 * ConstantNumber.h
 *
 *  Created on: 15 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_OPERABLES_MATHEMATICS_CONSTANTNUMBER_H_
#define SRC_OPERABLES_MATHEMATICS_CONSTANTNUMBER_H_

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
	ConstantNumber();
	ConstantNumber(int value);
	ConstantNumber(double value);
    virtual ~ConstantNumber(){}

	virtual double getValue();
	virtual bool equal ( const MathematicOperable* obj ) const;

	inline virtual bool isPhysical() {return false;}

	inline virtual std::string toString() {
        return std::to_string(value);
	}
protected:
	double value;
};
#endif /* SRC_OPERABLES_MATHEMATICS_CONSTANTNUMBER_H_ */
