#include "TPlan.h"



void TPlan::ReadFile()
{
	ifstream finC(_sourceFileClient),finT(_sourceFileTariff);
	try 
	{
		if (!(finC.is_open()&&finT.is_open()))
		{
			throw "Error. File is not opened";
		}
	}
	catch (...)
	{
		cout << "Error. File is not opened"<<endl;
	}


	string tmpS;
	unsigned int tmpI;
	double tmpD;

	for (int i = 0; i <= 100 && !finC.eof(); i++)
	{
		finC >> tmpS;
		tmpS += " ";
		Clients[i].SetNameS(tmpS);
		finC >> tmpS;
		Clients[i].SetNameS(tmpS);
		finC >> tmpS;
		tmpI = (unsigned int)stoi(tmpS);
		Clients[i].SetNumOfSMS(tmpI);
		finC >> tmpS;
		tmpI = (unsigned int)stoi(tmpS);
		Clients[i].SetTalkTime(tmpI);
		_numberOfClients++;
	}

	finT >> _countOfTariffs;
	for (unsigned int i = 0; i < _countOfTariffs; i++)
	{
		finT >> tmpS;
		Tariffs[i].SetTariffName(tmpS);
		finT >> tmpD;
		Tariffs[i].SetSMSCost(tmpD);
		finT >> tmpD;
		Tariffs[i].SetTalkTimeCost(tmpD);
		finT >> tmpD;
		Tariffs[i].SetFreeMinutes(tmpD);
	}

}

string TPlan::MinPlan(Person& client)
{
		double* arrPrices = new double[_countOfTariffs];

		for (unsigned int i = 0; i < _countOfTariffs; i++)
		{
			arrPrices[i] = client.GetNumOfSMS() * Tariffs[i].GetSMSCost();
			if (client.GetTalkTime()>= Tariffs[i].GetFreeMinutes())
			{
				arrPrices[i] += (client.GetTalkTime()-Tariffs[i].GetFreeMinutes()) * Tariffs[i].GetTalkTimeCost();
			}
			if (arrPrices[i]<0)
			{
				arrPrices[i] = 0;
			}
		}

		client.SetCost(arrPrices[0]);
		int minPriceIndex=0;
		for (unsigned int i = 1; i < _countOfTariffs; i++)
		{
			if (arrPrices[i]<client.GetCost())
			{
				client.SetCost(arrPrices[i]);
				minPriceIndex = i;
			}
		}
		delete[]arrPrices;
		return Tariffs[minPriceIndex].GetTariffName();
}

void TPlan::ShowInfo()
{
	for (unsigned int i = 0; i < _numberOfClients; i++)
	{
		cout << Clients[i] << endl;
	}
	cout << "_________________________________" << endl<<endl;
}

void TPlan::WriteOutside()
{
	ofstream fout;

	fout.open("SClients.txt");

	if (fout.is_open())
	{
		for (unsigned int i = 0; i < _numberOfClients; i++)
		{
			fout << Clients[i].GetName() << " " << Clients[i].GetNumOfSMS() << " " << Clients[i].GetTalkTime() << " " << endl;
		}
	}

	fout.close();
}

void TPlan::WriteOutside(string Output)
{
	ofstream fout;

	fout.open("SClients.txt");

	if (fout.is_open())
	{
		for (unsigned int i = 0; i < _numberOfClients; i++)
		{
			fout << Clients[i].GetName() << " " << Clients[i].GetNumOfSMS() << " " << Clients[i].GetTalkTime() << " " << endl;
		}
	}

	fout.close();
}

void TPlan::SortByTime(int monotone)
{
	int *arr = new int[_numberOfClients];
	for (unsigned int i = 0; i < _numberOfClients; i++)
	{
		arr[i] = Clients[i].GetTalkTime();
	}

	for (unsigned int i = 0; i < _numberOfClients; i++)
	{
		for (unsigned int j = 0; j < _numberOfClients; j++)
		{
			if (monotone>=0)
			{
				if (arr[i] > arr[j])
				{
					swap(arr[j], arr[i]);
					swap(Clients[j], Clients[i]);
				}
			}
			else
			{
				if (arr[i]<arr[j])
				{
					swap(arr[j], arr[i]);
					swap(Clients[j], Clients[i]);
				}
			}
			
		}
	}
	WriteOutside();
	//ShowInfo();

	delete[] arr;
}

void TPlan::SortByName(int monotone)
{
	for (unsigned int i = 0; i < _numberOfClients; i++)
	{
		for (unsigned int j = i; j < _numberOfClients; j++)
		{
			for (int k = 0;Clients[i].GetName()[k]; k++)
			{
				if (Clients[j].GetName()[k]<Clients[i].GetName()[k])
				{
					swap(Clients[j],Clients[i]);
					break;
				}
				else if (Clients[j].GetName()[k]> Clients[i].GetName()[k])
				{
					break;
				}
			}
			
		}
	}
}

TPlan::TPlan()
{	
	_numberOfClients = 0;
	_sourceFileClient = "no data";
	_sourceFileTariff = "no data";
	SortByTime();
}

TPlan::TPlan(string sourceFileClient,string sourceFileTariff)
{
	_numberOfClients = 0;
	_sourceFileClient = sourceFileClient;
	_sourceFileTariff = sourceFileTariff;
	ReadFile();
	SortByTime();
	for (unsigned int i = 0; i < _numberOfClients; i++)
	{
		Clients[i].SetBestTariff(MinPlan(Clients[i]));
	}
	SortByName();
}

TPlan::~TPlan()
{
	delete[] Clients;
	delete[] Tariffs;
}

string TPlan::GetFileName()
{
	return _sourceFileClient;
}

unsigned int TPlan::GetNumOfClients()
{
	return _numberOfClients;
}

istream& operator>>(istream& in, TPlan& obj)
{
	cin >> obj._sourceFileClient;
	obj.ReadFile();
	return in;
}
