#ifndef __ARRAY_LIST_INCLUDED__
#define __ARRAY_LIST_INCLUDED__

#include <iostream>
#include <cstdlib>
#include <string>
#include "List.cpp"
using namespace std;

template<class T> class ArrayList : public List<T> {

private:
	T* list;
	int listSize;

public:

	ArrayList():listSize(0), list(NULL){}

	void put(T el){
		list = (T*) realloc(list, (listSize + 1) * (sizeof list[0]));
		list[listSize] = el;
		listSize = listSize + 1;
	}

	T get(int i){
		if(i < 0 || i >= listSize)
			throw IndexOutOfBoundsException("Index is out of bounds.");
		return list[i];
	}

	void remove(int i){
		if(i < 0 || i >= listSize)
			throw IndexOutOfBoundsException("Index is out of bounds.");
		for(int j = i; j < listSize-1; j++){
			list[j] = list[j+1];
		}
		list = (T*) realloc(list, (listSize - 1) * (sizeof list[0]));
		listSize = listSize - 1;
	}

	void set(int i, T el){
		if(i < 0 || i >= listSize)
			throw IndexOutOfBoundsException("Index is out of bounds.");
		list[i] = el;
	}

	int size(){
		return listSize;
	}

	List<T>* copy() {
		List<T> *al = new ArrayList<T>();
		for(int i = 0; i < listSize; i++){
			al->put(list[i]);
		}
		return al;
	}
};

#endif
