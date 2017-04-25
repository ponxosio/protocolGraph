#include "randominteger.h"

std::default_random_engine RandomInteger::engine;

RandomInteger::RandomInteger() :
    MathematicOperable(), distribution(0,0)
{
    initNumber = std::make_shared<ConstantNumber>(0.0);
    endNumber = std::make_shared<ConstantNumber>(0.0);
}

RandomInteger::RandomInteger(const RandomInteger & cn) :
    MathematicOperable(cn), distribution(cn.distribution.param())
{
    initNumber = cn.initNumber;
    endNumber = cn.endNumber;
}

RandomInteger::RandomInteger(std::shared_ptr<MathematicOperable> initNumber, std::shared_ptr<MathematicOperable> endNumber) :
    MathematicOperable(), distribution((int)std::floor(initNumber->getValue()), (int)std::floor(endNumber->getValue()))
{
    this->initNumber = initNumber;
    this->endNumber = endNumber;
}

RandomInteger::~RandomInteger() {

}

bool RandomInteger::equal ( const MathematicOperable* obj ) const {
    bool vuelta = false;
    if (Utils::IsType<RandomInteger, MathematicOperable>(obj)) {
        const RandomInteger* cast = dynamic_cast<const RandomInteger*>(obj);
        vuelta = ((this->initNumber->equal(cast->initNumber.get()))
                && (this->endNumber->equal(cast->endNumber.get())));
    }
    return vuelta;
}

double RandomInteger::getValue() const {
    return distribution(engine);
}
