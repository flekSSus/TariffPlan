#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include "Person.h"
#include "Tariff.h"

using namespace std;

class TPlan
{
private:

	unsigned int _numberOfClients=0;
	unsigned int _countOfTariffs = 0;
	string _sourceFileClient;
	string _sourceFileTariff;
	Person* Clients = new Person[100];
	Tariff* Tariffs = new Tariff[100];


	void ReadFile();
	void SortByTime(int monotone=1);
	void SortByName(int monotone = 1);
	string MinPlan(Person&client);


public:

	TPlan();
	TPlan(string sourceFileClient,string sourceFileTariff);
	~TPlan();

	void WriteOutside();
	void WriteOutside(string Output);
	string GetFileName();
	unsigned int GetNumOfClients();
	void ShowInfo();
	
	

	friend istream& operator>>(istream& in, TPlan& obj);
};