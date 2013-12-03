#ifndef __Serializable_h__
#define __Serializable_h__
class Serializable {
	public:
		virtual int serialize(const char* record_name, const char *filename) const 
		{
		}
		virtual int deSerialize(const char* record_name, const char *filename)
		{
		}
		virtual void encode(string& coded) = 0;
		virtual void decode(string& coded) = 0;
};
#endif /* __Serializable_h__ */
