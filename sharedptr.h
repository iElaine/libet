#ifndef __SharedPtr_h__
#define __SharedPtr_h__
template <class T>
class SharedPtr
{
	public:
		SharedPtr(T* p) : mPtr(p) {
			if(mPtr)
				mPtr->addRef();
		}
		~SharedPtr() {
			if(mPtr)
			{
				if(!mPtr->decRef())
				{
					delete mPtr;
				}
			}
		}
		SharedPtr(const SharedPtr& ptr) : mPtr(ptr.get()) {
			if(mPtr)
				mPtr->addRef();
		}
		template <class Y>
		SharedPtr(const SharedPtr<Y>& ptr) : mPtr(ptr.get()) {
			if(mPtr)
				mPtr->addRef();
		}
		SharedPtr& operator=(const SharedPtr& ptr) {
			mPtr = ptr.mPtr;
			if(mPtr)
				mPtr->addRef();
			return *this;
		}
		virtual bool operator==(const SharedPtr& ptr) const {
			return mPtr == ptr.mPtr;
		}
		virtual T* get() { return mPtr;}
		virtual void reset(T* p) {
			if(mPtr)
			{
				if(!mPtr->decRef())
					delete mPtr;
			}
			mPtr = p;
			if(mPtr)
				mPtr->addRef();
		}
		T* operator->() { return mPtr;}
		const T* operator->() const { return mPtr;}
		T& operator*() { return *mPtr;}
		const T& operator*() const { return *mPtr;}
	protected:
		T* mPtr;
}
#endif

