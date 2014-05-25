#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
	int value;
	Node* next;
};
	
class linkedList {
public:
	Node* head;
	
public:
	void setValue(int x);				//Initialize head to NULL
	Node* find(int x);					//Return pointer to node with value x
	void insertAtHead(int x);			//Insert x at the head
	void insertAt(int x, Node* here);	//Insert x here
	void insertAfter(int x, int y);		//Insert x after y
	void deleteNode(int x);				//Delete x
	int  listLength();					//Returns length of list
	int* returnArray();					//Returns the items in an array
	void printList();					//Print the elements in the list
};
#endif