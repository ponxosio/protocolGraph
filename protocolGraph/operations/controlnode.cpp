#include "controlnode.h"

ControlNode::ControlNode() : Node() {
    type = if_type;
    conditionIn = NULL;
}

ControlNode::ControlNode(const ControlNode & node) : Node(node) {
    type = node.type;
    conditionIn = node.conditionIn;
    endBlockId = node.endBlockId;
}

ControlNode::ControlNode(int containerId, ControlType type, std::shared_ptr<ComparisonOperable> conditionIn) : Node(containerId) {
    this->type = type;
    this->conditionIn = conditionIn;
}

ControlNode::~ControlNode() {

}

std::string ControlNode::toText() {
    return std::to_string(containerID) + "[label=\"" + typeToStr(type) + "(" + conditionIn->toString() + ")\"];";
}

std::string ControlNode::typeToStr(ControlType type) {
    std::string str = "";
    switch(type) {
        case if_type:
            str = IF_STR;
            break;
        case elif_type:
            str = ELIF_STR;
            break;
        case else_type:
            str = ELSE_STR;
            break;
        case loop_type:
            str = LOOP_STR;
            break;
        default:
            str = "UNKNOW_TYPE";
            break;
    }
    return str;
}

