/*File: parse.cpp
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: Parses variable names.
 */
#include <cctype> 
#include <iostream> 
#include <sstream>
#include <string> 
using namespace std;
#include "parse.h"

string parseName(stringstream& linestr)
{
	char alnum;
	string name = "";

	linestr >> ws;
	while (isalnum(linestr.peek()))
	{
		linestr >> alnum;
		name += alnum;
	}
	return name;
}