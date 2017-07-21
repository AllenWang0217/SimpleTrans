/*
 * SyncAction.h
 *
 *  Created on: 2014��11��7��
 *      Author: Thoughtworks
 */

#ifndef SYNCACTION_H_
#define SYNCACTION_H_
#include "Event.h"
#include "../Common/CommonDefine.h"
#include "../Common/Role.h"

DEF_ROLE(SyncAction)
{
public:
	ABSTRACT(Status exec());
};

#endif /* SYNCACTION_H_ */
