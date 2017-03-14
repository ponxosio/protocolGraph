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
}

ProtocolGraph::ProtocolGraph(const ProtocolGraph & prot) :
    varTable(prot.varTable),
    nodeSerie(prot.nodeSerie),
    cpuOperations(prot.cpuOperations),
    actuatorsOperations(prot.actuatorsOperations),
    varEntryTable(prot.varEntryTable)
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
}

ProtocolGraph::~ProtocolGraph() {}

int ProtocolGraph::emplaceAssignation(const std::string & receiver, std::shared_ptr<MathematicOperable> value) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<VariableEntry> receiverPtr = getVariableEntry(receiver);
    std::shared_ptr<Node> nodePtr = std::make_shared<AssignationOperation>(nextId, receiverPtr, value);
    graph->addNode(nodePtr);

    cpuOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceDivergence(std::shared_ptr<ComparisonOperable> conditionIN) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<DivergeNode>(nextId, conditionIN);
    graph->addNode(nodePtr);

    cpuOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceLoop(std::shared_ptr<ComparisonOperable> conditionIN) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<LoopNode>(nextId, conditionIN);
    graph->addNode(nodePtr);

    cpuOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceApplyLight(
        int sourceID,
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
        int sourceId,
        std::shared_ptr<MathematicOperable> temperature,
        units::Temperature temperatureUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<ApplyTemperature>(nextId, sourceId, temperature, temperatureUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceGetVirtualVolume(int sourceId, const std::string & receiver) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<VariableEntry> receiverPtr = getVariableEntry(receiver);
    std::shared_ptr<Node> nodePtr = std::make_shared<GetVolume>(nextId, sourceId, receiverPtr);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceLoadContainer(int idSource, std::shared_ptr<MathematicOperable> volume, units::Volume volumeUnits) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<LoadContainerOperation>(nextId, idSource, volume, volumeUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceMeasureOD(
        int sourceId,
        const std::string & receiver,
        std::shared_ptr<MathematicOperable> duration,
        units::Time durationUnits,
        std::shared_ptr<MathematicOperable> measurmentFrequency,
        units::Frequency measurmentFrequencyUnits,
        std::shared_ptr<MathematicOperable> wavelength,
        units::Length wavelengthUnits)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<VariableEntry> receiverPtr = getVariableEntry(receiver);
    std::shared_ptr<Node> nodePtr = std::make_shared<MeasureOD>(nextId, sourceId, receiverPtr, duration, durationUnits, measurmentFrequency,
                                                                measurmentFrequencyUnits, wavelength, wavelengthUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceMix(
        int idSource1,
        int idSource2,
        int idTarget,
        std::shared_ptr<MathematicOperable> volume1,
        units::Volume volume1Units,
        std::shared_ptr<MathematicOperable> volume2,
        units::Volume volume2Units)
{
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<Mix>(nextId, idSource1, idSource2, idTarget, volume1, volume1Units, volume2, volume2Units);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
}

int ProtocolGraph::emplaceSetContinuousFlow(
        int idSource,
        int idTarget,
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

int ProtocolGraph::emplaceStir(int sourceId, std::shared_ptr<MathematicOperable> intensity, units::Frequency intensityUnits) {
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

int ProtocolGraph::emplaceTransfer(int idSource, int idTarget, std::shared_ptr<MathematicOperable> volume, units::Volume volumeUnits) {
    int nextId = nodeSerie.getNextValue();

    std::shared_ptr<Node> nodePtr = std::make_shared<Transfer>(nextId, idSource, idTarget, volume, volumeUnits);
    graph->addNode(nodePtr);

    actuatorsOperations.insert(nextId);
    return nextId;
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

void ProtocolGraph::connectOperation(int idSource, int idTarget, std::shared_ptr<ComparisonOperable> comparison) {
    graph->addEdge(makeEdge(idSource, idTarget, comparison));
}

ProtocolGraph::ProtocolNodePtr ProtocolGraph::getStart() {
	return graph->getNode(idStart);
}

void ProtocolGraph::setStartNode(int idStart) {
	this->idStart = idStart;
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






