/*
* SyncHelper.h
*
*  Created on: 2014��11��9��
*      Author: Thoughtworks
*/

#ifndef SYNCHELPER_H_
#define SYNCHELPER_H_
#include "../SchedAction/SyncActionAdapter.h"

template <typename ACTION>
class SYNC__ : public SyncActionAdapter {
public:
	SyncAction& getSyncAction() {
		return action;
	}
private:
	ACTION action;
};

#endif /* SYNCHELPER_H_ */
