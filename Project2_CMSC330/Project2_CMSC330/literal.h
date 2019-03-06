/*File: literal.h
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: Holds the value of the variable
 */
#pragma once
class Literal : public Operand
{
public:
	Literal(int value)
	{
		this->value = value;
	}
	int evaluate()
	{
		return value;
	}
private:
	int value;
};