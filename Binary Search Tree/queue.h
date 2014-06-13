#ifndef QUEUE_H
#define QUEUE_H

template<class object>
class queue {
private:
	class Node {
	public:
		object o;
		Node* next;
		Node(object o) {
			this->o = o;
			next = NULL;
		}
	};
	Node* head;
	Node* last;
	int size;
public:
	queue() { 
		head = NULL;
		last = NULL;
		size = 0;
	}

	void enqueue(object o) {
		Node* n=new Node(o);
		if (head == NULL) {head = n;}
		else {last->next = n;}
		last = n;
		size++;
    }

	object* dequeue() {
		if (head == NULL) { return NULL; }
		Node* n = head;
		head = head->next;
		if (head == NULL) {
			last = NULL;
		}
		size--;
		return &(n->o);
	}
	
	object* iterator() { 
		object* iterate=new object(size);
		Node* ptr=head;
		for (int i = 0; i < size; i++) {
			iterate[i] = ptr->o;
			ptr = ptr->next;
        }
		return iterate;
	}

	int length() { return size; }
};

#endif