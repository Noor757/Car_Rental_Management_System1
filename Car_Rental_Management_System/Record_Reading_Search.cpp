#ifndef RECORDREADINGSEARCH
#define RECORDREADINGSEARCH
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
bool readrecordfromfile(string file_name, string search_term){
	vector<string> record;
	ifstream file;
	file.open("Client_Details.csv");
	bool found_record = false;
	string id_user, email_user, name_user, password_user;
	while(getline(file,id_user,',') && !found_record){
		getline(file,email_user,',');
		getline(file,name_user,',');
		getline(file,password_user,'\n');
		if(id_user==search_term){
			found_record = true;
			record.push_back(id_user);
			record.push_back(email_user);
			record.push_back(name_user);
			record.push_back(password_user);
		}
	}
	if(found_record == false)		return 0;
	else 							return 1;			
}
#endif
