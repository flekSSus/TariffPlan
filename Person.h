#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person
{
private:

	string _name;
	string _bestTariff = "none";
	unsigned int _numberOfSMS;
	unsigned int _talkTime;
	double _minCost=0;

public:

	Person();
	Person(string name, unsigned int numberOfSMS, unsigned int talkTime);


	void SetName(string name);
	void SetNameS(string name);
	void SetTalkTime(unsigned int talkTime);
	void SetNumOfSMS(unsigned int numberOfSMS);
	void SetBestTariff(string bestTariff);
	void SetCost(double minCost);
	double GetCost();
	string GetName();
	string GetBestTariff();
	unsigned int GetTalkTime();
	unsigned int GetNumOfSMS();
	

	friend ostream& operator<<(ostream& out, const Person& obj);
};

ostream& operator<<(ostream& out, const Person& obj);
