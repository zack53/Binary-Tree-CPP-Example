/*File: symboltable.h
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: Symboltable stores variables with values.
 */
#pragma once
class SymbolTable
{
public:
	SymbolTable() {}
	void insert(string variable, int value);
	int lookUp(string variable) const;
	void resetElement();
private:
	struct Symbol
	{
		Symbol(string variable, int value)
		{
			this->variable = variable;
			this->value = value;
		}
		string variable;
		int value;
	};
	vector <Symbol> elements;
};