//============================================================================
// Name        : ArrayList.cpp
// Author      : Pawel Mlynarczyk <pawel@zwrss.pl>
// Description : Simple ArrayList for C++ - this is not the best implementation!
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

template<class T> class ArrayList {
private:
	T* list;
	int listSize;
public:

	ArrayList():listSize(0), list(NULL){}

	void put(T el){
		T* newList;
		newList = (T*) realloc(list, (listSize + 1) * (sizeof newList[0]));
		newList[listSize] = el;
		list = newList;
		listSize = listSize + 1;
		for(int i = 0; i < listSize; i++){
			cout << endl << list[i];
		}
	}

	T get(int i){
		if(i < 0 || i >= listSize){
			return NULL;
		} else {
			return list[i];
		}
	}

	void remove(int i){
		if(i >= 0 && i < listSize && listSize > 1){
			T* newList;
			newList = (T*) realloc(list, (listSize - 1) * (sizeof newList[0]));
			int j = 0;
			int k = 0;
			while(j < listSize-1){
				if(k != i){
					newList[j] = list[k];
					j++;
				}
				k++;
			}
			list = newList;
			listSize = listSize - 1;
		} else if(listSize == 1){
			list = NULL;
			listSize = 0;
		}
	}

	int size(){
		return listSize;
	}
};