/*File: symboltable.cpp
 *Author: Zackary Scott 
 *Date: 7-12-2018
 *Purpose: Symboltable stores variables with values.
 */
#include <string> 
#include <vector> 
using namespace std;
#include "symboltable.h"


void SymbolTable::insert(string variable, int value)
{
	const Symbol& symbol = Symbol(variable, value);
	elements.push_back(symbol);
}

int SymbolTable::lookUp(string variable) const
{
	for (int i = 0; i < elements.size(); i++)
		if (elements[i].variable == variable)
			return elements[i].value;
	return -1;
}
void SymbolTable::resetElement()
{
	if (elements.size() > 0)
	{
		for (int i = elements.size(); i > 0; i--) {
			elements.pop_back();
		}
	}
}