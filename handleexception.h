#ifndef __HandleException_h__
#define __HandleException_h__
#include "baseexception.h"
class HandleException : public BaseException {
	public:
		virtual const char* name() const { return "HandleException";}

		HandleException(const Data& message, 
				const Data& filename, 
				int line) : 
			BaseException(message, filename, line) {}
};
#endif /* __HandleException_h__ */
