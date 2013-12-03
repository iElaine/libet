#ifndef _TimeValue_h_
#define _TimeValue_h_
#include <time.h>
class TimeValue {
	public:
		TimeValue (time_t s, time_t ns) : sec(s), nsec(ns) {}
		TimeValue () : sec(0), nsec(0) {}
		void set(time_t s, time_t ns) { sec = s; nsec = ns;}
		bool operator==(const TimeValue& tv) const { return (sec == tv.sec) && (nsec == tv.nsec);}
		bool operator>(const TimeValue& tv) const { 
			if(sec > tv.sec)
				return true;
			else if(sec < tv.sec)
				return false;
			if(nsec > tv.nsec)
				return true;
			else if(nsec < tv.nsec)
				return false;
			return false;
		}
		bool operator<(const TimeValue& tv) const { 
			if(sec > tv.sec)
				return false;
			else if(sec < tv.sec)
				return true;
			if(nsec > tv.nsec)
				return false;
			else if(nsec < tv.nsec)
				return true;
			return false;
		}
		bool operator>=(const TimeValue& tv) const { return !(*this < tv);}
		bool operator<=(const TimeValue& tv) const { return !(*this > tv);}
		bool operator!=(const TimeValue& tv) const { return !(*this == tv);}
		TimeValue operator+(const TimeValue& tv) { 
			TimeValue t;
			t.sec = sec + tv.sec;
			t.nsec = nsec + tv.nsec;
			if(t.nsec > 1000000000)
			{
				t.sec++;
				t.nsec -= 1000000000;
			}
			return t;
		}
		TimeValue& operator+=(const TimeValue& tv) { 
			TimeValue& t = *this;
			t.sec = sec + tv.sec;
			t.nsec = nsec + tv.nsec;
			if(t.nsec > 1000000000)
			{
				t.sec++;
				t.nsec -= 1000000000;
			}
			return t;
		}
		TimeValue operator-(const TimeValue& tv) {
			TimeValue t;
			t.sec = sec - tv.sec;
			if(sec > tv.sec)
			{
				t.nsec = tv.nsec - nsec;
				t.sec--;
			}
			return t;
		}

		TimeValue& operator-=(const TimeValue& tv) {
			TimeValue &t = *this;
			t.sec = sec - tv.sec;
			if(sec > tv.sec)
			{
				t.nsec = tv.nsec - nsec;
				t.sec--;
			}
			return t;
		}
		time_t sec;
		time_t nsec;
};
#endif /* _TimeValue_h_ */
