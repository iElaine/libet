/**
 * @file messagereceiver.h
 * @author TommyWang Email<xuchu1986@gmail.com>
 * @brief 
 */
#ifndef __MessageProcessor_H__
#define __MessageProcessor_H__
#include "squeue.h"
#include "message.h"
class MessageProcessor {
	public:
		/**
		 * @brief constructor
		 */
		MessageProcessor(bool processblock = false) : mbProcessBlock(processblock) {}

		/**
		 * @brief destructor
		 */
		virtual ~MessageProcessor() {}

		/**
		 * post a message to the receiver
		 */
		virtual void post(Message *message) { mMessageFifo.add(message);}

		/**
		 * Interface to be called in a thread to process all messages
		 * in the FIFO
		 * @param timeout	timeout to get message if set blockmode
		 */
		virtual void process(time_t timeout) 
		{
			Message *msg;
			if(mbProcessBlock)
			{
				mMessageFifo.get(msg);
				this->onRxMessage(msg);
				delete msg;
			}
			else
			{
				if(mMessageFifo.tryget(msg))
				{
					this->onRxMessage(msg);
					delete msg;
				}
			}
		}
	protected:
		Squeue<Message*> mMessageFifo;
		virtual void onRxMessage(Message* msg) = 0;
		bool mbProcessBlock;
};
#endif /* __MessageProcessor_H__*/
