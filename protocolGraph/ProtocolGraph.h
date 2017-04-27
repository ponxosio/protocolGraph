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
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <vector>

//local
#include <graph/Graph.h>
#include <utils/AutoEnumerate.h>
#include <utils/units.h>

#include "protocolGraph/container/virtualcontainer.h"

#include "protocolGraph/operables/VariableTable.h"
#include "protocolGraph/operables/comparison/Tautology.h"
#include "protocolGraph/operables/mathematics/ArithmeticOperation.h"
#include "protocolGraph/operables/mathematics/VariableEntry.h"

#include "protocolGraph/operations/AssignationOperation.h"
#include "protocolGraph/operations/cpuoperation.h"
#include "protocolGraph/operations/controlnode.h"

#include "protocolGraph/operations/container/ApplyLight.h"
#include "protocolGraph/operations/container/ApplyTemperature.h"
#include "protocolGraph/operations/container/actuatorsoperation.h"
#include "protocolGraph/operations/container/finishableoperation.h"
#include "protocolGraph/operations/container/finishoperation.h"
#include "protocolGraph/operations/container/GetVolume.h"
#include "protocolGraph/operations/container/LoadContainerOperation.h"
#include "protocolGraph/operations/container/MeasureOD.h"
#include "protocolGraph/operations/container/Mix.h"
#include "protocolGraph/operations/container/SetContinousFlow.h"
#include "protocolGraph/operations/container/stopcontinuosflow.h"
#include "protocolGraph/operations/container/settimestep.h"
#include "protocolGraph/operations/container/Stir.h"
#include "protocolGraph/operations/container/TimeStep.h"
#include "protocolGraph/operations/container/Transfer.h"

