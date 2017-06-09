/*
 * ProtocolGraph.cpp
 *
 *  Created on: 9 de mar. de 2016
 *      Author: angel
 */

#include "ProtocolGraph.h"

ProtocolGraph::ProtocolGraph() {
	this->name = "undefined";
	this->idStart = -1;
    this->graph = std::make_shared<Graph<Node, ConditionEdge>>();
    this->varTable = std::make_shared<VariableTable>();
    this->timeVariable = std::make_shared<VariableEntry>(TIME_VARIABLE, varTable);
    this->tautology = std::make_shared<Tautology>();
}

ProtocolGraph::ProtocolGraph(const ProtocolGraph & prot) :
    varTable(prot.varTable),
    nodeSerie(prot.nodeSerie),
    cpuOperations(prot.cpuOperations),
    controlOperations(prot.controlOperations),
    actuatorsOperations(prot.actuatorsOperations),
    varEntryTable(prot.varEntryTable),
    vcontainerMap(prot.vcontainerMap),
    mainStack(prot.mainStack),
    controlStack(prot.controlStack),
    closingControlElms(prot.closingControlElms)
{
	this->name = prot.name;
	this->idStart = prot.idStart;
	this->graph = prot.graph;
    this->timeVariable = std::make_shared<VariableEntry>(TIME_VARIABLE, varTable);
}

ProtocolGraph::ProtocolGraph(const std::string & name) {
	this->name = name;
	this->idStart = -1;
    this->graph = std::make_shared<Graph<Node, ConditionEdge>>();
    this->varTable = std::make_shared<VariableTable>();
    this->timeVariable = std::make_shared<VariableEntry>(TIME_VARIABLE, varTable);
    this->tautology = std::make_shared<Tautology>();
}

ProtocolGraph::~ProtocolGraph() {}

