#include "generalprotocolexecutor.h"

GeneralProtocolExecutor::GeneralProtocolExecutor(std::shared_ptr<ProtocolGraph> protocol) :
    ProtocolExecutorInterface(protocol)
{

}

GeneralProtocolExecutor::~GeneralProtocolExecutor() {

}

void GeneralProtocolExecutor::executeProtocol(std::shared_ptr<ActuatorsExecutionInterface> executor,int nargs, ...)
    throw (std::runtime_error)
{
    if (nargs == 0) {
        va_list args;
        va_start(args, nargs);
        try {
            std::vector<int> nodes2process = {protocol->getStart()->getContainerId()};
            while(!nodes2process.empty()) {
                int nextId = nodes2process.back();
                nodes2process.pop_back();

                if (protocol->isCpuOperation(nextId)) {
                    protocol->getCpuOperation(nextId)->execute();
                } else if (protocol->isActuatorOperation(nextId)) {
                    protocol->getActuatorOperation(nextId)->execute(executor.get());
                }

                ProtocolGraph::ProtocolEdgeVectorPtr leaving = protocol->getProjectingEdges(nextId);
                for(const ProtocolGraph::ProtocolEdgePtr & edge: *leaving.get()) {
                    if (edge->conditionMet()) {
                        int nextop = edge->getIdTarget();
                        if (find(nodes2process.begin(),nodes2process.end(), nextop) == nodes2process.end()) {
                            nodes2process.push_back(nextop);
                        }
                    }
                }
            }
            va_end(args);
        }catch (std::exception & ex) {
            va_end(args);
            throw(std::invalid_argument("GeneralProtocolExecutor::executeProtocol" + std::string(ex.what())));
        }
    } else {
        throw(std::invalid_argument("GeneralProtocolExecutor::executeProtocol. Must receive zero argument, has received : " + std::to_string(nargs)));
    }
}
