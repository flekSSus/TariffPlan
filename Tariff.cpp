#include "Tariff.h"


void Tariff::SetTariffName(string tariffName)
{
	_tariffName = tariffName;
}

void Tariff::SetSMSCost(double smsCost)
{
	if (smsCost>=0)
	{
		_smsCost = smsCost;
	}
	else
	{
		_smsCost = 0;
	}
}

void Tariff::SetTalkTimeCost(double talkTimeCost)
{
	if (talkTimeCost>=0)
	{
		_talkTimeCost = talkTimeCost;
	}
	else
	{
		_talkTimeCost = 0;
	}
}

void Tariff::SetFreeMinutes(double freeMinutes)
{
	if (freeMinutes>=0)
	{
		_freeMinutes = freeMinutes;
	}
	else
	{
		_freeMinutes = 0;
	}
}

string Tariff::GetTariffName()
{
	return _tariffName;
}

double Tariff::GetSMSCost()
{
	return _smsCost;
}

double Tariff::GetTalkTimeCost()
{
	return _talkTimeCost;
}

double Tariff::GetFreeMinutes()
{
	return _freeMinutes;
}

Tariff::Tariff()
{
	_tariffName = "no info";
	_smsCost = 0;
	_talkTimeCost = 0;
	_freeMinutes = 0;
}

Tariff::Tariff(string tariffName, double smsCost, double talkTimeCost, double freeMinutes)
{
	_tariffName = tariffName;
	_smsCost = smsCost;
	_talkTimeCost = talkTimeCost;
	_freeMinutes = freeMinutes;
}

ostream& operator<<(ostream& out, const Tariff& obj)
{
	cout << obj._tariffName << " " << obj._smsCost << " " << obj._talkTimeCost << " " << obj._freeMinutes << " " << endl;
	return out;
}
