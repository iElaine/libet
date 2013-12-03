#ifndef __Handled_h__
#define __Handled_h__
#include "handleexception.h"
class HandleManager;
class Handled {
	public:
		typedef unsigned long Id;
		Handled(HandleManager& mgr);
		~Handled();
		virtual const char *name() const = 0;
	protected:
		HandleManager& mHandleManager;
		Id mId;
};
#endif /* __Handled_h__ */
