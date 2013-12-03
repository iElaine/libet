#include "handlemanager.h"
#include "log.h"

HandleManager::HandleManager() :
	mLastId(0)
{
}

bool HandleManager::isValidHandle(Handled::Id id) const 
{
	return mHandles.count(id) != 0;
}
Handled* HandleManager::getHandled(Handled::Id id) 
{
	HandleMap::iterator i = mHandles.find(id);
	if(i == mHandles.end())
	{
		throw HandleException("Stale Handle", __FILE__, __LINE__);
	}
	return i->second;
}

Handled::Id HandleManager::create(Handled *h) 
{
	mHandles[++mLastId] = h;
	DebugLog("HandleManager add Handled["<<h<<"]"<<" id="<<mLastId);
	return mLastId;
}

void HandleManager::remove(Handled::Id id)
{
	HandleMap::iterator i = mHandles.find(id);
	Handled* handled = NULL;
	if(i != mHandles.end())
	{
		mHandles.erase(i);
	}
}

