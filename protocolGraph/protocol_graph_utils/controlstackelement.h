#ifndef CONTROLSTACKELEMENT_H
#define CONTROLSTACKELEMENT_H

#include <vector>

#include <graph/Graph.h>
#include <graph/Node.h>

#include "protocolGraph/ConditionEdge.h"

#include "protocolGraph/operations/controlnode.h"

class ControlStackElement
{
public:
    ControlStackElement(int ctrNodeId, ControlNode::ControlType type);
    ControlStackElement(int ctrNodeId, const std::vector<int> & opStack, ControlNode::ControlType type);
    ControlStackElement(const ControlStackElement & cse);
    virtual ~ControlStackElement();

    inline int getCrtNodeId() const {
        return ctrNodeId;
    }

    inline ControlNode::ControlType getType() const {
        return type;
    }

    inline std::vector<int> & getOpStack() {
        return opStack;
    }

    inline const std::vector<int> & getOpStack() const {
        return opStack;
    }

    inline std::vector<ControlStackElement> & getLinkedElements() {
        return linkedElements;
    }

    inline const std::vector<ControlStackElement> & getLinkedElements() const {
        return linkedElements;
    }
protected:
    int ctrNodeId;
    ControlNode::ControlType type;
    std::shared_ptr<Graph<Node, ConditionEdge>> graph;

    std::vector<int> opStack;
    std::vector<ControlStackElement> linkedElements;
};

#endif // CONTROLSTACKELEMENT_H
