#ifndef WANTACAB
#define WANTACAB
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include "AvailableCarsShow.cpp"
using namespace std;
int wantACab(){
	cout << "\n\n\t\tHey! This is 'Call A Cab' booking serivce. We are here to make your long, tiring journey comfortable. \n\n\t\tTell us what you need" << endl;
	char USER;
	cout << "\n\n\t\tPress 1 to see cars available for rent." << endl;
	cout << "\n\n\t\tPress 2 to exit." << endl;
	USER = getch();
	cout << "\n\n\t\tPlease wait.";
    for(int i=0;i<2;i++){
        cout << ".";
        Sleep(1000);        
    }
	system("CLS");
		switch (USER){
		case '1':
			showAvaialbleCars();
			break;
		case '2':
			return 0;
		}
}
#endif
