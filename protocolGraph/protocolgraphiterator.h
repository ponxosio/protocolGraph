#ifndef PROTOCOLGRAPHITERATOR_H
#define PROTOCOLGRAPHITERATOR_H

#include "protocolGraph/ProtocolGraph.h"

class ProtocolGraphIterator
{
public:
    ProtocolGraphIterator(std::shared_ptr<ProtocolGraph> protocolGraph);
    virtual ~ProtocolGraphIterator() {}

protected:
    std::shared_ptr<ProtocolGraph> protocolGraph;
};

#endif // PROTOCOLGRAPHITERATOR_H
