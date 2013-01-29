#include <iostream>
#include "ArrayList.cpp"
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
	Optional<int> *a = new Yes<int>(5);
	Optional<int> *b = new No<int>();
	cout << a->get(1) << ", " << b->get(1);
//	List<Test1<int> > *a = new ArrayList<Test1<int> >();
//	a->put(*new Test2<int>(1));
//	a->put(*new Test1<int>(2));
//	a->put(*new Test2<int>(3));
//	a->put(*new Test1<int>(4));
//	cout << a->get(0).get();
//	Test1<int> t;
//	t = Test1<int>(1);
//	cout << t.get();
//	{
//		cout << endl << " --- test --- ";
//		for(int i = 0; i < a.size(); i++){
//			cout << endl << i << "." << a.get(i).x;
//		}
//	}
//	a.remove(2);
//	{
//		cout << endl << " --- test --- ";
//		for(int i = 0; i < a.size(); i++){
//			cout << endl << i << "." << a.get(i).x;
//		}
//	}
//	a.remove(0);
//	{
//		cout << endl << " --- test --- ";
//		for(int i = 0; i < a.size(); i++){
//			cout << endl << i << "." << a.get(i).x;
//		}
//	}
//	a.remove(0);
//	a.remove(0);
//	{
//		cout << endl << " --- test --- ";
//		for(int i = 0; i < a.size(); i++){
//			cout << endl << i << "." << a.get(i).x;
//		}
//	}
	return 0;
}
