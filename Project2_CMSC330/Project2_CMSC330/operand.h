/*File: operand.h
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: Creates an operand as a literal or as a variable.
 */
#pragma once
class Operand : public Expression
{
public:
	static Expression* parse(stringstream& linestr);
};