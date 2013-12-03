#ifndef __Shared_h__
#define __Shared_h__
#include "autolock.h"
class Shared {
	public:
		Shared() { mRefCounter = 1;}
		size_t addRef()
		{
			AutoLock g(mLock);
			++mRefCounter;
			return mRefCounter;
		}
		size_t decRef()
		{
			AutoLock g(mLock);
			--mRefCounter;
			return mRefCounter;
		}
	private:
		size_t mRefCounter;
		Mutex mLock;
};
#endif
