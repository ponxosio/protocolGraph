#include "characteristiccheck.h"

CharacteristicCheck::CharacteristicCheck() :
    ComparisonOperable()
{
    value = NULL;
    op = CheckOperations::odd;
    negation = false;
}

CharacteristicCheck::CharacteristicCheck(const CharacteristicCheck & obj) :
    ComparisonOperable(obj)
{
        value = std::shared_ptr<MathematicOperable>(obj.value);
        op = obj.op;
        negation = obj.negation;
}

CharacteristicCheck::CharacteristicCheck(
        bool negation,
        std::shared_ptr<MathematicOperable> value,
        CheckOperations op) :
    ComparisonOperable()
{
    this->negation = negation;
    this->op = op;
    this->value = value;
}

CharacteristicCheck::~CharacteristicCheck() {

}

bool CharacteristicCheck::conditionMet() const {
    bool met = false;
    switch (op) {
    case CheckOperations::odd: {
        double calcValue = value->getValue();
        met = Utils::isWhole(calcValue) && Utils::isOdd((int)calcValue);
        break;
    } case CheckOperations::even : {
        double calcValue = value->getValue();
        met = Utils::isWhole(calcValue) && Utils::isEven((int)calcValue);
        break;
    } case CheckOperations::prime : {
        double calcValue = value->getValue();
        met = Utils::isWhole(calcValue) && Utils::isPrime((int)calcValue);
        break;
    } case CheckOperations::whole : {
        met = Utils::isWhole(value->getValue());
        break;
    } case CheckOperations::positive : {
        met = value->getValue() >= 0;
        break;
    } case CheckOperations::negative : {
        met = value->getValue() < 0;
        break;
    }
    }
    return met;
}

bool CharacteristicCheck::equals(ComparisonOperable* obj) const {
    bool vuelta = false;
    if (Utils::IsType<CharacteristicCheck, ComparisonOperable>(obj)) {
        const CharacteristicCheck* cast = dynamic_cast<const CharacteristicCheck*>(obj);
        vuelta = ((cast->value->equal(this->value.get()))
                && (cast->op == this->op)
                && (cast->negation == this->negation));
    }
    return vuelta;
}

std::string CharacteristicCheck::getStringOp() const {
    std::string str = "unknow";
    switch (op) {
    case CheckOperations::odd :
        str = ODD_STR;
        break;
    case CheckOperations::even :
        str = EVEN_STR;
        break;
    case CheckOperations::prime :
        str = PRIME_STR;
        break;
    case CheckOperations::whole :
        str = WHOLE_STR;
        break;
    case CheckOperations::positive :
        str = POSITIVE_STR;
        break;
    case CheckOperations::negative :
        str = NEGATIVE_STR;
        break;
    default:
        break;
    }
    return str;
}
