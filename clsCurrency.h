#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "clsString.h"

class clsCurrency
{

	
private:

	enum enMode {EmptyMode = 0 , UpdateMode = 1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;



};

