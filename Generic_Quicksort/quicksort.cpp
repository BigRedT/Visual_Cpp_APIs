#include <iostream>
#include "quicksort.h"

//template <class Item>
bool Quicksort<Item>::less(Item x, Item y) { return x.compareTo(y)<0;}

//template <class Item>
void Quicksort <Item>::exch(Item itemArray[], int i, int j) {
	Item temp=itemArray[i];
	itemArray[i]=itemArray[j];
	itemArray[j]=temp;
}

//template <class Item>
int Quicksort<Item>::partition(Item itemArray[], int lo, int hi) {
	int i=lo;
	int j=hi+1;
	while(true) {
		while(less(itemArray[++i],itemArray[lo])) {
			if(i==hi) { break;}
		}
		while(less(itemArray[lo],itemArray[--j])) {
			if(j==lo) { break;}
		}
		if(j<=i) { break;}
		exch(itemArray,i,j);
	}
	exch(itemArray,lo,j);
	return j;
}

//template <class Item>
void Quicksort<Item>::sort(Item itemArray[], int lo, int hi) {
	if(lo>=hi) {return;}
	int j=partition(itemArray,lo,hi);
	sort(itemArray,lo,j-1);
	sort(itemArray,j+1,hi);
}

//template <class Item>
void Quicksort<Item>::length(Item itemArray[]) {
	int len=sizeof(itemArray)/sizeof(Item);
	std::cout<<len<<itemArray[0].val;
}