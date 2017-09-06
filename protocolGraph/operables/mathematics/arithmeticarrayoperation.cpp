#include "arithmeticarrayoperation.h"

const std::string ArithmeticArrayOperation::PLUS_STRING_SRC = "plus";
const std::string ArithmeticArrayOperation::MINUS_STRING_SRC = "minus";
const std::string ArithmeticArrayOperation::MULTIPLY_STRING_SRC = "multiply";
const std::string ArithmeticArrayOperation::MAX_STRING_SRC = "max";
const std::string ArithmeticArrayOperation::MIN_STRING_SRC = "minus";

ArithmeticArrayOperation::ArithmeticArrayOperation() {
    this->op = plus;
}

ArithmeticArrayOperation::ArithmeticArrayOperation(const ArithmeticArrayOperation & aop) :
    array(aop.array)
{
    this->op = aop.op;
}

ArithmeticArrayOperation::ArithmeticArrayOperation(const std::vector<std::shared_ptr<MathematicOperable>> & array, ArithmeticArrayOperator op) :
    array(array)
{
    this->op = op;
}

ArithmeticArrayOperation::~ArithmeticArrayOperation() {

}

/**
 * Returns the numeric value of the variable, resulting from the mathematical operation
 * @return the numeric value of the variable
 */
double ArithmeticArrayOperation::getValue() const throw (std::invalid_argument) {
    double vuelta = 0.0;

    int arraySize = array.size();
    if (arraySize > 0) {

        auto it = array.begin();
        vuelta = (*it)->getValue();
        ++it;

        for(; it != array.end(); ++it) {
            double actualValue = (*it)->getValue();

            switch (op) {
            case plus:
                if (actualValue == ConstantNumber::INFINITE || vuelta == ConstantNumber::INFINITE) {
                    vuelta = ConstantNumber::INFINITE;
                } else {
                    vuelta += actualValue;
                }
                break;
            case minus:
                if (actualValue == ConstantNumber::M_INFINITE || vuelta == ConstantNumber::M_INFINITE) {
                    vuelta = ConstantNumber::M_INFINITE;
                } else {
                    vuelta -= actualValue;
                }
                break;
            case multiply:
                if (actualValue == ConstantNumber::INFINITE || vuelta == ConstantNumber::INFINITE) {
                    vuelta = ConstantNumber::INFINITE;
                } else {
                    vuelta *= actualValue;
                }
                break;
            case max:
                vuelta = std::max(vuelta, actualValue);
                break;
            case min:
                vuelta = std::min(vuelta, actualValue);
                break;
            }
        }
    }
    return vuelta;
}

/**
 * Compares two Objects implementing this interface
 * @param obj other object to be compared to
 * @return true if both are the same, false otherwise.
 */
bool ArithmeticArrayOperation::equal(const MathematicOperable* obj) const {
    bool vuelta = false;

    if (Utils::IsType<ArithmeticArrayOperation, MathematicOperable>(obj)) {
        const ArithmeticArrayOperation* cast = dynamic_cast<const ArithmeticArrayOperation*>(obj);

        vuelta = (cast->op == this->op);
        for(int i=0; vuelta && i < array.size(); i++) {
            std::shared_ptr<MathematicOperable> op1 = array.at(i);
            std::shared_ptr<MathematicOperable> op2 = cast->array.at(i);

            vuelta = op1->equal(op2.get());
        }
    }
    return vuelta;
}

bool ArithmeticArrayOperation::isPhysical() const throw (std::invalid_argument) {
    bool value = false;
    for(auto it = array.begin(); !value && it < array.end(); ++it) {
        value = (*it)->isPhysical();
    }
    return value;
}

std::string ArithmeticArrayOperation::toString() const {
    std::stringstream stream;

    stream << getStringOp() << "(";
    for(auto it = array.begin(); it < array.end(); ++it) {
        stream << (*it)->toString();
        if (it != array.end() - 1) {
            stream << ",";
        }
    }
    stream << ")";

    return stream.str();
}

std::string ArithmeticArrayOperation::getStringOp() const {
    std::string vuelta;
    switch (op) {
    case plus:
        vuelta = PLUS_STRING_SRC;
        break;
    case minus:
        vuelta = MINUS_STRING_SRC;
        break;
    case multiply:
        vuelta = MULTIPLY_STRING_SRC;
        break;
    case max:
        vuelta = MAX_STRING_SRC;
        break;
    case min:
        vuelta = MIN_STRING_SRC;
        break;
    }
    return vuelta;
}






