#ifndef SLL
#define SLL
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	string data;
	Node *next;

	Node(string d){
		data = d;
		next = 0;
	}	
};
class SingleLinkedList{
	Node *head;
	Node *tail;
public:
	SingleLinkedList(){
		head = tail = NULL;
	}
	bool IsEmpty(){
		if(head==0 || tail==0)		return 1;
		else						return 0;
	}
/*	bool exists(Node *n){
	if(!isEmpty()){
			Node *temp = head;
			for(; temp!=NULL;){
				if(temp == n)	return 1;
				temp = temp->next;
			}
	}
	return 0;
	} */
	void AddtoHead(string e){
			Node *temp = head;
			head = new Node(e);
			head->next = temp;
		if(tail==0)
			tail=head;
	}
	void AddtoTail(string e){
		if(tail==0)
			head = tail =  new Node(e);
		else{
			tail->next = new Node(e);
			tail = tail->next;
		}
	}
	void show(){
		if(!IsEmpty()){
			Node *temp;
			cout << "\n\t\t";
			int check=0;
			for(temp=head;temp!=0;temp=temp->next){
				if(check==6){
					cout << "\n\t\t";
					check=0;
				}		
				cout << temp->data << setw(20);
				check++;
			}
			cout << "\n\t\t";
		}
	}
	void show1(){
		if(!IsEmpty()){
			Node *temp;
			cout << "\n\t\t";
			int check=0;
			for(temp=head;temp!=0;temp=temp->next){		
				cout << temp->data << setw(10);
			}
			cout << "\n\t\t";
		}
	}
	string delfromHead(){
		if(!IsEmpty()){
			string e = head->data;
			Node *temp = head;
			if(head==tail)
				head = tail = 0;
			else
				head = head->next;
			delete temp;
			return e;
		}
	}
/*	void SearchInList(string e){
		Node *temp;
		int count=0;
		for(temp=head;temp!=0 && temp->data != e;temp = temp->next)
			count++;
			if(temp->data == e) 			cout << "Element Found at node " << count+1;
			else							cout << "Element Not Found";
			cout << "\n";
	}  */
};

#endif
