#ifndef REGISTER
#define REGISTER
#include <iostream>
#include <bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include "Enter_ID.cpp"
using namespace std;
void Registeration(){
	fstream fout;
	fout.open("Client_Details.csv", ios::out | ios::app);
	int i, check=0;
	string name, email, password1, password2;
	enter_ID();
	cout << "\n\n\t\tEnter Your Email Address: ";
	cin >> email;
	fout << email << ",";
	cout << "\n\n\t\tEnter Your Name: ";
	cin >> name;
	fout << name << ",";
	cout << "\n\n\t\tEnter Password: ";
	cin >> password1;
	cout << "\n\n\t\tVerify Password: ";
enterAgain:	cin >> password2;
	for(i=0;password1[i]!='\0' || password2[i]!='\0';i++){
		if(password1[i]==password2[i] && password2[i]==password1[i])	check=1;
		else															check=0;
	}
	if(check==1){
		cout << "\n\n\t\tYour New Password is: ";
		cout << password1 << endl;
		fout << password2;
	}
	else{
		cout << "\n\n\t\tWrong Password\n";
		cout << "\n\n\t\tEnter Password  again to verify: ";
		goto enterAgain;
	}
	fout << "\n";
	}
#endif
