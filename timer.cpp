#include <cassert>
#include "timer.h"
#include "timerqueue.h"
using namespace std;

Timer::Timer(TimeValue tv, TimerQueue* timerqueue, bool exec_in_thread) : 
	mQueue(*timerqueue), 
	mExpires(Timer::getTimeValue() + tv),
	mExecInThread(exec_in_thread)
{
//	mQueue.addTimer(this);	
}
