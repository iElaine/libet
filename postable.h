#ifndef __Postable_h__
#define __Postable_h__
#include "squeue.h"
#include "message.h"
class Postable {
	public:
		virtual void post(Message* msg) {
			mFifo.add(msg);
		}	
	protected:
		Squeue<Message*> mFifo;
};
#endif
