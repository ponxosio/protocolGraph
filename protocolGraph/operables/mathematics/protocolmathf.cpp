#include "protocolmathf.h"

std::shared_ptr<MathematicOperable> ProtocolMathF::add(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    if (op1 == NULL) {
        return op2;
    } else if (op2 == NULL) {
        return op1;
    } else {
        return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::plus, op2);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::minus(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    if (op1 == NULL) {
        return op2;
    } else if (op2 == NULL) {
        return op1;
    } else {
        return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::minus, op2);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::multiply(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    if (op1 == NULL) {
        return op2;
    } else if (op2 == NULL) {
        return op1;
    } else {
        return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::multiply, op2);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::divide(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    if (op1 == NULL) {
        return op2;
    } else if (op2 == NULL) {
        return op1;
    } else {
        return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::divide, op2);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::module(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    if (op1 == NULL) {
        return op2;
    } else if (op2 == NULL) {
        return op1;
    } else {
        return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::module, op2);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::min(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    if (op1 == NULL) {
        return op2;
    } else if (op2 == NULL) {
        return op1;
    } else {
        return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::min, op2);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::max(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    if (op1 == NULL) {
        return op2;
    } else if (op2 == NULL) {
        return op1;
    } else {
        return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::max, op2);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::pow(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    if (op1 == NULL) {
        return op2;
    } else if (op2 == NULL) {
        return op1;
    } else {
        return std::make_shared<ArithmeticOperation>(op1, ArithmeticOperation::power, op2);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::abs(std::shared_ptr<MathematicOperable> op) {
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::absoluteValue);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::floor(std::shared_ptr<MathematicOperable> op) {
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::floor);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::round(std::shared_ptr<MathematicOperable> op) {
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::round);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::ceiling(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::ceiling);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::log10(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::log10);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::ln(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::ln);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::exp_e(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::exp_e);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::exp_10(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::exp_10);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::minus(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::minus);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::sin_op(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::sin_op);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::cos_op(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::cos_op);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::tan_op(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::tan_op);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::asin_op(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::asin_op);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::acos_op(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::acos_op);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::atan_op(std::shared_ptr<MathematicOperable> op){
    if (op == NULL) {
        return NULL;
    } else {
        return std::make_shared<ProtocolUnaryOperation>(op, ProtocolUnaryOperation::atan_op);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::random() {
    return std::make_shared<RandomFraction>();
}

std::shared_ptr<MathematicOperable> ProtocolMathF::random(double op1, double op2) {
    return std::make_shared<RandomInteger>(getNum(op1), getNum(op2));
}

std::shared_ptr<MathematicOperable> ProtocolMathF::random(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    return std::make_shared<RandomInteger>(op1,op2);
}

std::shared_ptr<MathematicOperable> ProtocolMathF::getNum(double value) {
    return std::make_shared<ConstantNumber>(value);
}

std::shared_ptr<MathematicOperable> ProtocolMathF::test(
        std::shared_ptr<ComparisonOperable> condition,
        std::shared_ptr<MathematicOperable> trueValue,
        std::shared_ptr<MathematicOperable> falseValue)
{
    return std::make_shared<TestOperation>(condition, trueValue, falseValue);
}

std::shared_ptr<MathematicOperable> ProtocolMathF::tryAddNumbers(std::shared_ptr<MathematicOperable> op1, std::shared_ptr<MathematicOperable> op2) {
    if (op1 != NULL
        && op2 != NULL
        && Utils::IsType<ConstantNumber,MathematicOperable>(op1.get())
        && Utils::IsType<ConstantNumber,MathematicOperable>(op2.get()))
    {
        std::shared_ptr<ConstantNumber> cn1 = std::dynamic_pointer_cast<ConstantNumber>(op1);
        std::shared_ptr<ConstantNumber> cn2 = std::dynamic_pointer_cast<ConstantNumber>(op2);
        return addNumbers(cn1, cn2);
    } else {
        return add(op1, op2);
    }
}

std::shared_ptr<MathematicOperable> ProtocolMathF::addNumbers(std::shared_ptr<ConstantNumber> op1, std::shared_ptr<ConstantNumber> op2) {
    double num1 = op1->getValue();
    double num2 = op2->getValue();
    return std::make_shared<ConstantNumber>(num1 + num2);
}

std::shared_ptr<MathematicOperable> ProtocolMathF::tryMaxNumbers(const std::vector<std::shared_ptr<MathematicOperable>> & ops) {
    std::vector<std::shared_ptr<MathematicOperable>> opsToMax;

    double maxNumber = ConstantNumber::M_INFINITE;
    for(auto it = ops.begin(); it < ops.end(); ++it) {
        std::shared_ptr<MathematicOperable> actualOp = *it;
        if (Utils::IsType<ConstantNumber, MathematicOperable>(actualOp.get())) {
            maxNumber = std::max(maxNumber, actualOp->getValue());
        } else {
            opsToMax.push_back(actualOp);
        }
    }

    std::shared_ptr<MathematicOperable> rValue;
    if (!opsToMax.empty()) {
        opsToMax.push_back(std::make_shared<ConstantNumber>(maxNumber));
        rValue = std::make_shared<ArithmeticArrayOperation>(opsToMax, ArithmeticArrayOperation::max);
    } else {
        rValue = std::make_shared<ConstantNumber>(maxNumber);
    }
    return rValue;
}

std::shared_ptr<MathematicOperable> ProtocolMathF::maxNumbers(std::shared_ptr<ConstantNumber> op1, std::shared_ptr<ConstantNumber> op2) {
    double num1 = op1->getValue();
    double num2 = op2->getValue();
    return std::make_shared<ConstantNumber>(std::max(num1, num2));
}

