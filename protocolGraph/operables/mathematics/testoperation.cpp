#include "testoperation.h"

TestOperation::TestOperation() :
    MathematicOperable()
{
    condition = std::make_shared<Tautology>();
    trueValue = std::make_shared<ConstantNumber>(0.0);
    falseValue = std::make_shared<ConstantNumber>(0.0);
}

TestOperation::TestOperation(const TestOperation & aop) :
    MathematicOperable(aop)
{
    condition = std::shared_ptr<ComparisonOperable>(aop.condition->clone());
    trueValue = aop.trueValue;
    falseValue = aop.falseValue;
}

TestOperation::TestOperation(
        std::shared_ptr<ComparisonOperable> condition,
        std::shared_ptr<MathematicOperable> trueValue,
        std::shared_ptr<MathematicOperable> falseValue) :
    MathematicOperable()
{
    this->condition = condition;
    this->trueValue = trueValue;
    this->falseValue = falseValue;
}

TestOperation::~TestOperation() {

}

double TestOperation::getValue() const throw (std::invalid_argument) {
    double value;
    if(condition->conditionMet()) {
        value = trueValue->getValue();
    } else {
        value = falseValue->getValue();
    }
    return value;
}

bool TestOperation::equal(const MathematicOperable* obj) const {
    bool vuelta = false;
    if (Utils::IsType<TestOperation, MathematicOperable>(obj)) {
        const TestOperation* cast = dynamic_cast<const TestOperation*>(obj);
        vuelta = ((this->condition->equals(cast->condition.get()))
                && (this->trueValue->equal(cast->trueValue.get()))
                && (this->falseValue->equal(cast->falseValue.get())));
    }
    return vuelta;
}