#include "protocol_graph_utils/controlstackelement.h"

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
    int emplaceApplyLight(const std::string & sourceID,
                          std::shared_ptr<MathematicOperable> wavelength,
                          units::Length wavelengthUnits,
                          std::shared_ptr<MathematicOperable> intensity,
                          units::LuminousIntensity intensityUnits);

    int emplaceApplyTemperature(const std::string & sourceId,
                                std::shared_ptr<MathematicOperable> temperature,
                                units::Temperature temperatureUnits);

    int emplaceGetVirtualVolume(const std::string & sourceId, const std::string & receiver);
    int emplaceLoadContainer(const std::string & idSource, std::shared_ptr<MathematicOperable> volume, units::Volume volumeUnits);
    int emplaceMeasureOD(const std::string & sourceId,
                         const std::string & receiver,
                         std::shared_ptr<MathematicOperable> duration,
                         units::Time durationUnits,
                         std::shared_ptr<MathematicOperable> measurmentFrequency,
                         units::Frequency measurmentFrequencyUnits,
                         std::shared_ptr<MathematicOperable> wavelength,
                         units::Length wavelengthUnits);

    int emplaceMix(const std::string & idSource1,
                   const std::string & idSource2,
                   const std::string & idTarget,
                   std::shared_ptr<MathematicOperable> volume1,
                   units::Volume volume1Units,
                   std::shared_ptr<MathematicOperable> volume2,
                   units::Volume volume2Units);

    int emplaceStopContinuousFlow(const std::string & idSource, const std::string & idTarget);
    int emplaceSetContinuousFlow(const std::string & idSource,
                                 const std::string & idTarget,
                                 std::shared_ptr<MathematicOperable> rate,
                                 units::Volumetric_Flow rateUnits);

    int emplaceSetTimeStep(std::shared_ptr<MathematicOperable> timeSlice, units::Time timeUnits);
    int emplaceStir(const std::string & sourceId, std::shared_ptr<MathematicOperable> intensity, units::Frequency intensityUnits);
    int emplaceTimeStep();
    int emplaceTransfer(const std::string & idSource,
                        const std::string & idTarget,
                        std::shared_ptr<MathematicOperable> volume,
                        units::Volume volumeUnits);

    int emplaceFinishOperation(int finsihOperationId) throw(std::invalid_argument);

    void startIfBlock(std::shared_ptr<ComparisonOperable> condition);
    void startElIfBlock(std::shared_ptr<ComparisonOperable> condition) throw(std::runtime_error);
    void startElseBlock() throw(std::runtime_error);
    void endIfBlock() throw(std::runtime_error);

    void startLoopBlock(std::shared_ptr<ComparisonOperable> condition);
    void endLoopBlock() throw(std::runtime_error);

    void appendOperations(int idOpAppend);
    void appendOperations(const std::vector<int> & idsOpsAppends);
    void appendOperations(const std::vector<int> & sourcesAppend, const std::vector<int> & targetsAppends) throw(std::runtime_error);

	ProtocolNodePtr getStart();
	void setStartNode(int idStart);

    void clearVarTable();
    const std::shared_ptr<VariableEntry> & getTimeVariable() const;
    std::shared_ptr<VariableEntry> getVariable(const std::string & name);

    std::shared_ptr<CPUOperation> getCpuOperation(int idNode) throw(std::invalid_argument);
    std::shared_ptr<ControlNode> getControlNode(int idNode) throw(std::invalid_argument);
    std::shared_ptr<ActuatorsOperation> getActuatorOperation(int idNode) throw(std::invalid_argument);

    std::shared_ptr<VirtualContainer> getVContainer(const std::string & vcName) const;
    bool addVContainer(const std::string & name,
                       VirtualContainer::ContainerType vcType,
                       units::Volume capacity,
                       units::Volume initialVolume,
                       units::Temperature storeTemperature);

    inline bool hasVContainer(const std::string & name) const {
        return (vcontainerMap.find(name) != vcontainerMap.end());
    }

    inline bool isCpuOperation(int idNode) {
        auto finded = cpuOperations.find(idNode);
        return (finded != cpuOperations.end());
    }
    inline bool isControlOperations(int idNode) {
        auto finded = controlOperations.find(idNode);
        return (finded != controlOperations.end());
    }
    inline bool isActuatorOperation(int idNode) {
        auto finded = actuatorsOperations.find(idNode);
        return (finded != actuatorsOperations.end());
    }

    inline const std::unordered_set<int> & getCpuOperations() const {
        return cpuOperations;
    }
    inline const std::unordered_set<int> & getActuatorsOperations() const {
        return actuatorsOperations;
    }
    inline const std::unordered_set<int> & getControlOperations() const {
        return controlOperations;
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
    inline std::string toString() const {
        return graph->toString();
    }
protected:
	int idStart;
	std::string name;
    std::shared_ptr<Graph<Node, ConditionEdge>> graph;

    AutoEnumerate nodeSerie;
    std::shared_ptr<VariableTable> varTable;
    std::unordered_set<int> cpuOperations;
    std::unordered_set<int> actuatorsOperations;
    std::unordered_set<int> controlOperations;
    std::unordered_map<std::string, std::shared_ptr<VariableEntry>> varEntryTable;
    std::unordered_map<std::string, std::shared_ptr<VirtualContainer>> vcontainerMap;

    std::vector<ControlStackElement> controlStack;
    std::vector<ControlStackElement> closingControlElms;
    std::vector<int> mainStack;

    std::shared_ptr<Tautology> tautology;
    std::shared_ptr<VariableEntry> timeVariable;

    ProtocolEdgePtr makeEdge(int idSource, int idTarget, std::shared_ptr<ComparisonOperable> comparison);
    std::shared_ptr<VariableEntry> getVariableEntry(const std::string & varName);

    std::vector<int> & getActiveAppendableNodes();
    std::shared_ptr<ComparisonOperable> getActualCondition();

    bool checkControlStackIsPhysical();

    bool checkClosingElemsNeedProcessing();
    void linkClosingStack(ControlStackElement & element);

    void appendToClosingControls(const std::vector<int> & idsOpsAppends, std::vector<ControlStackElement> & closingStack);
    void closingControls_ProcessLoop(const std::vector<int> & idsOpsAppends, int idLoop, std::shared_ptr<ControlNode> & lastNode);
    void closingControls_ProcessElse(const std::vector<int> & idsOpsAppends,
                                     int idIf,
                                     const std::vector<int> & localStack,
                                     std::shared_ptr<ControlNode> & lastNode);
    void closingControls_ProcessElif(const std::vector<int> & idsOpsAppends,
                                     int idIf,
                                     const std::vector<int> & localStack,
                                     std::shared_ptr<ControlNode> & lastNode);
    void closingControls_ProcessIf(const std::vector<int> & idsOpsAppends,
                                   int idIf,
                                   const std::vector<int> & localStack,
                                   std::shared_ptr<ControlNode> & lastNode);
};
#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_PROTOCOLGRAPH_H_ */
