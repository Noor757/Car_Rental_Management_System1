#ifndef AVAILABLECARSSHOW
#define AVAILABLECARSSHOW
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include "sll.cpp"
#include "selectCar.cpp"
using namespace std;
int convertstr_int(string s){ 
    int num = 0; 
    int n = s.length(); 
    for (int i = 0; i < n; i++) 
        num = num * 10 + (int(s[i]) - 48); 
    return num; 
}
int showAvaialbleCars(){				// plus showing car's rent too as per day
	char u;
	ifstream FILE;
	FILE.open("Available_Cars.csv");
	bool Found_Record = false;
	string index, car_name, engine, speed, seater, carRent;
	cout << "\n\n\t\tPress 1 for 2 seater cars." << endl;
	cout << "\n\n\t\tPress 2 for 4-5 seater cars." << endl;
	cout << "\n\n\t\tPress 3 for 7 seater cars." << endl;
	u = getch();
	cout << "\n\n\t\tPlease wait.";
    for(int i=0;i<2;i++){
        cout << ".";
        Sleep(1000);       
    }
	system("CLS");
	cout << "\n\t\t" << "No" << "." << setw(20) << "CarName" << setw(20) << "EngineCapacity" << setw(20) <<  "TopSpeed" << setw(20) << "Seater" << setw(20) << "Rentperday($)" << endl;
		switch (u){
		case '1':{
		SingleLinkedList SinglyList;
		string s[2]={"1","2"};		int i=0;
		Found_Record = false;
		while(getline(FILE,index,',') && !Found_Record && i<2){
		getline(FILE,car_name,',');
		getline(FILE,engine,',');
		getline(FILE,speed,',');
		getline(FILE,seater,',');
		getline(FILE,carRent,'\n');
		if(index==s[i++]){
			Found_Record = true;
		SinglyList.AddtoTail(index);
		SinglyList.AddtoTail(car_name);
		SinglyList.AddtoTail(engine);
		SinglyList.AddtoTail(speed);
		SinglyList.AddtoTail(seater);
		SinglyList.AddtoTail(carRent);
		}
		Found_Record = false;
	}
		SinglyList.show();		
		cout << '\n';	
		Sleep(1000);	
		}
		break;
		case '2':{
		SingleLinkedList SinglyList2;
		string s[9]={"3","4","5","6","7","8","9","10","11"};		int i=0, extra1, extra2, extra3=3;
		Found_Record = false;
		while(getline(FILE,index,',') && !Found_Record && i<9){
		getline(FILE,car_name,',');
		getline(FILE,engine,',');
		getline(FILE,speed,',');
		getline(FILE,seater,',');
		getline(FILE,carRent,'\n');
		extra1 = convertstr_int(index);
		extra2 = convertstr_int(s[i]);
		if(extra1>=3){
			if(extra1==extra2){ 
			i++;
			Found_Record = true;
		SinglyList2.AddtoTail(index);											
		SinglyList2.AddtoTail(car_name);
		SinglyList2.AddtoTail(engine);
		SinglyList2.AddtoTail(speed);
		SinglyList2.AddtoTail(seater);
		SinglyList2.AddtoTail(carRent);
		}
	}
		Found_Record = false;
	}
		SinglyList2.show();	
		cout << '\n';	
		Sleep(1000); 
	}

		break;
	case '3':{
		SingleLinkedList SinglyList3;
		string s[3]={"12","13","14"};		int i=0, extra1, extra2, extra3=12;
		Found_Record = false;
		while(getline(FILE,index,',') && !Found_Record){
		getline(FILE,car_name,',');
		getline(FILE,engine,',');
		getline(FILE,speed,',');
		getline(FILE,seater,',');
		getline(FILE,carRent,'\n');
		extra1 = convertstr_int(index);
		extra2 = convertstr_int(s[i]);
		if(extra1>=3){
			if(extra1==extra2){ 
			i++;
			Found_Record = true;
		SinglyList3.AddtoTail(index);
		SinglyList3.AddtoTail(car_name);
		SinglyList3.AddtoTail(engine);
		SinglyList3.AddtoTail(speed);
		SinglyList3.AddtoTail(seater);
		SinglyList3.AddtoTail(carRent);
		}
	}
		Found_Record = false;
	}
		SinglyList3.show();		
		cout << '\n';	
		Sleep(1000);	
		}
		break;
		}

	char g;
	cout << "\n\n\t\tPress 1 to select a car." << endl;
	cout << "\n\n\t\tPress 2 to exit." << endl;
	g = getch();
	cout << "\n\n\t\tPlease wait.";
    for(int i=0;i<2;i++){
        cout << ".";
        Sleep(1000);        
    }
		switch (g){
		case '1':
			selectCar();
			break;
		case '2':
			return 0;
		}
}
#endif
