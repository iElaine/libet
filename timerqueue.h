#ifndef _TimerQueue_h_
#define _TimerQueue_h_
#include "threadif.h"
#include <map>
#include <queue>
#include <memory>
#include "timer.h"
#include "threadpool.h"

class ThreadPool;
typedef void (*TimerCallback)(void *);
class TimerQueue 
{
	public:
		TimerQueue(int nworker) { 
			if(nworker)
			{
				mThreadPool = new ThreadPool(nworker);
				mUseThreadPool = true;
			}
			else
			{
				mThreadPool = NULL;
				mUseThreadPool = false;
			}
		}
		int addTimer(std::auto_ptr<Timer> timer);
		int addTimer(Timer *timer);
		int addTimer(int ms, TimerCallback& cb, void *param);
		int cancelTimer(int handle);
		bool hasThreadPool() const { return mUseThreadPool;}
		void poll();
	protected:
		void cancelAllTimers();
		std::priority_queue<Timer*, std::vector<Timer*>, Timer::less<Timer> > mTimerQueue;
		ThreadPool *mThreadPool;
		bool	mUseThreadPool;
};

class TimerQueueThread : public ThreadIf 
{
	public:
		TimerQueueThread(TimerQueue& queue) : mTimerQueue(queue) {}
	protected:
		virtual void thread() {
			while(!isStop())
			{
				mTimerQueue.poll();
			}
		}
		TimerQueue &mTimerQueue;
};

#endif /* _TimerQueue_h_ */

