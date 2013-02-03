#include <iostream>
#include "ArrayList.cpp"
#include "LinkedList.cpp"
#include "Optional.cpp"
using namespace std;

template <class T1> class Test1{
public:
	T1 x;
	Test1():x(NULL){}
	Test1(T1 x):x(x){}
	T1 get(){
		return x;
	}
};

template <class T2> class Test2 : public Test1<T2>{
public:
	T2 x;
	Test2(T2 x):x(x){}
};

class A{
public:
	int x;
	A(int x):x(x){}
};

int main() {

	cout << endl << "--- Create and input test:" << endl;
//	List<Optional<int> > *list = new ArrayList<Optional<int> >();
	List<Optional<int> > *list = new LinkedList<Optional<int> >();
	list->put(Optional<int>(1));
	list->put(Optional<int>(NULL));
	list->put(Optional<int>(3));
	list->put(Optional<int>());
	list->put(Optional<int>(5));
	list->set(4, Optional<int>(9));
	for(int i = 0; i < list->size(); i++){
		Optional<int> opt = list->get(i);
		cout << endl << "Value at " << i << " is ";
		if(opt.isSet()){
			cout << opt.get(-1);
		} else {
			cout << "not set (" << opt.get(-1) << ")";
		}
	}
	cout << endl << "--- Exception test:" << endl;
	try{
		list->get(7);
	} catch (IndexOutOfBoundsException& e) {
		cout << endl << "Got an exception: " << e.message();
	}
	cout << endl << "--- Remove one test:" << endl;
	list->remove(2);
	for(int i = 0; i < list->size(); i++){
		Optional<int> opt = list->get(i);
		cout << endl << "Value at " << i << " is ";
		if(opt.isSet()){
			cout << opt.get(-1);
		} else {
			cout << "not set (" << opt.get(-1) << ")";
		}
	}
	cout << endl << "--- Remove all test:" << endl;
	while(list->size() > 0){
		list->remove(0);
		cout << endl << "deleting";
	}
	for(int i = 0; i < list->size(); i++){
		Optional<int> opt = list->get(i);
		cout << endl << "Value at " << i << " is ";
		if(opt.isSet()){
			cout << opt.get(-1);
		} else {
			cout << "not set (" << opt.get(-1) << ")";
		}
	}
	cout << endl << "--- Reinput test:" << endl;
	list->put(Optional<int>(1));
	list->put(Optional<int>());
	list->put(Optional<int>(3));
	list->put(Optional<int>());
	list->put(Optional<int>(5));
	for(int i = 0; i < list->size(); i++){
		Optional<int> opt = list->get(i);
		cout << endl << "Value at " << i << " is ";
		if(opt.isSet()){
			cout << opt.get(-1);
		} else {
			cout << "not set (" << opt.get(-1) << ")";
		}
	}
	cout << endl << "--- Copy test:" << endl;
	List<Optional<int> >* list2 = list->copy();
	for(int i = 0; i < list2->size(); i++){
		Optional<int> opt = list2->get(i);
		cout << endl << "Value at " << i << " is ";
		if(opt.isSet()){
			cout << opt.get(-1);
		} else {
			cout << "not set (" << opt.get(-1) << ")";
		}
	}
	cout << endl << "--- Contains test:" << endl;
	if(list->contains(Optional<int>(1))){
		cout << endl << "OK";
	} else {
		cout << endl << "ERROR! This DOES contain Optional(1)!";
	}

	if(!list->contains(Optional<int>(10))){
		cout << endl << "OK";
	} else {
		cout << endl << "ERROR! This DOES NOT contain Optional(10)!";
	}

	return 0;
}
