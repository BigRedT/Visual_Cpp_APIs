#include<iostream>
#include"queue.h"
#include"binarySearchTree.h"


class Key {
public:
	int x;
	Key(){
		x=0;
	}
	Key(int y) {x=y;}
	int compareTo(Key key) {
		if(this->x<key.x) {return -1;}
		else if(this->x>key.x) {return 1;}
		else {return 0;}
	}
};
int main(){
	
	BST<Key,char> tree;
	Key a(1);
	Key b(2);
	Key c(3);
	Key d(4);
	Key e(5);
	Key f(6);
	tree.put(d, 'd');
	tree.put(f, 'f');
	tree.put(e, 'e');
	tree.put(b, 'b');
	tree.put(c, 'c');
	tree.put(a, 'a');
	std::cout <<"Number of Elements: " <<tree.sizeOfTree()<<std::endl;
	Key* inorderKeys = new Key(tree.sizeOfTree());
	inorderKeys = tree.inorder();
	for (int i = 0; i < tree.sizeOfTree(); i++) {
		std::cout << inorderKeys->x << " - " << *tree.get(*inorderKeys) << " rank: " << tree.rank(*inorderKeys) << std::endl;
		inorderKeys++;
	}
	inorderKeys = NULL;
	std::cout << "Deleting e and b" << std::endl;
	tree.deleteKey(e);
	tree.deleteKey(b);
	inorderKeys = new Key(tree.sizeOfTree());
	inorderKeys = tree.inorder();
	for (int i = 0; i < tree.sizeOfTree(); i++) {
		std::cout << inorderKeys->x << " - " << *tree.get(*inorderKeys) << " rank: "<<tree.rank(*inorderKeys) <<std::endl;
		inorderKeys++;
	}
	std::cout << "Number of Elements: " << tree.sizeOfTree() << std::endl;
	std::cout << "Press any key to continue";
	getchar();
	return 0;
}
