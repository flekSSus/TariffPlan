#include "Person.h"

void Person::SetName(string name)
{
	_name = name;
}

void Person::SetNameS(string name)
{
	_name += name;
}

void Person::SetTalkTime(unsigned int talkTime)
{
	_talkTime = talkTime;
}

void Person::SetNumOfSMS(unsigned int numberOfSMS)
{
	_numberOfSMS = numberOfSMS;
}

void Person::SetBestTariff(string bestTariff)
{
	_bestTariff = bestTariff;
}

void Person::SetCost(double minCost)
{
	_minCost = minCost;
}

double Person::GetCost()
{
	return _minCost;
}

string Person::GetName()
{
	return _name;
}

string Person::GetBestTariff()
{
	return _bestTariff;
}

unsigned int Person::GetTalkTime()
{
	return _talkTime;
}

unsigned int Person::GetNumOfSMS()
{
	return _numberOfSMS;
}

Person::Person()
{
	_name = "";
	_numberOfSMS = 0;
	_talkTime = 0;
}

Person::Person(string name, unsigned int numberOfSMS, unsigned int talkTime)
{
	_name = name;
	_numberOfSMS = numberOfSMS;
	_talkTime = talkTime;
}

ostream& operator<<(ostream& out, const Person& obj)
{
	cout <<"Name : "<< obj._name<<" | "<<"SMS : " << obj._numberOfSMS<<" | "<< "Talk time : " << obj._talkTime<<" | "<<"Best tariff : "<<obj._bestTariff << " | " <<"Cost : "<<obj._minCost<< endl;
	return out;
}
