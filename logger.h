#ifndef __Logger_h__
#define __Logger_h__

class Logger {
	public:
		void operator<<(const ostream& os) {
		}
		void poll() {

		};
	protected:
		struct LogMessage {
		};
		Squeue<LogMessage> mPendingLogMessages;
};
#endif
