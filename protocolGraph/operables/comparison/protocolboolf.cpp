#include "protocolboolf.h"

std::shared_ptr<ComparisonOperable> ProtocolBoolF::tautology() {
    return std::make_shared<Tautology>();
}

std::shared_ptr<ComparisonOperable> ProtocolBoolF::contradiction() {
    std::shared_ptr<ComparisonOperable> tau = tautology();
    tau->negate();
    return tau;
}

std::shared_ptr<ComparisonOperable> ProtocolBoolF::equal(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    return std::make_shared<SimpleComparison>(false, op1, SimpleComparison::equal, op2);
}

std::shared_ptr<ComparisonOperable> ProtocolBoolF::less(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    return std::make_shared<SimpleComparison>(false, op1, SimpleComparison::less, op2);
}

std::shared_ptr<ComparisonOperable> ProtocolBoolF::lessEq(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    return std::make_shared<SimpleComparison>(false, op1, SimpleComparison::less_equal, op2);
}

std::shared_ptr<ComparisonOperable> ProtocolBoolF::big(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    return std::make_shared<SimpleComparison>(false, op1, SimpleComparison::greater, op2);
}

std::shared_ptr<ComparisonOperable> ProtocolBoolF::bigEq(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    return std::make_shared<SimpleComparison>(false, op1, SimpleComparison::greater_equal, op2);
}

std::shared_ptr<ComparisonOperable> ProtocolBoolF::makeAnd(std::shared_ptr<ComparisonOperable> op1, std::shared_ptr<ComparisonOperable> op2) {
    return std::make_shared<BooleanComparison>(false, op1, BooleanComparison::conjunction, op2);
}

std::shared_ptr<ComparisonOperable> ProtocolBoolF::makeOr(std::shared_ptr<ComparisonOperable> op1, std::shared_ptr<ComparisonOperable> op2) {
    return std::make_shared<BooleanComparison>(false, op1, BooleanComparison::disjunction, op2);
}

std::shared_ptr<ComparisonOperable> ProtocolBoolF::makeNot(std::shared_ptr<ComparisonOperable> op) {
    std::shared_ptr<ComparisonOperable> newCopy(op->clone());
    newCopy->negate();
    return newCopy;
}
