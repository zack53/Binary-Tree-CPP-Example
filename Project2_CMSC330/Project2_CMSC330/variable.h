/*File: variable.h
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: Variable returns a value for the variable.
 */
#pragma once
class Variable : public Operand
{
public:
	Variable(string name)
	{
		this->name = name;
	}
	int evaluate();
private:
	string name;
};