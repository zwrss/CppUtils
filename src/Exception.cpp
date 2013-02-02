#ifndef __EXCEPTION_INTERFACE_INCLUDED__
#define __EXCEPTION_INTERFACE_INCLUDED__

#include <string>
using namespace std;

class Exception {
public:
	virtual string message() = 0;
	virtual ~Exception(){};
};

#endif
