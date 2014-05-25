#include <iostream>
#include "linked_list.h"

void linkedList::setValue(int x){
	head=NULL;
}

Node* linkedList::find(int x) {
	Node* scan=head;
	while(scan!=NULL) {
		if(scan->value==x) {break;}
		scan=scan->next;
	}
	return scan;
}

void linkedList::insertAtHead(int x) {
	Node* newNode= new Node();
	newNode->value=x;
	newNode->next=head;
	head=newNode;
}

void linkedList::insertAfter(int x, int y) {
	Node* after=find(y);
	Node* newNode= new Node();
	newNode->value=x;
	newNode->next=after->next;
	after->next=newNode;
}

void linkedList::insertAt(int x, Node* here){
	if(here==head){
		insertAtHead(x);
		return;
	}
	Node* scan=head;
	while(scan->next!=here){
		scan=scan->next;
	}
	insertAfter(x,scan->value);
}

void linkedList::deleteNode(int x) {
	Node* toDelete=find(x);
	if(toDelete==NULL) {return;}
	Node* scan=head;
	if(head==toDelete) {
		head=head->next;
	}else{
		while(scan->next!=toDelete) {
			scan=scan->next;
		}
		scan->next=toDelete->next;
	}
	delete toDelete;
	toDelete=NULL;
}

void linkedList::printList() {
	Node* scan=head;
	while(scan!=NULL) {
		std::cout<<"->"<<scan->value;
		scan=scan->next;
	}
	std::cout<<"->NULL"<<std::endl;
}

int linkedList::listLength() {
	int length=0;
	Node* scan=head;
	while(scan!=NULL) {
		length++;
		scan=scan->next;
	}
	return length;
}

int* linkedList::returnArray() {
	int length=listLength();
	int* array = new int(length);
	Node* scan=head;
	for(int i=0;i<length;i++){
		array[i]=scan->value;
		scan=scan->next;
	}
	return array;
}