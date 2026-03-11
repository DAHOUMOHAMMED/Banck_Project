#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;




class clsBanckClient : public clsPerson
{

private:

	enum enMode {EmptyMode = 0 , UpdateMode = 1};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float  _AccountBalance;

	static clsBanckClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBanckClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));

	}

	static clsBanckClient _GetEmptyClientObject()
	{
		return clsBanckClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	clsBanckClient(enMode Mode , string FirstName, string LastName, string Email, string Phone , string AccountNumber,
		string PinCode , float AccountBalance) : clsPerson( FirstName,  LastName,  Email,  Phone)
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
		return _AccountNumber;
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
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	//Property Get
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

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

	static clsBanckClient Find(string AccountNumber)
	{


		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBanckClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}

	static clsBanckClient Find(string AccountNumber , string PassWord)
	{


		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBanckClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PassWord)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBanckClient Client1 = Find(AccountNumber);

		return(!Client1.IsEmpty());
	}
};

