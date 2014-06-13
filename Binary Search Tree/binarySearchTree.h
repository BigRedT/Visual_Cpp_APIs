#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include"queue.h"
template<class Key, class Value>
class BST {
private:
	class Node {
	public:
		Key key;
		Value val;
		Node* left;
		Node* right;
		int count;
		Node(Key key, Value val) {
			this->val=val;
			this->key=key;
			this->left=NULL;
			this->right=NULL;
			count = 1;
		}
	};
private:
	Node* root;
	//queue<Key> Q;
public:
	BST() { 
		root=NULL;
	}

	int sizeOfTree() { return size(root); }

	void put(Key key, Value val) {
		root=put(root,key,val);
	}
private:
	int size(Node* x) {
		if (x == NULL) { return 0; }
		return x->count;
	}
	Node* put(Node* x, Key key, Value val) {
		if(x==NULL) {
			Node* n=new Node(key,val);
			return n;
		}
		int cmp=key.compareTo(x->key);
		if(cmp<0) {x->left=put(x->left,key,val);}
		else if(cmp>0) {x->right=put(x->right,key,val);}
		else {x->val=val;}
		x->count = 1 + size(x->left) + size(x->right);
		return x;
	}

//public:
	/*Value* get(Key key) {
		Node* x=root;
		while(x!=NULL) {
			int cmp=key.compareTo(x->key);
			if(cmp<0) {x=x->left;}
			else if(cmp>0) {x=x->right;}
			else {return &(x->val);}
		}
		return NULL;
	}*/
public:
	Value* get(Key key) {
		return get(root,key);
	}
private:
	Value* get(Node* x, Key key) {
		if(x==NULL) {return NULL;}
		int cmp=key.compareTo(x->key);
		if(cmp<0) {return get(x->left,key);}
		else if(cmp>0) {return get(x->right,key);}
		else {return &(x->val);}
	}
public:
	Key* floor(Key key) {
		return floor(root,key);
	}
private:
	Key* floor(Node* x, Key key) {
		if(x==NULL) {return NULL;}
		int cmp=key.compareTo(x->key);
		if(cmp<0) {return floor(x->left,key);}
		else if(cmp==0) {return &(x->key);}
		else {
			Key* keyTemp=floor(x->right,key);
			if(keyTemp==NULL) {return &(x->key);}
			return keyTemp;
		}
	}
public:
	Key* inorder(){
		queue<Key>* Q=new queue<Key>;
		inorder(root,Q);
		return Q->iterator();
	}
private:
	void inorder(Node* x, queue<Key>* Q) {
		if (x == NULL) { return; }
		inorder(x->left,Q);
		Q->enqueue(x->key);
		inorder(x->right,Q);
	}

public:
	int rank(Key key) {
		return rank(root,key);
	}
private:
	int rank(Node* x, Key key) {
		if (x == NULL) { return 0; }
		int cmp = key.compareTo(x->key);
		if (cmp < 0) { return rank(x->left,key); }
		else if (cmp > 0) { return size(x->left) + 1 + rank(x->right, key); }
		return size(x->left);
	}

public:
	Key* min() {
		Node* t = min(root);
		if (t == NULL) { return NULL; }
		return &(t->key);
	}
private:
	Node* min(Node* x) {
		if (x == NULL) { return NULL; }
		Node* t = x;
		while (x->left != NULL) {
			x = x->left;
		}
		return x;
	}

public:
	void deleteKey(Key key) {
		root = deleteKey(root, key);
	}
private:
	Node* deleteKey(Node* x, Key key) {
		if (x == NULL) { return NULL; }
		int cmp = key.compareTo(x->key);
		if (cmp < 0) { x->left = deleteKey(x->left, key); }
		else if (cmp > 0) { x->right = deleteKey(x->right, key); }
		else {
			if (x->left == NULL && x->right == NULL) {
				delete[] x;
				return NULL;
			}
			else if (x->left == NULL) {
				Node* n = x->right;
				n->count = x->count-1;
				delete[] x;
				return n;
			}
			else if (x->right == NULL) {
				Node* n = x->left;
				n->count = x->count - 1;
				delete[] x;
				return n;
			}
			else {
				Node* t = min(x->right);
				Node temp = *x;
				x->key = t->key;
				x->val = t->val;
				t->key = temp.key;
				t->val = temp.val;
				x->right = deleteKey(x->right, key);
			}
		}
		x->count = 1 + size(x->left) + size(x->right);
		return x;
	}
};

#endif