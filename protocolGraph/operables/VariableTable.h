/*
 * VariableTable.h
 *
 *  Created on: 15 de mar. de 2016
 *      Author: angel
 */

#ifndef SRC_OPERABLES_VARIABLETABLE_H_
#define SRC_OPERABLES_VARIABLETABLE_H_

/**** TIME VARIABLE ****/
#define TIME_VARIABLE "actualTime"

#include <string>
#include <stdexcept>
#include <memory>

// data structures
#include <tuple>
#include <unordered_map>

#include "protocolGraph/protocolgraph_global.h"

/**
 * Class that implements an associative table where the value of the declared variables in a protocol will be stored.
 *
 * Also each variable has a flag that tells if the variable is used to store a physical property of the machine.
 *
 * Also has methods to serialize and deserialize the object in order to store it at the disk.
 */
class VARIABLETABLE_EXPORT VariableTable {
public:
	VariableTable();
    VariableTable(const VariableTable & varTable);
	virtual ~VariableTable();

	/**
	 * Returns the value of the table entry, throws an invalid argument exception if the entry does not exists
	 * @param name key of the entry
	 * @return the value of that entry
	 */
	double getVaue(const std::string & name) throw (std::invalid_argument);
	/**
	 * Returns if a variable stores physical data.
	 * @param name of the variable
	 * @return true if te variable stores physical data, false otherwise
	 */
	bool getPhysical(const std::string & name) throw (std::invalid_argument);
	/**
	 * Change the value of a given entry of the table, creating it if the name does not exists
	 * @param name key of the entry to be changed
	 * @param value new value of the entry
	 */
	void setValue(const std::string & name, double value);
	/**
	 * Set the physical operation of the variable
	 * @param name of the variable to change
	 * @param physical flag that indicates that a variable stores a physical property of the machine
	 */
	void setPhysical(const std::string & name, bool physical);
	/**
	 * Clears all variables at the table
	 */
	inline void clear() {table.clear();}
    /**
     * @brief containsKey checks if a key already exist in the table
     * @param key string with the variable name
     * @return true if the variable already exists, false in o.c
     */
	inline bool containsKey(const std::string & key)
	{
		return (table.find(key) != table.end());
	}
protected:
	std::unordered_map<std::string, std::tuple<double,bool>> table;
};
#endif /* SRC_OPERABLES_VARIABLETABLE_H_ */
