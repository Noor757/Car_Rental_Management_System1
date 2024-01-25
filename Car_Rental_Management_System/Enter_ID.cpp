#ifndef ENTERID
#define ENTERID
#include <iostream>
#include <bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include "Record_Reading_Search.cpp"
using namespace std;
void enter_ID(){
	fstream fout;
	fout.open("Client_Details.csv", ios::out | ios::app);
	string user_ID;
	cout << "\n\n\t\tEnter a 4-digit id number: ";
again:	cin >> user_ID;
	if(readrecordfromfile("Client_Details.csv",user_ID)){
		cout << "\n\n\t\tID number must be unique. Enter again: ";
		goto again;
	}
	cout << "\n\n\t\tThis is your id number for login." << endl;
	fout << user_ID << ",";
}
#endif
