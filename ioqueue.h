class IOQueue {
	public:
		void Poll();
		bool registerExternal(int fd, int type);
};

class IOQueueThread : public ThreadIf {
	public:
		IOQueueThread(IOQueue& ioqueue);
	protected:
		virtual void thread();
		IOQueue& mIOQueue;
};

