#include "baseexception.h"
BaseException::BaseException(const Data& message, 
		const Data& filename, 
		int line) : 
	mMessage(message), 
	mFilename(filename), 
	mLine(line) 
{
}

BaseException::~BaseException() throw() 
{
}
