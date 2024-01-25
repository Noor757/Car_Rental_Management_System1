#include <iostream>
#include <bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include "Register.cpp"
#include "Record_Reading_Search.cpp"
#include "choice.cpp"
#include "sll.cpp"
using namespace std;
void Login(){
	string id;
	fstream file ("Client_Details.csv", ios::in);
	cout << "\n\n\t\tEnter ID to access your account: ";
	cin >> id;
	cout << "\n\n\t\tPlease wait.";
	for(int i=0;i<2;i++){
        cout << ".";
        Sleep(1000);        //the dot will be printed after 1 second, because in sleep we take data in milli second
    }
	if(readrecordfromfile("Client_Details.csv",id))			enter_choice1(id);
	else													cout << "\n\n\t\tID doesn't exit." << "Sign up first!" << endl;
}
int main(){
	string c;		string temp;
	cout << "\n\n\t\t\t\t\tCar Rental Management System" << endl;
	cout << "\n\n\t\tAlready have an account: " << endl;
	cout << "\n\n\t\tYes or No? "; 
	cin >> c;
	cout << "\n\n\t\tPlease wait.";
    for(int i=0;i<2;i++){
        cout << ".";
        Sleep(1000);     
    }
	if(c=="Yes" || c=="yes" || c=="YES")		Login();
	else{
		cout << "\n\n\t\tSign up now!" << endl;
reg:		Registeration();
		cout << "\n\n\t\tCongratulations! Your account is created Successfully!.";
		cout << "\n\n\t\tPlease wait.";
    	for(int i=0;i<2;i++){
       	 	cout << ".";
        	Sleep(1000);       
    }
		enter_choice2();
	}
	return 0;
}

