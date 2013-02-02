#ifndef __LIST_INTERFACE_INCLUDED__
#define __LIST_INTERFACE_INCLUDED__

template<class T> class List {
public:
	virtual void put(T el) = 0;
	virtual T get(int i) = 0;
	virtual void remove(int i) = 0;
	virtual void set(int i, T el) = 0;
	virtual int size() = 0;
};

#endif
