#ifndef __LINKED_LIST_INCLUDED__
#define __LINKED_LIST_INCLUDED__

#include <iostream>
#include <cstdlib>
#include "List.cpp"
using namespace std;

template<class T> class LinkedList : public List<T> {
	class Node {
	public:
		T value;
		Node* nextNode;
		Node* prevNode;
		Node(T v):value(v), nextNode(NULL), prevNode(NULL){}
	};

private:
	Node* first;
	Node* last;
	int listSize;

	Node* getNode(int i){
		if(listSize == 0 || i < 0 || i >= listSize){
			return NULL;
		}
		Node* n = first;
		while(i > 0){
			if(n == NULL){
				return NULL;
			}
			n = n->nextNode;
			i--;
		}
		return n;
	}

public:

	LinkedList():listSize(0), first(NULL), last(NULL){}

	void put(T el){
		Node* n = new Node(el);
		if(first == NULL){
			first = n;
			last = n;
			listSize = 1;
		} else {
			last->nextNode = n;
			n->prevNode = last;
			last = n;
			listSize = listSize + 1;
		}
	}

	T get(int i){
		Node* n = getNode(i);
		if(n == NULL)
			return NULL;
		else
			return n->value;
	}

	void remove(int i){
		Node* n = getNode(i);
		if(n == NULL){
			return;
		} else if(n == first && n == last){
			first = NULL;
			last = NULL;
		} else if(n == first) {
			first = n->nextNode;
		} else if(n == last) {
			last = n->prevNode;
		} else {
			n->prevNode->nextNode = n->nextNode;
			n->nextNode->prevNode = n->prevNode;
		}
		delete n;
		listSize = listSize - 1;
	}

	void set(int i, T el){
		Node* n = getNode(i);
		if(n == NULL){
			return;
		} else {
			n->value = el;
		}
	}

	int size(){
		return listSize;
	}

	LinkedList<T> copy() {
		return *new LinkedList<T>();
	}

};

#endif
