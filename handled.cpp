#include "handled.h"
#include "handlemanager.h"
Handled::Handled(HandleManager& mgr) : 
	mHandleManager(mgr), 
	mId(0) 
{
	mId= mHandleManager.create(this);
}

Handled::~Handled() 
{
	mHandleManager.remove(mId);
}
