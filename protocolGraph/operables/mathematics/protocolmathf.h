#ifndef PROTOCOLMATHF_H
#define PROTOCOLMATHF_H

#include "protocolGraph/operables/mathematics/ArithmeticOperation.h"
#include "protocolGraph/operables/mathematics/ConstantNumber.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operables/mathematics/UnaryOperation.h"

#include "protocolGraph/protocolgraph_global.h"

class PROTOCOLMATHF_EXPORT ProtocolMathF
{
public:
    static std::shared_ptr<MathematicOperable> add(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<MathematicOperable> minus(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<MathematicOperable> multiply(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<MathematicOperable> divide(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);

    static std::shared_ptr<MathematicOperable> abs(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> floor(std::shared_ptr<MathematicOperable> op);

    static std::shared_ptr<MathematicOperable> getNum(double value);
};

#endif // PROTOCOLMATHF_H
