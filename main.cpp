﻿#include <iostream>
#include"TPlan.h"

using namespace std;

int main()
{
    TPlan work("Client.txt","Tplan.txt");
    //work.WriteOutside();
    //cin >> work;
    work.ShowInfo();
}