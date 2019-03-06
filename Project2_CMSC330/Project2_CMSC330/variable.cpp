/*File: variable.cpp
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: Variable returns a value for the variable.
 */
#include <strstream>
#include <vector>
using namespace std;
#include "expression.h"
#include "operand.h"
#include "variable.h"
#include "symboltable.h"

extern SymbolTable symbolTable;

int Variable::evaluate()
{
	return symbolTable.lookUp(name);
}