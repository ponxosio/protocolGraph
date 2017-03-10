/*
 * ProtocolGraph.h
 *
 *  Created on: 9 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_PROTOCOLGRAPH_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_PROTOCOLGRAPH_H_

#include <string>

//data structures
#include <vector>
#include <unordered_set>
#include <unordered_map>

//local
#include <graph/Graph.h>
#include <utils/AutoEnumerate.h>
#include <utils/units.h>

#include "protocolGraph/operables/VariableTable.h"
#include "protocolGraph/operables/mathematics/ArithmeticOperation.h"
#include "protocolGraph/operables/mathematics/VariableEntry.h"

#include "protocolGraph/operations/AssignationOperation.h"
#include "protocolGraph/operations/cpuoperation.h"
#include "protocolGraph/operations/DivergeNode.h"
#include "protocolGraph/operations/LoopNode.h"

#include "protocolGraph/operations/container/ApplyLight.h"
#include "protocolGraph/operations/container/ApplyTemperature.h"
#include "protocolGraph/operations/container/ContainerOperation.h"
#include "protocolGraph/operations/container/GetVolume.h"
#include "protocolGraph/operations/container/LoadContainerOperation.h"
#include "protocolGraph/operations/container/MeasureOD.h"
#include "protocolGraph/operations/container/Mix.h"
#include "protocolGraph/operations/container/SetContinousFlow.h"
#include "protocolGraph/operations/container/settimestep.h"
#include "protocolGraph/operations/container/Stir.h"
#include "protocolGraph/operations/container/TimeStep.h"
#include "protocolGraph/operations/container/Transfer.h"

#include "protocolGraph/ConditionEdge.h"

#include "protocolGraph/protocolgraph_global.h"

/**
 * @brief The ProtocolGraph class
 */
class PROTOCOLGRAPH_EXPORT ProtocolGraph {
public:
	//TYPE DEFS
    typedef Graph<Node, ConditionEdge>::NodeTypePtr ProtocolNodePtr;
    typedef Graph<Node, ConditionEdge>::EdgeTypePtr ProtocolEdgePtr;

    typedef Graph<Node, ConditionEdge>::NodeVector ProtocolNodeVector;
    typedef Graph<Node, ConditionEdge>::EdgeVector ProtocolEdgeVector;

    typedef Graph<Node, ConditionEdge>::NodeVectorPtr ProtocolNodeVectorPtr;
    typedef Graph<Node, ConditionEdge>::EdgeVectorPtr ProtocolEdgeVectorPtr;

    typedef Graph<Node, ConditionEdge>::NodeMapPtr ProtocolNodeMapPtr;
	//

	ProtocolGraph();
	ProtocolGraph(const ProtocolGraph & prot);
	ProtocolGraph(const std::string & name);
	virtual ~ProtocolGraph();

    int emplaceAssignation(const std::string & receiver, std::shared_ptr<MathematicOperable> value);
    int emplaceDivergence(std::shared_ptr<ComparisonOperable> conditionIN);
    int emplaceLoop(std::shared_ptr<ComparisonOperable> conditionIN);

    int emplaceApplyLight(int sourceID,
                          std::shared_ptr<MathematicOperable> wavelength,
                          units::Frequency wavelengthUnits,
                          std::shared_ptr<MathematicOperable> intensity,
                          units::LuminousIntensity intensityUnits);

    int emplaceApplyTemperature(int sourceId,
                                std::shared_ptr<MathematicOperable> temperature,
                                units::Temperature temperatureUnits);

    int emplaceGetVirtualVolume(int sourceId, const std::string & receiver);
    int emplaceLoadContainer(int idSource, std::shared_ptr<MathematicOperable> volume, units::Volume volumeUnits);
    int emplaceMeasureOD(int sourceId,
                         const std::string & receiver,
                         std::shared_ptr<MathematicOperable> duration,
                         units::Time durationUnits,
                         std::shared_ptr<MathematicOperable> measurmentFrequency,
                         units::Frequency measurmentFrequencyUnits,
                         std::shared_ptr<MathematicOperable> wavelength,
                         units::Frequency wavelengthUnits);

    int emplaceMix(int idSource1,
                   int idSource2,
                   int idTarget,
                   std::shared_ptr<MathematicOperable> volume1,
                   units::Volume volume1Units,
                   std::shared_ptr<MathematicOperable> volume2,
                   units::Volume volume2Units);

    int emplaceSetContinuousFlow(int idSource,
                                 int idTarget,
                                 std::shared_ptr<MathematicOperable> rate,
                                 units::Volumetric_Flow rateUnits);

    int emplaceSetTimeStep(std::shared_ptr<MathematicOperable> timeSlice, units::Time timeUnits);
    int emplaceStir(int sourceId, std::shared_ptr<MathematicOperable> intensity, units::Frequency intensityUnits);
    int emplaceTimeStep();
    int emplaceTransfer(int idSource, int idTarget, std::shared_ptr<MathematicOperable> volume, units::Volume volumeUnits);

    void connectOperation(int idSource, int idTarget, std::shared_ptr<ComparisonOperable> comparison);

	ProtocolNodePtr getStart();
	void setStartNode(int idStart);

    void clearVarTable();
    const std::shared_ptr<VariableEntry> & getTimeVariable() const;
    std::shared_ptr<VariableEntry> getVariable(const std::string & name);

    std::shared_ptr<CPUOperation> getCpuOperation(int idNode) throw(std::invalid_argument);
    std::shared_ptr<ActuatorsOperation> getActuatorOperation(int idNode) throw(std::invalid_argument);

    inline bool isCpuOperation(int idNode) {
        auto finded = cpuOperations.find(idNode);
        return (finded == cpuOperations.end());
    }
    inline bool isActuatorOperation(int idNode) {
        auto finded = actuatorsOperations.find(idNode);
        return (finded == actuatorsOperations.end());
    }
    inline const ProtocolEdgeVectorPtr getProjectingEdges(int idNode) const {
		return graph->getLeavingEdges(idNode);
	}
    inline typename ProtocolNodeMapPtr getAllNodes() const {
		return graph->getAllNodes();
	}
	inline void printProtocol(const std::string & path) {
		graph->saveGraph(path);
	}
	inline const std::string& getName() const {
		return name;
	}
protected:
	int idStart;
	std::string name;
    std::shared_ptr<Graph<Node, ConditionEdge>> graph;

    AutoEnumerate nodeSerie;
    std::shared_ptr<VariableTable> varTable;
    std::unordered_set<int> cpuOperations;
    std::unordered_set<int> actuatorsOperations;
    std::unordered_map<std::string, std::shared_ptr<VariableEntry>> varEntryTable;

    std::shared_ptr<VariableEntry> timeVariable;

	ProtocolEdgePtr makeEdge(int idSource, int idTarget, std::shared_ptr<ComparisonOperable> comparison);
    std::shared_ptr<VariableEntry> getVariableEntry(const std::string & varName);
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_PROTOCOLGRAPH_H_ */
