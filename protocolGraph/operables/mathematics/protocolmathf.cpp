#include "protocolmathf.h"

std::shared_ptr<MathematicOperable> ProtocolMathF::add(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::plus, op2);
}

std::shared_ptr<MathematicOperable> ProtocolMathF::minus(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::minus, op2);
}

std::shared_ptr<MathematicOperable> ProtocolMathF::multiply(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::multiply, op2);
}

std::shared_ptr<MathematicOperable> ProtocolMathF::divide(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::divide, op2);
}

std::shared_ptr<MathematicOperable> ProtocolMathF::abs(std::shared_ptr<MathematicOperable> op) {
    return std::make_shared<UnaryOperation>(op, UnaryOperation::absoluteValue);
}

std::shared_ptr<MathematicOperable> ProtocolMathF::floor(std::shared_ptr<MathematicOperable> op) {
    return std::make_shared<UnaryOperation>(op, UnaryOperation::floor);
}

std::shared_ptr<MathematicOperable> ProtocolMathF::getNum(double value) {
    return std::make_shared<ConstantNumber>(value);
}
