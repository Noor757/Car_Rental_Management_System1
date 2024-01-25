#ifndef SELECTCAR
#define SELECTCAR
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include "Record_Reading_Search.cpp"
#include "My_Profile.cpp"
#include "sll.cpp"
#include "Ending_Func.cpp"
using namespace std;
int calculate_extrabill(int bill1); // for extra time and distance covered
int special_Discount(int bill);		// special discounts,						// Invoice Generation here
int convertstrtoint(string s){ 
    // Initialize a variable 
    int num = 0; 
    int n = s.length(); 
    // Iterate till length of the string 
    for (int i = 0; i < n; i++) 
        // Subtract 48 from the current digit 
        num = num * 10 + (int(s[i]) - 48); 
    return num; 
}
int selectCar(){
	string choose, di;
	SingleLinkedList s1;
	ifstream file1;
	file1.open("Available_Cars.csv");
	bool found_record = false;
	string NO, CARNAME, ENGINE, SPEED, SEATER, CARRENT;
	int noofdays; int initialBill;
	cout << "\n\n\t\tChoose no. of the car ";
	cin >> choose;
	Sleep(1000);
	while(getline(file1,NO,',') && !found_record){
		getline(file1,CARNAME,',');
		getline(file1,ENGINE,',');
		getline(file1,SPEED,',');
		getline(file1,SEATER,',');
		getline(file1,CARRENT,'\n');
		if(NO==choose){
			found_record = true;
			s1.AddtoTail(NO);
			s1.AddtoTail(CARNAME);
			s1.AddtoTail(ENGINE);
			s1.AddtoTail(SPEED);
			s1.AddtoTail(SEATER);
			s1.AddtoTail(CARRENT);
		}
	}
	SingleLinkedList s;
	initialBill = 	convertstrtoint(CARRENT);
	cout << "\n\n\t\tFor how many days ";
	cin >> noofdays;
	cout << "\n\n\t\tEnter your ID for confirmation ";
	cin >> di;
	if(readrecordfromfile("Client_Details.csv",di)){
		ifstream file;
		file.open("Client_Details.csv");
		bool found_record2 = false;
		string id_user, email_user, name_user, password_user;
		while(getline(file,id_user,',') && !found_record2){
		getline(file,email_user,',');
		getline(file,name_user,',');
		getline(file,password_user,'\n');
		if(id_user==di){
			found_record2 = true;
			s.AddtoTail(id_user);
			s.AddtoTail(email_user);
			s.AddtoTail(name_user);
			s.AddtoTail(password_user);
		}
	}
			initialBill = initialBill*noofdays;
			cout << "\n\n\t\tYour initial Bill is: " << initialBill << endl;
		}
	else{
		cout << "\n\n\t\tID doesn't exit." << "Sign up first!" << endl;
		return 0;
	}											
	Sleep(1000);
	cout << "\n\n\t\tHere you go. Enjoy and fun hard." << endl;
	Sleep(1000);
	cout << "\n\n\t\tAfter " << noofdays << " days" << endl;
	int final_bill;
	final_bill = calculate_extrabill(initialBill);
	system("CLS");
	int checking_where = 0;
	char h;
	cout << "\n\n\t\tPress 1 to generate invoice." << endl;
	cout << "\n\n\t\tPress 2 for discount." << endl;
	h = getch();
	cout << "\n\n\t\tPlease wait.";
    for(int i=0;i<2;i++){
        cout << ".";
        Sleep(1000);        
    }
    	int newBILL;
	system("CLS");
		switch (h){
		case '1':
			checking_where = 1;
			goto invoice;
			break;
		case '2':
			newBILL = special_Discount(final_bill);
			goto invoice;
			break;
		}
	invoice:	system("CLS");		
				cout << "\n\n\t\t\t\t\tINVOICE" << endl;			//Invoice Generation
				cout << "\n\n\t\tUser Credentials: " << endl;
				s.show1();		
				cout << "\n\n\t\tCar Details: " << endl;	
				s1.show1();
				if(checking_where==0){
					cout << "\n\n\t\tYour bill  before discount is: " << final_bill << endl;
					cout << "\n\n\t\tYour Final bill after discount is: " << newBILL << endl;
				}
					
				else	
					cout << "\n\n\t\tYour Final bill is: " << final_bill << endl;
				Sleep(1000); 
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				bill_receive();
		}
int calculate_extrabill(int bill1){
	int days;		string reply1, reply2;		int total_final_bill;
		cout << "\n\n\t\tHave you travelled for more than the contracted days? ";
		cin >> reply1;
	if(reply1=="YES" or reply1=="Yes" or reply1=="yes"){
		cout << "\n\n\t\tEnter no of days (extra if any) other than for those you ordered for the car ";
		cin >> days ;
		total_final_bill = bill1 * days;
	}
	else		total_final_bill = bill1;
		cout << "\n\n\t\tHave you travelled outstation during this time? ";
		cin >> reply2;
		if(reply2=="YES" or reply2=="Yes" or reply2=="yes")
			total_final_bill = total_final_bill * 100;
		return total_final_bill;
	}
int special_Discount(int bill){
	int discount; 	int new_bill;
	discount = rand() % 100 + 1;
	new_bill = bill - discount;
	return new_bill;
}
#endif
