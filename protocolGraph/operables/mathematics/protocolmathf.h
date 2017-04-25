#ifndef PROTOCOLMATHF_H
#define PROTOCOLMATHF_H

#include "protocolGraph/operables/mathematics/ArithmeticOperation.h"
#include "protocolGraph/operables/mathematics/ConstantNumber.h"
#include "protocolGraph/operables/mathematics/MathematicOperable.h"
#include "protocolGraph/operables/mathematics/UnaryOperation.h"
#include "protocolGraph/operables/mathematics/randomfraction.h"
#include "protocolGraph/operables/mathematics/randominteger.h"

#include "protocolGraph/protocolgraph_global.h"

class PROTOCOLMATHF_EXPORT ProtocolMathF
{
public:
    static std::shared_ptr<MathematicOperable> add(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<MathematicOperable> minus(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<MathematicOperable> multiply(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<MathematicOperable> divide(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<MathematicOperable> module(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);

    static std::shared_ptr<MathematicOperable> abs(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> floor(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> round(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> ceiling(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> log10(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> ln(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> exp_e(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> exp_10(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> minus(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> sin_op(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> cos_op(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> tan_op(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> asin_op(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> acos_op(std::shared_ptr<MathematicOperable> op);
    static std::shared_ptr<MathematicOperable> atan_op(std::shared_ptr<MathematicOperable> op);

    static std::shared_ptr<MathematicOperable> random();
    static std::shared_ptr<MathematicOperable> random(double op1, double op2);

    static std::shared_ptr<MathematicOperable> getNum(double value);
};

#endif // PROTOCOLMATHF_H
