#ifndef __HandleManager_h__
#define __HandleManager_h__
#include <map>
#include "handleexception.h"
#include "handled.h"
class HandleManager {
	public:
		HandleManager();
		bool isValidHandle(Handled::Id id) const;
		Handled* getHandled(Handled::Id id);
	protected:
		friend class Handled;
		Handled::Id create(Handled *h);
		void remove(Handled::Id id);
		typedef std::map<Handled::Id, Handled*> HandleMap;
		HandleMap mHandles;
		Handled::Id mLastId;
};
#endif /* __Handled_h__ */
