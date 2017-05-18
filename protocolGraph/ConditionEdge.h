/*
 * ConditionEdge.h
 *
 *  Created on: 15 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_FLUIDCONTROL_PROTOCOLGRAPH_CONDITIONEDGE_H_
#define SRC_FLUIDCONTROL_PROTOCOLGRAPH_CONDITIONEDGE_H_

#include <graph/Edge.h>
#include <utils/Utils.h>

//local
#include "protocolGraph/operables/comparison/ComparisonOperable.h"

#include "protocolGraph/protocolgraph_global.h"

/**
 * Represents an edge in a graph that has a condition, the edge can not be used until the condition is met.
 */
class CONDITIONEDGE_EXPORT ConditionEdge: public Edge {
public:
	//Obligatory constructors if is derived from NODE
	ConditionEdge();
	ConditionEdge(const ConditionEdge & edge);
	//
	/**
	 * Makes internal copies of leftVariable and rightVariable
	 * @param comparison comparison operation that must be met in order to use this edge
	 */
	ConditionEdge(int idSource, int idTarget, std::shared_ptr<ComparisonOperable> comparison);
	virtual ~ConditionEdge();

	/**
	 * Checks if the condition to use this edge is met
	 * @return true if the condition is met, false otherwise
	 */
	bool conditionMet();
	/**
	 * Checks if the condition uses physical values
	 * @return true if uses physical variables, false otherwise
	 */
	bool isPhyscal();
	/**
	 * Checks if this edge has certain condition
	 * @param comparison condition to be checked
	 * @return true if this edge has the same condition, false otherwise
	 */
	bool hasCondition(ComparisonOperable* comparison);

	//OVERRIDEN METHODS
	/**
	 * Compares two edges
	 *
	 * @param e other edge to compare
	 * @return true if the edges are equal, false otherwise
	 */
    virtual bool equals(const Edge& e) const;

	virtual std::string toText();

    inline bool operator== ( const ConditionEdge & n) const
    {
            return this->equals(n);
    }
protected:
	std::shared_ptr<ComparisonOperable> comparison;

};

#endif /* SRC_FLUIDCONTROL_PROTOCOLGRAPH_CONDITIONEDGE_H_ */
