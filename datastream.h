class DataStream {
	public:
		DataStream(Data&);
		DataStream& operator<<(const long);
		DataStream& operator<<(const unsigned long);
		DataStream& operator<<(const double);
		DataStream& operator<<(const char*);
		DataStream& operator<<(const char);
		DataStream& operator<<(const std::string&);
		DataStream& operator<<(const Data&);
		void flush();
	protected:
		Data& mData; 
};
