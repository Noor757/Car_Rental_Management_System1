#ifndef ENDINGFUNC
#define ENDINGFUNC
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include<windows.h>
#include<conio.h>
using namespace std;
void give_feedback();
void thank_message();
void bill_receive(){
	cout << "\n\n\t\tPlease wait.";
	for(int i=0;i<2;i++){
        cout << ".";
        Sleep(1000);
    }
	cout << "\n\n\t\tYour payment has been received." << endl;
	give_feedback();
}
void give_feedback(){
	string feedback;
	cout << "\n\n\t\tPlease wait.";
	for(int i=0;i<2;i++){
        cout << ".";
        Sleep(1000);
    }
	cout << "\n\n\t\tWe would love to hear your comments about our service." << endl;
	cout << "\n\n\t\tTell us what you truly think of it. If there is any misguidance, we will try to fix it." << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cin >> feedback;
	fstream feed_back;
	feed_back.open("feedback.txt",ios::out | ios::app);
	feed_back << feedback;
	Sleep(1000);
	system("CLS");
	thank_message();
}
void thank_message(){
	cout << "\n\n\t\tThankYou for trusting us. Make sure to visit again." << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	Sleep(1000);
}
#endif

