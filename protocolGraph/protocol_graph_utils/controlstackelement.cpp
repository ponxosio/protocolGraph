#include "controlstackelement.h"

ControlStackElement::ControlStackElement(int ctrNodeId, ControlNode::ControlType type) {
    this->ctrNodeId = ctrNodeId;
    this->type = type;
}

ControlStackElement::ControlStackElement(int ctrNodeId, const std::vector<int> & opStack, ControlNode::ControlType type) :
    opStack(opStack)
{
    this->ctrNodeId = ctrNodeId;
    this->type = type;
}

ControlStackElement::ControlStackElement(const ControlStackElement & cse) :
    opStack(cse.opStack), linkedElements(cse.linkedElements)
{
    this->ctrNodeId = cse.ctrNodeId;
    this->type = cse.type;
}

ControlStackElement::~ControlStackElement() {

}
