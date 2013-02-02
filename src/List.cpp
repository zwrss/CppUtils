#ifndef __LIST_INTERFACE_INCLUDED__
#define __LIST_INTERFACE_INCLUDED__

#include "Exception.cpp"

template<class T> class List {
public:
	virtual void put(T el) = 0;
	virtual T get(int i) = 0;
	virtual void remove(int i) = 0;
	virtual void set(int i, T el) = 0;
	virtual int size() = 0;
	virtual List<T>* copy() = 0;
	virtual ~List(){ delete this; };
};

class IndexOutOfBoundsException : Exception {
private:
	string msg;
public:
	IndexOutOfBoundsException(string msg):msg(msg){}
	string message(){ return msg; }
};

#endif
