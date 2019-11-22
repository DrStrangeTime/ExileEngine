#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Headers.h"

// Object interface
class Object
{
protected:
	
	std::string		_name;	// Object name

public:
	Object();
	virtual ~Object() {}

	
	std::string&	GetName();

	void			SetName(std::string x);
};

#endif