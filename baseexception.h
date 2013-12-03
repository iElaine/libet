#ifndef __BaseException__h__
#define __BaseException__h__
#include <stdexcept>
#include "data.h"
class BaseException : public std::exception {
	public:
		virtual const char *name() const = 0;
		const Data& getMessage() const { return mMessage;}
		virtual const char *what() const throw() { return mMessage.c_str();}
	protected:
		BaseException(const Data& message, 
				const Data& filename, 
				int line);
		virtual ~BaseException() throw();
		Data mMessage;
		Data mFilename;
		int  mLine;
};
#endif /* __BaseException__h__ */
