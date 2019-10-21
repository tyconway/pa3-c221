#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
using namespace std;

struct EmptyPQ : public exception
{
	const char* what() const throw ()
	{
		return "Priority Qeque is empty.";
	}
};

#endif