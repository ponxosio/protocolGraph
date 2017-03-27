#ifndef CONTROLNODE_H
#define CONTROLNODE_H

#define IF_STR "if"
#define ELIF_STR "elif"
#define ELSE_STR "else"
#define LOOP_STR "loop"

#include <memory>

#include <graph/Node.h>

#include "protocolGraph/operables/comparison/ComparisonOperable.h"

class ControlNode : public Node
{
public:
    typedef enum ControlType_ {
        if_type,
        elif_type,
        else_type,
        loop_type
    } ControlType;

    ControlNode();
    ControlNode(const ControlNode & node);
    ControlNode(int containerId, ControlType type, std::shared_ptr<ComparisonOperable> conditionIn);

    virtual ~ControlNode();

    virtual std::string toText();

    inline virtual Node* clone() {
        return new ControlNode(*this);
    }

    inline ControlType getType() {
        return type;
    }

    inline const std::shared_ptr<const ComparisonOperable> getConditionIn() const {
        return conditionIn;
    }

    inline const std::vector<int> & getEndBlockId() const {
        return endBlockId;
    }

    inline void setEndBlockId(const std::vector<int> & endBlockId) {
        this->endBlockId.clear();
        this->endBlockId.reserve(endBlockId.size());

        for(int i = 0; i < endBlockId.size(); i++) {
            this->endBlockId.insert(this->endBlockId.begin() + i, endBlockId[i]);
        }
    }

protected:
    ControlType type;
    std::vector<int> endBlockId;
    std::shared_ptr<ComparisonOperable> conditionIn;

    std::string typeToStr(ControlType type);

};

#endif // CONTROLNODE_H
