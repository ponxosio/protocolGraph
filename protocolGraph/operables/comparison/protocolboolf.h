#ifndef PROTOCOLBOOLF_H
#define PROTOCOLBOOLF_H

#include "protocolGraph/operables/comparison/BooleanComparison.h"
#include "protocolGraph/operables/comparison/ComparisonOperable.h"
#include "protocolGraph/operables/comparison/SimpleComparison.h"
#include "protocolGraph/operables/comparison/Tautology.h"

#include "protocolGraph/operables/mathematics/MathematicOperable.h"

#include "protocolGraph/protocolgraph_global.h"

class PROTOCOLBOOLF_EXPORT ProtocolBoolF
{
public:
    static std::shared_ptr<ComparisonOperable> tautology();
    static std::shared_ptr<ComparisonOperable> contradiction();

    static std::shared_ptr<ComparisonOperable> equal(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<ComparisonOperable> less(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<ComparisonOperable> lessEq(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<ComparisonOperable> big(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);
    static std::shared_ptr<ComparisonOperable> bigEq(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2);

    static std::shared_ptr<ComparisonOperable> makeAnd(std::shared_ptr<ComparisonOperable> op1, std::shared_ptr<ComparisonOperable> op2);
    static std::shared_ptr<ComparisonOperable> makeOr(std::shared_ptr<ComparisonOperable> op1, std::shared_ptr<ComparisonOperable> op2);
    static std::shared_ptr<ComparisonOperable> makeNot(std::shared_ptr<ComparisonOperable> op);
};

#endif // PROTOCOLBOOLF_H