int ProtocolGraph::emplaceAssignation(const std::string & receiver, std::shared_ptr<MathematicOperable> value) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<VariableEntry> receiverPtr = getVariableEntry(receiver);
    receiverPtr->setPhysical(value->isPhysical() /*|| checkControlStackIsPhysical()*/);

    std::shared_ptr<Node> nodePtr = std::make_shared<AssignationOperation>(nextId, receiverPtr, value);
    graph->addNode(nodePtr);

    cpuOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceApplyLight(
        const std::string & sourceID,
        std::shared_ptr<MathematicOperable> wavelength,
        units::Length wavelengthUnits,
        std::shared_ptr<MathematicOperable> intensity,
        units::LuminousIntensity intensityUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<ApplyLight>(nextId, sourceID, wavelength, wavelengthUnits, intensity, intensityUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceApplyTemperature(
        const std::string & sourceId,
        std::shared_ptr<MathematicOperable> temperature,
        units::Temperature temperatureUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<ApplyTemperature>(nextId, sourceId, temperature, temperatureUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceGetVirtualVolume(const std::string & sourceId, const std::string & receiver) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<VariableEntry> receiverPtr = getVariableEntry(receiver);
    std::shared_ptr<Node> nodePtr = std::make_shared<GetVolume>(nextId, sourceId, receiverPtr);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceLoadContainer(const std::string & idSource, std::shared_ptr<MathematicOperable> volume, units::Volume volumeUnits) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<LoadContainerOperation>(nextId, idSource, volume, volumeUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceMeasureOD(
        const std::string & sourceId,
        const std::string & receiver,
        std::shared_ptr<MathematicOperable> measurmentFrequency,
        units::Frequency measurmentFrequencyUnits,
        std::shared_ptr<MathematicOperable> wavelength,
        units::Length wavelengthUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<VariableEntry> receiverPtr = getVariableEntry(receiver);
    receiverPtr->setPhysical(true);

    std::shared_ptr<Node> nodePtr = std::make_shared<MeasureOD>(nextId, sourceId, receiverPtr, measurmentFrequency,
                                                                measurmentFrequencyUnits, wavelength, wavelengthUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceMeasureFluorescence(
        const std::string & sourceId,
        const std::string & receiver,
        std::shared_ptr<MathematicOperable> measurmentFrequency,
        units::Frequency measurmentFrequencyUnits,
        std::shared_ptr<MathematicOperable> excitation,
        units::Length excitationUnits,
        std::shared_ptr<MathematicOperable> emission,
        units::Length emissionUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<VariableEntry> receiverPtr = getVariableEntry(receiver);
    receiverPtr->setPhysical(true);

    std::shared_ptr<Node> nodePtr = std::make_shared<MeasureFluorescence>(nextId, sourceId, receiverPtr, measurmentFrequency,
                                                                measurmentFrequencyUnits, excitation, excitationUnits, emission, emissionUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceMeasureLuminiscence(
        const std::string & sourceId,
        const std::string & receiver,
        std::shared_ptr<MathematicOperable> measurmentFrequency,
        units::Frequency measurmentFrequencyUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<VariableEntry> receiverPtr = getVariableEntry(receiver);
    receiverPtr->setPhysical(true);

    std::shared_ptr<Node> nodePtr = std::make_shared<MeasureLuminiscence>(nextId, sourceId, receiverPtr, measurmentFrequency, measurmentFrequencyUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceMeasureVolume(
        const std::string & sourceId,
        const std::string & receiver,
        std::shared_ptr<MathematicOperable> measurmentFrequency,
        units::Frequency measurmentFrequencyUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<VariableEntry> receiverPtr = getVariableEntry(receiver);
    receiverPtr->setPhysical(true);

    std::shared_ptr<Node> nodePtr = std::make_shared<MeasureVolume>(nextId, sourceId, receiverPtr, measurmentFrequency, measurmentFrequencyUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceMeasureTemperature(
        const std::string & sourceId,
        const std::string & receiver,
        std::shared_ptr<MathematicOperable> measurmentFrequency,
        units::Frequency measurmentFrequencyUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<VariableEntry> receiverPtr = getVariableEntry(receiver);
    receiverPtr->setPhysical(true);

    std::shared_ptr<Node> nodePtr = std::make_shared<MeasureTemperature>(nextId, sourceId, receiverPtr, measurmentFrequency, measurmentFrequencyUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceMix(
        const std::string & idSource1,
        const std::string & idSource2,
        const std::string & idTarget,
        std::shared_ptr<MathematicOperable> volume1,
        units::Volume volume1Units,
        std::shared_ptr<MathematicOperable> volume2,
        units::Volume volume2Units,
        const std::string & opDuration)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr =
            std::make_shared<Mix>(
                nextId,
                idSource1,
                idSource2,
                idTarget,
                volume1,
                volume1Units,
                volume2,
                volume2Units,
                getVariable(opDuration));

    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceStopContinuousFlow(const std::string & idSource, const std::string & idTarget) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<StopContinuosFlow>(nextId, idSource, idTarget);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceSetContinuousFlow(
        const std::string & idSource,
        const std::string & idTarget,
        std::shared_ptr<MathematicOperable> rate,
        units::Volumetric_Flow rateUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<SetContinousFlow>(nextId, idSource, idTarget, rate, rateUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceSetTimeStep(std::shared_ptr<MathematicOperable> timeSlice, units::Time timeUnits) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<SetTimeStep>(nextId, timeSlice, timeUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceStir(const std::string & sourceId, std::shared_ptr<MathematicOperable> intensity, units::Frequency intensityUnits) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<Stir>(nextId, sourceId, intensity, intensityUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceTimeStep() {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<TimeStep>(nextId, timeVariable);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceTransfer(
        const std::string & idSource,
        const std::string & idTarget,
        std::shared_ptr<MathematicOperable> volume,
        units::Volume volumeUnits,
        const std::string & opDuration)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<Transfer>(nextId, idSource, idTarget, volume, volumeUnits, getVariable(opDuration));
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceFinishOperation(int finsihOperationId) throw(std::invalid_argument) {
    std::shared_ptr<Node> opPtr = graph->getNode(finsihOperationId);
    if (opPtr != NULL) {
        std::shared_ptr<FinishableOperation> finishOpPtr = std::dynamic_pointer_cast<FinishableOperation>(opPtr);
        if (finishOpPtr != NULL) {
            int nextId = nodeSerie.getNextValue();

            std::shared_ptr<Node> nodePtr = std::make_shared<FinishOperation>(nextId, finishOpPtr);
            graph->addNode(nodePtr);

            actuatorsOperations.insert(nextId);
            return nextId;
        } else {
            throw(std::invalid_argument("ProtocolGraph::emplaceFinishOperation. finishOp id " + std::to_string(finsihOperationId) +
                                        " is not a Finishable Operation"));
        }
    } else {
        throw(std::invalid_argument("ProtocolGraph::emplaceFinishOperation. Unknow finishOp id " + std::to_string(finsihOperationId)));
    }
}

int ProtocolGraph::emplaceElectrophoresis(
        const std::string & sourceId,
        std::shared_ptr<MathematicOperable> fieldStrenght,
        units::ElectricField fieldUnits,
        std::shared_ptr<VariableEntry> dataReference)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<ElectrophoresisOperation>(nextId, sourceId, fieldStrenght, fieldUnits, dataReference);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceCentrifugate(
        const std::string & sourceId,
        std::shared_ptr<MathematicOperable> speed,
        units::Frequency speedUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<CentrifugateOperation>(nextId, sourceId, speed, speedUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceShake(const std::string & sourceId,
                                std::shared_ptr<MathematicOperable> speed,
                                units::Frequency speedUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<ShakeOperation>(nextId, sourceId, speed, speedUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

void ProtocolGraph::startIfBlock(std::shared_ptr<ComparisonOperable> condition) {
    int nodeId = nodeSerie.getNextValue();
    std::shared_ptr<Node> nodeIfPtr = std::make_shared<ControlNode>(nodeId, ControlNode::if_type, condition);
    graph->addNode(nodeIfPtr);
    controlOperations.insert(nodeId);

    appendOperations(nodeId);

    ControlStackElement element(nodeId, std::vector<int>{nodeId}, ControlNode::if_type);
    controlStack.push_back(element);
}

void ProtocolGraph::startElIfBlock(std::shared_ptr<ComparisonOperable> condition) throw(std::runtime_error) {
    if(!controlStack.empty()) {
        const ControlStackElement & top = controlStack.back();
        ControlNode::ControlType topType = top.getType();
        if (topType == ControlNode::if_type || topType == ControlNode::elif_type) {
            int nodeId = nodeSerie.getNextValue();
            std::shared_ptr<Node> nodeIfPtr = std::make_shared<ControlNode>(nodeId, ControlNode::elif_type, condition);
            graph->addNode(nodeIfPtr);
            controlOperations.insert(nodeId);

            int topId = top.getCrtNodeId();
            std::shared_ptr<ControlNode> ctrPtr = getControlNode(topId);
            std::shared_ptr<ComparisonOperable> conditionOut(ctrPtr->getConditionIn()->clone());
            conditionOut->negate();
            graph->addEdge(makeEdge(topId, nodeId, conditionOut));

            ControlStackElement element(nodeId, std::vector<int>{nodeId}, ControlNode::elif_type);
            if (!closingControlElms.empty()) {
                linkClosingStack(element);
            }
            controlStack.push_back(element);
        } else {
            throw(std::runtime_error("ProtocolGraph::startElIfBlock().To start an elif block you must have started an if or an elif before"));
        }
    } else {
        throw(std::runtime_error("ProtocolGraph::startElIfBlock().To start an elif block first you must start a control block"));
    }
}

void ProtocolGraph::startElseBlock() throw(std::runtime_error) {
    if(!controlStack.empty()) {
        const ControlStackElement & top = controlStack.back();
        ControlNode::ControlType topType = top.getType();
        if (topType == ControlNode::if_type || topType == ControlNode::elif_type) {
            int nodeId = nodeSerie.getNextValue();
            std::shared_ptr<Node> nodeIfPtr = std::make_shared<ControlNode>(nodeId, ControlNode::else_type, tautology);
            graph->addNode(nodeIfPtr);
            controlOperations.insert(nodeId);

            int topId = top.getCrtNodeId();
            std::shared_ptr<ControlNode> ctrPtr = getControlNode(topId);
            std::shared_ptr<ComparisonOperable> conditionOut(ctrPtr->getConditionIn()->clone());
            conditionOut->negate();
            graph->addEdge(makeEdge(topId, nodeId, conditionOut));

            ControlStackElement element(nodeId, std::vector<int>{nodeId}, ControlNode::else_type);
            if (!closingControlElms.empty()) {
                linkClosingStack(element);
            }
            controlStack.push_back(element);
        } else {
            throw(std::runtime_error("ProtocolGraph::startElseBlock().To start an else block you must have started an if or an elif before"));
        }
    } else {
        throw(std::runtime_error("ProtocolGraph::startElseBlock().To start an else block first you must start a control block"));
    }
}

void ProtocolGraph::endIfBlock() throw(std::runtime_error) {
    if(!controlStack.empty()) {
        ControlNode::ControlType topType = controlStack.back().getType();
        if (topType == ControlNode::if_type || topType == ControlNode::elif_type || topType == ControlNode::else_type) {
            ControlNode::ControlType actualType;
            do {
                const ControlStackElement & top = controlStack.back();
                ControlStackElement topCopy(top);
                closingControlElms.push_back(topCopy);

                actualType = top.getType();
                controlStack.pop_back();
            } while(actualType != ControlNode::if_type);
        } else {
            throw(std::runtime_error("ProtocolGraph::endIfBlock().To end an if block you must have started an if or an elif or an else before"));
        }
    } else {
        throw(std::runtime_error("ProtocolGraph::endIfBlock().To end an if block first you must start a control block"));
    }
}

void ProtocolGraph::startLoopBlock(std::shared_ptr<ComparisonOperable> condition) {
    int nodeId = nodeSerie.getNextValue();
    std::shared_ptr<Node> nodeIfPtr = std::make_shared<ControlNode>(nodeId, ControlNode::loop_type, condition);
    graph->addNode(nodeIfPtr);
    controlOperations.insert(nodeId);

    appendOperations(nodeId);

    ControlStackElement element(nodeId, std::vector<int>{nodeId}, ControlNode::loop_type);
    controlStack.push_back(element);
}

void ProtocolGraph::endLoopBlock() throw(std::runtime_error) {
    if(!controlStack.empty()) {
        ControlStackElement top = controlStack.back();
        const ControlNode::ControlType & topType = top.getType();
        if (topType == ControlNode::loop_type) {
            int loopId = top.getCrtNodeId();
            appendOperations(loopId);

            ControlStackElement topCopy(top);
            closingControlElms.push_back(topCopy);
            controlStack.pop_back();
        } else {
            throw(std::runtime_error("ProtocolGraph::endLoopBlock().To end a loop block you must have started a loop before"));
        }
    } else {
        throw(std::runtime_error("ProtocolGraph::endLoopBlock().To end a loop block first you must start a control block"));
    }
}

void ProtocolGraph::appendOperations(int idOpAppend) {
    if(checkClosingElemsNeedProcessing()) {
        appendToClosingControls(std::vector<int>{idOpAppend}, closingControlElms);
    } else {
        std::vector<int> & activeStack = getActiveAppendableNodes();
        std::shared_ptr<ComparisonOperable> condition = getActualCondition();

        for(auto it = activeStack.begin(); it != activeStack.end(); ++it) {
            graph->addEdge(makeEdge(*it, idOpAppend, condition));
        }

        activeStack.clear();
        activeStack.push_back(idOpAppend);

    }
}
void ProtocolGraph::appendOperations(const std::vector<int> & idsOpsAppends)
{
    if(checkClosingElemsNeedProcessing()) {
        appendToClosingControls(idsOpsAppends, closingControlElms);
    } else {
        std::vector<int> & activeStack = getActiveAppendableNodes();
        std::shared_ptr<ComparisonOperable> condition = getActualCondition();

        for(auto it = activeStack.begin(); it != activeStack.end(); ++it) {
            for(int id : idsOpsAppends) {
                graph->addEdge(makeEdge(*it, id, condition));
            }
        }

        activeStack.clear();
        for(int id : idsOpsAppends) {
            activeStack.push_back(id);
        }
    }
}

void ProtocolGraph::appendOperations(const std::vector<int> & sourcesAppend, const std::vector<int> & targetsAppends) throw(std::runtime_error)
{
    if(checkClosingElemsNeedProcessing()) {
        throw(std::runtime_error("ProtocolGraph::appendOperations(). Control block just closed, imposible to use this append"));
    } else {
        std::vector<int> & activeStack = getActiveAppendableNodes();
        std::shared_ptr<ComparisonOperable> condition = getActualCondition();

        std::vector<std::vector<int>::iterator> mainStackToRemove;
        for(int sourceId : sourcesAppend) {
            auto it = std::find(activeStack.begin(), activeStack.end(), sourceId);
            if (it != activeStack.end()) {
                mainStackToRemove.push_back(it);
            } else {
                throw(std::runtime_error("ProtocolGraph::appendOperations(). Source id: " + std::to_string(sourceId) + " is not appendable"));
            }
        }
        for(int sourceId : sourcesAppend) {
            for(int targetId : targetsAppends) {
                graph->addEdge(makeEdge(sourceId, targetId, condition));
            }
        }
        for(std::vector<int>::iterator elem2erase : mainStackToRemove) {
            activeStack.erase(elem2erase);
        }
        for(int targetId : targetsAppends) {
            activeStack.push_back(targetId);
        }
    }
}

void ProtocolGraph::clearVarTable() {
    varTable->clear();
    varTable->setValue(TIME_VARIABLE, 0.0);
}

const std::shared_ptr<VariableEntry> & ProtocolGraph::getTimeVariable() const {
    return timeVariable;
}

std::shared_ptr<VariableEntry> ProtocolGraph::getVariable(const std::string & name) {
    return std::make_shared<VariableEntry>(name, varTable);
}

std::shared_ptr<CPUOperation> ProtocolGraph::getCpuOperation(int idNode) throw(std::invalid_argument) {
    auto finded = cpuOperations.find(idNode);
    if (finded != cpuOperations.end()) {
        std::shared_ptr<Node> nodePtr = graph->getNode(*finded);
        if (nodePtr != NULL) {
            std::shared_ptr<CPUOperation> cpuCast = std::dynamic_pointer_cast<CPUOperation>(nodePtr);
            if (cpuCast) {
                return cpuCast;
            } else {
                throw(std::invalid_argument(std::to_string(idNode) + " is not a CPUOperation."));
            }
        } else {
            throw(std::invalid_argument(std::to_string(idNode) + " is not in the graph."));
        }
    } else {
        throw(std::invalid_argument(std::to_string(idNode) + " is not a CPU Operation."));
    }
}

std::shared_ptr<ControlNode> ProtocolGraph::getControlNode(int idNode) throw(std::invalid_argument) {
    auto finded = controlOperations.find(idNode);
    if (finded != controlOperations.end()) {
        std::shared_ptr<Node> nodePtr = graph->getNode(*finded);
        if (nodePtr != NULL) {
            std::shared_ptr<ControlNode> controlCast = std::dynamic_pointer_cast<ControlNode>(nodePtr);
            if (controlCast) {
                return controlCast;
            } else {
                throw(std::invalid_argument("ProtocolGraph::getControlNode()."+std::to_string(idNode) + " is not a ControlNode."));
            }
        } else {
            throw(std::invalid_argument("ProtocolGraph::getControlNode()." + std::to_string(idNode) + " is not in the graph."));
        }
    } else {
        throw(std::invalid_argument("ProtocolGraph::getControlNode()." + std::to_string(idNode) + " is not a ControlNode."));
    }
}

std::shared_ptr<ActuatorsOperation> ProtocolGraph::getActuatorOperation(int idNode) throw(std::invalid_argument) {
    auto finded = actuatorsOperations.find(idNode);
    if (finded != actuatorsOperations.end()) {
        std::shared_ptr<Node> nodePtr = graph->getNode(*finded);
        if (nodePtr != NULL) {
            std::shared_ptr<ActuatorsOperation> actuatorsCast = std::dynamic_pointer_cast<ActuatorsOperation>(nodePtr);
            if (actuatorsCast) {
                return actuatorsCast;
            } else {
                throw(std::invalid_argument(std::to_string(idNode) + " is not a CPUOperation."));
            }
        } else {
            throw(std::invalid_argument(std::to_string(idNode) + " is not in the graph."));
        }
    } else {
        throw(std::invalid_argument(std::to_string(idNode) + " is not an Actuator operation."));
    }
}

std::shared_ptr<VirtualContainer> ProtocolGraph::getVContainer(const std::string & vcName) const {
    std::shared_ptr<VirtualContainer> vcPtr = NULL;
    auto finded = vcontainerMap.find(vcName);
    if (finded != vcontainerMap.end()) {
        vcPtr = finded->second;
    }
    return vcPtr;
}

bool ProtocolGraph::addVContainer(
        const std::string & name,
        VirtualContainer::ContainerType vcType,
        units::Volume capacity,
        units::Volume initialVolume,
        units::Temperature storeTemperature)
{
    bool added = false;
    if (vcontainerMap.find(name) == vcontainerMap.end()) {
        std::shared_ptr<VirtualContainer> vptr = std::make_shared<VirtualContainer>(name, vcType, capacity, initialVolume, storeTemperature);
        vcontainerMap.insert(std::make_pair(name, vptr));
        added = true;
    }
    return added;
}

ProtocolGraph::ProtocolNodePtr ProtocolGraph::getStart() {
	return graph->getNode(idStart);
}

void ProtocolGraph::setStartNode(int idStart) {
	this->idStart = idStart;
    mainStack.push_back(idStart);
}

ProtocolGraph::ProtocolEdgePtr ProtocolGraph::makeEdge(int idSource, int idTarget, std::shared_ptr<ComparisonOperable> comparison) {
    //return new ConditionEdge(idSource, idTarget, comparison);
    return std::make_shared<ConditionEdge>(idSource, idTarget, comparison);
}

std::shared_ptr<VariableEntry> ProtocolGraph::getVariableEntry(const std::string & varName) {
    auto finded = varEntryTable.find(varName);
    if (finded != varEntryTable.end()) {
        return finded->second;
    } else {
        std::shared_ptr<VariableEntry> entryPtr = std::make_shared<VariableEntry>(varName, varTable);
        varEntryTable.insert(std::make_pair(varName, entryPtr));
        return entryPtr;
    }
}

std::vector<int> & ProtocolGraph::getActiveAppendableNodes() {
    if(controlStack.empty()) {
        return mainStack;
    } else {
        return controlStack.back().getOpStack();
    }
}

std::shared_ptr<ComparisonOperable> ProtocolGraph::getActualCondition() {
    std::shared_ptr<ComparisonOperable> condition = tautology;
    if (!controlStack.empty()) {
        const std::vector<int> & controlLocalStack = controlStack.back().getOpStack();
        if (controlLocalStack.size() == 1 && isControlOperations(controlLocalStack.back())) {
            int controlNodeId = controlLocalStack.back();
            std::shared_ptr<ControlNode> nodePtr = getControlNode(controlNodeId);
            condition = std::shared_ptr<ComparisonOperable>(nodePtr->getConditionIn()->clone());
        }
    }
    return condition;
}

bool ProtocolGraph::checkControlStackIsPhysical() {
    bool isPhysical = false;
    for(const ControlStackElement & e : controlStack) {
        int ctrId = e.getCrtNodeId();
        const std::shared_ptr<ControlNode> & ctrPtr = getControlNode(ctrId);
        isPhysical = isPhysical || ctrPtr->getConditionIn()->isPhysical();
    }
    return isPhysical;
}

bool ProtocolGraph::checkClosingElemsNeedProcessing() {
    return !closingControlElms.empty() && (controlStack.empty() || (controlStack.back().getType() == ControlNode::loop_type));
}

void ProtocolGraph::linkClosingStack(ControlStackElement & element) {
    std::vector<ControlStackElement> & linkedElem = element.getLinkedElements();
    linkedElem.reserve(linkedElem.size() + closingControlElms.size());
    linkedElem.insert(linkedElem.begin(), closingControlElms.begin(), closingControlElms.end());
    closingControlElms.clear();
}

void ProtocolGraph::appendToClosingControls(const std::vector<int> & idsOpsAppends, std::vector<ControlStackElement> & closingStack) {
    std::shared_ptr<ControlNode> lastNode = NULL;
    std::vector<ControlStackElement> extraElems;

    while(!closingStack.empty()) {
        const ControlStackElement & elem = closingStack.back();

        if (!elem.getLinkedElements().empty()) {
            const std::vector<ControlStackElement> & actualLinked = elem.getLinkedElements();
            extraElems.reserve(extraElems.size() + actualLinked.size());
            extraElems.insert(extraElems.begin(), actualLinked.begin(), actualLinked.end());
        }

        ControlNode::ControlType type = elem.getType();
        if (type == ControlNode::loop_type) {
            closingControls_ProcessLoop(idsOpsAppends, elem.getCrtNodeId(), lastNode);
        } else if (type == ControlNode::else_type) {
            closingControls_ProcessElse(idsOpsAppends, elem.getCrtNodeId(), elem.getOpStack(), lastNode);
        } else if (type == ControlNode::if_type) {
            closingControls_ProcessIf(idsOpsAppends, elem.getCrtNodeId(), elem.getOpStack(), lastNode);
        } else if (type == ControlNode::elif_type) {
            closingControls_ProcessElif(idsOpsAppends, elem.getCrtNodeId(), elem.getOpStack(), lastNode);
        }
        closingStack.pop_back();
    }

    if ((lastNode != NULL) &&
        (lastNode->getType() == ControlNode::if_type || lastNode->getType() == ControlNode::elif_type))
    {
        std::shared_ptr<ComparisonOperable> conditionOut(lastNode->getConditionIn()->clone());
        conditionOut->negate();

        for(int idOp : idsOpsAppends) {
            graph->addEdge(makeEdge(lastNode->getContainerId(), idOp, conditionOut));
        }
    }

    if (!extraElems.empty()) {
        appendToClosingControls(idsOpsAppends, extraElems);
    }

    std::vector<int> & actualStack = getActiveAppendableNodes();
    actualStack.clear();
    for(int idOp: idsOpsAppends) {
        actualStack.push_back(idOp);
    }
}

void ProtocolGraph::closingControls_ProcessLoop(const std::vector<int> & idsOpsAppends,
                                                int idLoop,
                                                std::shared_ptr<ControlNode> & lastNode)
{
    std::shared_ptr<ControlNode> ctrPtr = getControlNode(idLoop);
    std::shared_ptr<ComparisonOperable> conditionOut(ctrPtr->getConditionIn()->clone());
    conditionOut->negate();

    for(int idOp : idsOpsAppends) {
        graph->addEdge(makeEdge(idLoop, idOp, conditionOut));
    }
    ctrPtr->setEndBlockId(idsOpsAppends);
    lastNode = NULL;
}

void ProtocolGraph::closingControls_ProcessElse(const std::vector<int> & idsOpsAppends,
                                                int idIf,
                                                const std::vector<int> & localStack,
                                                std::shared_ptr<ControlNode> & lastNode)
{
    for(int idStack: localStack) {
        if (!isControlOperations(idStack)) {
            for(int idOp : idsOpsAppends) {
                graph->addEdge(makeEdge(idStack, idOp, tautology));
            }
        }
    }
    getControlNode(idIf)->setEndBlockId(idsOpsAppends);
    lastNode = NULL;
}

void ProtocolGraph::closingControls_ProcessElif(const std::vector<int> & idsOpsAppends,
                                                int idIf,
                                                const std::vector<int> & localStack,
                                                std::shared_ptr<ControlNode> & lastNode)
{
    for(int idStack: localStack) {
        if (!isControlOperations(idStack)) {
            for(int idOp : idsOpsAppends) {
                graph->addEdge(makeEdge(idStack, idOp, tautology));
            }
        }
    }
    getControlNode(idIf)->setEndBlockId(idsOpsAppends);
    lastNode = getControlNode(idIf);
}

void ProtocolGraph::closingControls_ProcessIf(const std::vector<int> & idsOpsAppends,
                                              int idIf,
                                              const std::vector<int> & localStack,
                                              std::shared_ptr<ControlNode> & lastNode)
{
    if ((lastNode != NULL) &&
        (lastNode->getType() == ControlNode::if_type || lastNode->getType() == ControlNode::elif_type))
    {
        std::shared_ptr<ComparisonOperable> conditionOut(lastNode->getConditionIn()->clone());
        conditionOut->negate();

        for(int idOp : idsOpsAppends) {
            graph->addEdge(makeEdge(lastNode->getContainerId(), idOp, conditionOut));
        }
    }

    for(int idStack: localStack) {
        if (!isControlOperations(idStack)) {
            for(int idOp : idsOpsAppends) {
                graph->addEdge(makeEdge(idStack, idOp, tautology));
            }
        }
    }
    getControlNode(idIf)->setEndBlockId(idsOpsAppends);
    lastNode = getControlNode(idIf);
}
