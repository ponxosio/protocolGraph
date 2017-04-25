#ifndef RANDOMFRACTION_H
#define RANDOMFRACTION_H

#include <memory>
#include <random>
#include <string>

//local
#include <utils/Utils.h>
#include "protocolGraph/operables/mathematics/MathematicOperable.h"

#include "protocolGraph/protocolgraph_global.h"

class RANDOMFRACTION_EXPORT RandomFraction : public MathematicOperable
{
public:
    RandomFraction();
    RandomFraction(const RandomFraction & cn);
    virtual ~RandomFraction();

    virtual bool equal ( const MathematicOperable* obj ) const;
    virtual double getValue() const;

    inline virtual bool isPhysical() const {
        return false;
    }

    inline virtual std::string toString() const {
        return "rand()";
    }

    inline virtual MathematicOperable* clone() const {
        return new RandomFraction(*this);
    }
 protected:
    static std::default_random_engine engine;
    static std::uniform_real_distribution<double> distribution;
};

#endif // RANDOMFRACTION_H
