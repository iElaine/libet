#include "timerqueue.h"
class CbTimer : public Timer {
	public:
		CbTimer(TimeValue tv, TimerQueue* tq, TimerCallback& cb, void *param) : Timer(tv, tq), mCallback(cb), mParam(param) {}
		virtual void onTimer() { mCallback(mParam);}
	protected:
		TimerCallback mCallback;
		void *mParam;
};

class TimerTask : public Task {
	public:
		TimerTask(Timer* t) : mTimer(t) {}
		virtual int operator()() {
			if(mTimer)
			{
				mTimer->onTimer();
				delete mTimer;
				mTimer = NULL;
			}
			return Task::EXIT;
		}
	protected:
		Timer *mTimer;
};

int TimerQueue::addTimer(std::auto_ptr<Timer> timer)
{
	mTimerQueue.push(timer.release());
	return 0;
}
int TimerQueue::addTimer(Timer *timer)
{
	mTimerQueue.push(timer);
	return 0;
}
int TimerQueue::addTimer(int ms, TimerCallback& cb, void *param)
{
	TimeValue tv;
	tv.sec = ms/1000;
	tv.nsec = (ms - tv.sec * 1000) * 1000000;
	Timer* timer = new CbTimer(tv, this, cb, param);
	if(!timer)
		return -1;
	mTimerQueue.push(timer);
	return 0;
}
int TimerQueue::cancelTimer(int handle)
{
	return 0;
}

void TimerQueue::poll()
{
	TimeValue now = Timer::getTimeValue();
	Timer* t = mTimerQueue.top();
	if(t->expires() >= now)
	{
		mTimerQueue.pop();
		if(t->isExecInThread())
		{
			TimerTask *q = new TimerTask(t);
			mThreadPool->submitTask(q);
		}
		else
		{
			t->onTimer();
			delete t;
		}
	}
	else
		Timer::sleep(now - t->expires());
}
