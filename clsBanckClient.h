#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"

using namespace std;




class clsBanckClient : public clsPerson
{

private:

	enum enMode {EmptyMode = 0 , UpdateMode = 1};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	string _AccountBalance;

public:

	clsBanckClient(enMode Mode , string FirstName, string LastName, string Email, string Phone , string AccountNumber,
		string PinCode , string AccountBalance) : clsPerson( FirstName,  LastName,  Email,  Phone)
	{
		_Mode           = Mode;
		_AccountNumber  = AccountNumber;
		_PinCode        = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode = enMode::EmptyMode);
	}

	//Property Get
	string AccountNumber()
	{
		return _PinCode;
	}

	//Property Set
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	//Property Get
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	//Property Set
	void SetAccountBalance(string AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	//Property Get
	string GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) string AccountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n____________________";
		cout << "\nFirst Name : " << FirstName;
		cout << "\nLast  Name : " << LastName;
		cout << "\nFull  Name : " << FullName();
		cout << "\nEmail      : " << Email;
		cout << "\nPhone      : " << Phone;
		cout << "\nAcc Number : " << _AccountNumber;
		cout << "\nPassWord   : " << _PinCode;
		cout << "\nBalance    : " << _AccountBalance;
	}
};

