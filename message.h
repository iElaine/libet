/**
 * @file message.h
 * @author TommyWang Email<xuchu1986@gmail.com>
 * @brief 
 */
#ifndef __MESSAGE_H__
#define __MESSAGE_H__
#include <iostream>
class Message {
	public:
		virtual std::ostream& encode(std::ostream& os) const = 0;
		virtual Message* clone() const = 0;
};
#endif /* __MESSAGE_H__ */
