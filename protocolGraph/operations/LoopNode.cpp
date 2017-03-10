/*
 * ControlNode.cpp
 *
 *  Created on: 23 de mar. de 2016
 *      Author: angel
 */

#include "LoopNode.h"

LoopNode::LoopNode() :
        CPUOperation()
{
	this->conditionIN = std::shared_ptr<ComparisonOperable>();	
}

LoopNode::LoopNode(const LoopNode& obj) :
        CPUOperation(obj)
{
	this->conditionIN = obj.conditionIN;	
}

LoopNode::LoopNode(int containerId, std::shared_ptr<ComparisonOperable> conditionIN) :
        CPUOperation(containerId)
{
	this->conditionIN = conditionIN;
}

LoopNode::~LoopNode() {

}

string LoopNode::toText() {
    return std::to_string(containerID) + "[ label =\"" + LOOP_STRING + "("
			+ conditionIN.get()->toString() + ")\"];";
}

void LoopNode::execute() {
    //debug
}
