#include "gtest/gtest.h"
#include "timevalue.h"
#include "timer.h"
#include <algorithm>
#include <queue>
#include <tinyxml.h>
#include "handled.h"
#include "handlemanager.h"
#include "log.h"
#include "sharedptr.h"
using namespace std;

bool LogInitializer::bInitialized = LogInitializer::init();

TEST(TimeValue, Test)
{
	TimeValue tv1(1,2);
	TimeValue tv2(1,3);
	TimeValue tv3(2,5);
	TimeValue tv4(4,1);
	// logic
	ASSERT_TRUE(tv1 < tv2);
	ASSERT_TRUE(tv4 >= tv2);
	ASSERT_TRUE(tv1 != tv2);
	ASSERT_TRUE(tv1 == tv1);
	// arg
	ASSERT_EQ((tv1 + tv2), tv3);
}

TEST(PriorityQueue, Test)
{
	for(int rep = 0; rep < 10;++rep)
	{
		srand(clock());
		priority_queue<Timer*, vector<Timer*>, Timer::less<Timer> > h;
		for(int i=0;i<10;++i)
		{
			h.push(new Timer(TimeValue(rand(),0), NULL));
		}
		Timer *e1, *e2;
		e1 = e2 = h.top();
		for(int i=0;i<10;++i)
		{
			ASSERT_TRUE(e1->expires() >= e2->expires());
			h.pop();
			e1 = e2;
			e2 = h.top();
		}
	}
}

class testhandled : public Handled {
	public:
		testhandled(HandleManager& mgr) : Handled(mgr) {}
		Handled::Id id() const { return mId;}
		virtual const char *name() const { return "testhandled";}
};

TEST(HandleManager, Test)
{
	HandleManager mgr;
	Handled::Id id;
	{
		testhandled h(mgr);
		id = h.id();
		ASSERT_NO_THROW(mgr.getHandled(id));
		testhandled *th = static_cast<testhandled*>(mgr.getHandled(id));
		ASSERT_EQ(th->id(), 1);
	}
	testhandled *ph = new testhandled(mgr);
	EXPECT_ANY_THROW(mgr.getHandled(id));
	ASSERT_NO_THROW(mgr.getHandled(ph->id()));
	delete ph;
	EXPECT_ANY_THROW(mgr.getHandled(ph->id()));
}

TEST(SharedPtrTest,test)
{
	SharedPtr<int> a(new int(0));
	ASSERT_TRUE(a.unique());
	SharedPtr<int> b = a;
	ASSERT_FALSE(a.unique());
}
