#pragma once

#include <string>
#include <iostream>

using namespace std;

class Tariff
{
private:

	string _tariffName;
	double _smsCost;
	double _talkTimeCost;
	double _freeMinutes;

public:

	Tariff();
	Tariff(string tariffName,double smsCost, double talkTimeCost, double freeMinutes);

	void SetTariffName(string tariffName);
	void SetSMSCost(double smsCost);
	void SetTalkTimeCost(double talkTimeCost);
	void SetFreeMinutes(double freeMinutes);
	string GetTariffName();
	double GetSMSCost();
	double GetTalkTimeCost();
	double GetFreeMinutes();

	friend ostream& operator<<(ostream& out, const Tariff& obj);
	
};

