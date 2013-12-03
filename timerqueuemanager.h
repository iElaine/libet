#ifndef _TimerQueueManager_h_
#define _TimerQueueManager_h_
#include "timerqueue.h"

class TimerQueueManager {
	public:
		static TimerQueue* createTimerQueue(const char *name)
		{
			std::string tq_name(name);
			std::map<std::string, TimerQueue*>::iterator itr = mTimerQueues.find(tq_name);
			if(itr != mTimerQueues.end())
			{
				return NULL;
			}
			TimerQueue* new_queue = new TimerQueue();
			if(new_queue)
			{
				mTimerQueues.insert(make_pair(tq_name, new_queue));
				return new_queue;
			}
			return NULL;
		}
		static void destroyTimerQueue(const char *name)
		{
			std::string tq_name(name);
			std::map<std::string, TimerQueue*>::iterator itr = mTimerQueues.find(tq_name);
			if(itr != mTimerQueues.end())
			{
				if(itr->second)
				{
					itr->second->cancelAllTimers();
					delete itr->second;
				}
				mTimerQueues.erase(itr);
			}
		}
		static void getTimerQueue(const char *name)
		{
			std::string tq_name(name);
			std::map<std::string, TimerQueue*>::iterator itr = mTimerQueues.find(tq_name);
			if(itr != mTimerQueues.end())
			{
				return itr->second;
			}
			return NULL;
		}
	protected:
		std::map<std::string, TimerQueue*> mTimerQueues;
};
#endif /* _TimerQueueManager_h_ */

