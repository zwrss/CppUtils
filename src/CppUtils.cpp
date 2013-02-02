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

	List<Optional<int> > *list = new ArrayList<Optional<int> >();
//	List<Optional<int> > *list = new LinkedList<Optional<int> >();
	list->put(*new Optional<int>(1));
	list->put(*new Optional<int>());
	list->put(*new Optional<int>(3));
	list->put(*new Optional<int>());
	list->put(*new Optional<int>(5));
	list->set(4, 9);
	for(int i = 0; i < list->size(); i++){
		Optional<int> opt = list->get(i);
		cout << endl << "Value at " << i << " is ";
		if(opt.isSet()){
			cout << opt.get(-1);
		} else {
			cout << "not set (" << opt.get(-1) << ")";
		}
	}
	cout << endl << "-------------------" << endl;
	list->remove(2);
	list->remove(6);
	for(int i = 0; i < list->size(); i++){
		Optional<int> opt = list->get(i);
		cout << endl << "Value at " << i << " is ";
		if(opt.isSet()){
			cout << opt.get(-1);
		} else {
			cout << "not set (" << opt.get(-1) << ")";
		}
	}

	return 0;
}
