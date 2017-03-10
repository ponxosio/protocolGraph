/*
 * DivergeNode.cpp
 *
 *  Created on: 11 de abr. de 2016
 *      Author: angel
 */

#include "DivergeNode.h"

DivergeNode::DivergeNode() :
        CPUOperation()
{
	this->conditionIN = std::shared_ptr<ComparisonOperable>();
}

DivergeNode::DivergeNode(const DivergeNode& node) :
        CPUOperation(node)
{
	this->conditionIN = node.conditionIN;
}

DivergeNode::DivergeNode(int containerId, std::shared_ptr<ComparisonOperable> conditionIN) :
        CPUOperation(containerId)
{
	this->conditionIN = conditionIN;
}

DivergeNode::~DivergeNode() {}

string DivergeNode::toText() {
    return std::to_string(containerID) + "[ label =\"" + DIVERGE_STRING + "("
			+ conditionIN.get()->toString() + ")\"];";
}

void DivergeNode::execute() {
    //
}
