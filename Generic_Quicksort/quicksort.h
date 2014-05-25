#ifndef QUICKSORT_H
#define QUICKSORT_H

class Item {
public:
	double val;
public:
	Item();
	Item(double x);
	int compareTo(Item x);
};

template <class Item>									//Item must have public int compareTo(Item x) function
class Quicksort {
private:
	bool less(Item x, Item y);							//returns true if x < y according to a total order
	void exch(Item itemArray[], int i, int j);			//swaps items at indices i and j
public:
	int partition(Item itemArray[], int lo, int hi);	//partitions the itemArray between lo and hi and returns the pivot
	void sort(Item itemArray[], int lo, int hi);		//sorts itemArray between lo and hi
	void length(Item itemArray[]);						//length of array
};

#endif

