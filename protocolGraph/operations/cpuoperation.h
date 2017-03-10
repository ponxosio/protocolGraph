#ifndef CPUOPERATION_H
#define CPUOPERATION_H

#include <graph/Node.h>

class CPUOperation : public Node {
public:
    CPUOperation() :
        Node()
    {
    }
    CPUOperation(const CPUOperation & obj) :
        Node(obj)
    {
    }
    CPUOperation(int idContainer) :
        Node(idContainer)
    {
    }
    virtual ~CPUOperation(){}

    virtual void execute() = 0;
};
#endif // CPUOPERATION_H
