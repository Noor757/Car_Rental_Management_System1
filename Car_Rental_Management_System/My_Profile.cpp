#ifndef MYPROFILE
#define MYPROFILE
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
vector<string> My_Profile(string file_Name, string Id){
	vector<string> profile_details;
	ifstream file;
	file.open("Client_Details.csv");
	bool found_Record = false;
	string id_User, email_User, name_User, password_User;
	while(getline(file,id_User,',') && !found_Record){
		getline(file,email_User,',');
		getline(file,name_User,',');
		getline(file,password_User,'\n');
		if(id_User==Id){
			found_Record = true;
			profile_details.push_back(id_User);
			profile_details.push_back(email_User);
			profile_details.push_back(name_User);
			profile_details.push_back(password_User);
		}
	}
	cout << "\n\n\t\tCredentials for ID " << profile_details[0] << " are: " << endl;
	cout << "\n\t\t" << profile_details[1] << endl;
	cout << "\n\t\t" << profile_details[2] << endl;
	cout << "\n\t\t" << profile_details[3] << endl;
	cout << "---------------------------------------------------------------\n";
	Sleep(1000);
	return profile_details;
}
#endif
