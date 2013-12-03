#ifndef _Timer_h_
#define _Timer_h_
#include <functional>
#include <unistd.h>
#include "timevalue.h"
class TimerQueue;
class Timer {
	public:
		Timer(TimeValue tv, TimerQueue* timerqueue, bool exec_in_thread = false);
		virtual void onTimer(){}
		static time_t getTimeSec() { 
			struct timespec tp;
			clock_gettime(CLOCK_MONOTONIC, &tp);
			return tp.tv_sec;
		}
		static TimeValue getTimeValue() {
			struct timespec tp;
			clock_gettime(CLOCK_MONOTONIC, &tp);
			time_t t = tp.tv_nsec;
			return TimeValue(tp.tv_sec, tp.tv_nsec);
		}
		static void sleep(const TimeValue& t) {
			time_t usec = t.sec * 1000000 + t.nsec/1000;
			usleep(usec);
		}
		template<class T>
		struct less : public std::binary_function<T*, T*, bool> {
			bool operator()(const T* t1, const T* t2) const
			{
				return t1->expires() < t2->expires();
			}
		};
		const TimeValue& expires() const { return mExpires;}
		bool isExecInThread() const { return mExecInThread;}
	protected:
		TimerQueue& mQueue;
	private:
		TimeValue mExpires;
		bool mExecInThread;
};

#endif /* _Timer_h_ */

