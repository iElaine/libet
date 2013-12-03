#ifndef __SharedPointer_h__
#define __SharedPointer_h__
template <class T>
class SharedPointer {
	public:
		virtual T* get() { return 
	protected:
		template <class PtrType>
		class Wrapper : public Shared {
			public:
				Wrapper(PtrType *p) {
					mPtr = p;
				}
				inline PtrType* get() { return mPtr;}
			protected:
				PtrType * mPtr;
		}
		Wrapper<T> mWrapper;
};
#endif
