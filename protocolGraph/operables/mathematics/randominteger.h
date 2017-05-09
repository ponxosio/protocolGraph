#ifndef RANDOMINTEGER_H
#define RANDOMINTEGER_H

#include <memory>
#include <random>
#include <string>

//local
#include <utils/Utils.h>
#include "protocolGraph/operables/mathematics/ConstantNumber.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"

#include "protocolGraph/protocolgraph_global.h"

class RANDOMINTEGER_EXPORT RandomInteger : public MathematicOperable
{
public:
    RandomInteger();
    RandomInteger(const RandomInteger & cn);
    RandomInteger(std::shared_ptr<MathematicOperable> initNumber, std::shared_ptr<MathematicOperable> endNumber);
    virtual ~RandomInteger();

    virtual bool equal ( const MathematicOperable* obj ) const;
    virtual double getValue() const;

    inline virtual bool isPhysical() const {
        return false;
    }

    inline virtual std::string toString() const {
        return "rand(" + (initNumber ? initNumber->toString() : "?") + "," + (endNumber ? endNumber->toString() : "?") + ")";
    }

    inline virtual MathematicOperable* clone() const {
        return new RandomInteger(*this);
    }
 protected:
    static std::default_random_engine engine;

    std::shared_ptr<MathematicOperable> initNumber;
    std::shared_ptr<MathematicOperable> endNumber;
    std::uniform_int_distribution<long> distribution;
};

#endif // RANDOMINTEGER_H
