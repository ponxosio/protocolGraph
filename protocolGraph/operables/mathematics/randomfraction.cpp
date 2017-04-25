#include "randomfraction.h"

std::default_random_engine RandomFraction::engine ;
std::uniform_real_distribution<double> RandomFraction::distribution(0.0, 1.0);

RandomFraction::RandomFraction() :
    MathematicOperable()
{

}

RandomFraction::RandomFraction(const RandomFraction & cn) :
    MathematicOperable(cn)
{

}

RandomFraction::~RandomFraction() {

}

bool RandomFraction::equal( const MathematicOperable* obj ) const {
    return (Utils::IsType<RandomFraction, MathematicOperable>(obj));
}

double RandomFraction::getValue() const {
    return distribution(engine);
}
