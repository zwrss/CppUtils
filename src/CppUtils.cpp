//============================================================================
// Name        : CppUtils.cpp
// Author      : Pawel Mlynarczyk <pawel@zwrss.pl>
// Description : Simple utils for C++.
//============================================================================

#include <iostream>
#include "ArrayList.cpp"
using namespace std;

class A{
public:
	int x;
	A(int x):x(x){}
};

int main() {
	ArrayList<A> a = *new ArrayList<A>();
	a.put(*new A(1));
	a.put(*new A(2));
	a.put(*new A(3));
	a.put(*new A(4));
	{
		cout << endl << " --- test --- ";
		for(int i = 0; i < a.size(); i++){
			cout << endl << i << "." << a.get(i).x;
		}
	}
	a.remove(2);
	{
		cout << endl << " --- test --- ";
		for(int i = 0; i < a.size(); i++){
			cout << endl << i << "." << a.get(i).x;
		}
	}
	a.remove(0);
	{
		cout << endl << " --- test --- ";
		for(int i = 0; i < a.size(); i++){
			cout << endl << i << "." << a.get(i).x;
		}
	}
	a.remove(0);
	a.remove(0);
	{
		cout << endl << " --- test --- ";
		for(int i = 0; i < a.size(); i++){
			cout << endl << i << "." << a.get(i).x;
		}
	}
	return 0;
}
