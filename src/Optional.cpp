#ifndef __OPTIONAL_CLASS_INCLUDED__
#define __OPTIONAL_CLASS_INCLUDED__

#include <iostream>
using namespace std;

template<class T> class Optional{
private:
	T x;
	bool isset;
public:
	Optional(){
		isset = false;
	}
	Optional(T x):x(x){
		isset = true;
	}

	T get(T e){
		if(isset)
			return x;
		else
			return e;
	}

	bool isSet(){
		return isset;
	}

	int operator==(Optional<T> &other){
		if(!isSet() && !other.isSet()){
			return 1;
		} else if(isSet() && other.isSet() && x == other.get(NULL)){
			return 1;
		} else {
			return 0;
		}
	}
};

#endif
