//============================================================================
// Name        : CppUtils.cpp
// Author      : Pawel Mlynarczyk <pawel@zwrss.pl>
// Description : Simple utils for C++.
//============================================================================

#include <iostream>
#include "ArrayList.cpp"
using namespace std;

void arrayListTest(ArrayList *a){
	cout << endl << " -- test -- " << endl;
	for(int i = 0; i < a->size(); i++){
		cout << endl << i << ". " << a->get(i) << endl;
	}
}

int main() {
	ArrayList<int> *a = new ArrayList<int>();
	a->put(1);
	a->put(2);
	a->put(5);
	a->put(8);
	a->test();
	a->remove(2);
	a->test();
	a->remove(0);
	a->test();
	a->remove(0);
	a->remove(0);
	a->test();
	return 0;
}
