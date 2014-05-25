#include<iostream>
#include<stdlib.h>
#include "quicksort.h"

#define N 100

Item::Item() { val=0;}
Item::Item(double x) { val=x;}
int Item::compareTo (Item x) {
	if(val < x.val) { return -1;}
	if(val > x.val) { return +1;}
	return 0;
}

int main(){
	/*Item a(2);
	Item b(1);
	Item c(8);
	Item d(4);
	Item e(3);
	Item itemArray[5]={a,b,c,d,e};*/
	Item itemArray[N];
	for(int i=0;i<N;i++) { itemArray[i].val=rand();}
	Quicksort <Item> Q;
	Q.sort(itemArray,0,N-1);
	for(int i=0;i<N;i++){
		std::cout<<"->"<<itemArray[i].val;
	}
	getchar();
	return 0;
}