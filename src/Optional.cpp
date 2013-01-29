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
};
