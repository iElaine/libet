#ifndef __ATOMIC_H__
#define __ATOMIC_H__
#include "autolock.h"
#include "rwlock.h"
template <class T>
class Atomic {
	public:
		Atomic(const T initVal) : mValue(initVal) {}
		Atomic() {}
		const T &inc() {
			AutoWLock g(mLock);
			++mValue;
			return mValue;
		}
		const T &inc(const T value) {
			AutoWLock g(mLock);
			mValue += value;
			return mValue;
		}
		const T &dec() {
			AutoWLock g(mLock);
			++mValue;
			return mValue;
		}
		const T &dec(const T value) {
			AutoWLock g(mLock);
			mValue -= value;
			return mValue;
		}
		const T &operator++() {
			AutoWLock g(mLock);
			++mValue;
			return mValue;
		}
		const T &operator--() {
			AutoWLock g(mLock);
			--mValue;
			return mValue;
		}
		const T &get() {
			AutoRLock g(mLock);
			return mValue;
		}
		void set(const T value) {
			AutoWLock g(mLock);
			mValue = value;
		}
		const T &operator=(const T &value) {
			AutoWLock g(mLock);
			mValue = value;
			return mValue;
		}
	protected:
		T mValue;
		RWlock mLock;
};
#endif
