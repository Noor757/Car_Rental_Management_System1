#ifndef CHOICE
#define CHOICE
#include <iostream>
#include <bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include "My_Profile.cpp"
#include "wantAcab.cpp"
using namespace std;
int enter_choice1(string temp){			// parameter is passing just for reference for id 
	char user;
	system("CLS");
	while(1){
	cout << "\n\n\t\tPress 1 to see your profile." << endl;
	cout << "\n\n\t\tPress 2 if you want to rent a car." << endl;
	cout << "\n\n\t\tPress 3 to exit." << endl;
	user = getch();
	cout << "\n\n\t\tPlease wait.";
    for(int i=0;i<2;i++){
        cout << ".";
        Sleep(1000);       
    }
	system("CLS");
		switch (user){
		case '1':
			My_Profile("Client_Details.csv", temp);							// changes required e.g adding order records
			break;
		case '2':
			wantACab();
			break;
		case '3':
			return 0;
		}
	}
}

int enter_choice2(){			
	char User;
	system("CLS");
	cout << "\n\n\t\tPress 1 if you want to rent a car." << endl;
	cout << "\n\n\t\tPress 2 to exit." << endl;
	User = getch();
	cout << "\n\n\t\tPlease wait.";
    for(int i=0;i<2;i++){
        cout << ".";
        Sleep(1000);        
    }
	system("CLS");
		switch (User){
		case '1':
			wantACab();
			break;
		case '2':
			return 0;
		}
}
#endif
