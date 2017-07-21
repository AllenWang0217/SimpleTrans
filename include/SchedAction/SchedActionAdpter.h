/*
 * SchedActionAdpter.h
 *
 *  Created on: 2014��11��7��
 *      Author: Thoughtworks
 */

#ifndef SCHEDACTIONADPTER_H_
#define SCHEDACTIONADPTER_H_
#include "SchedAction.h"
#include "../Action/Action.h"

class SchedActionAdapter : public SchedAction
{
public:
	Status exec(){
		return ROLE(Action).exec();
	}
	Status handleEvent(const Event& event){
		return ROLE(Action).handleEvent(event);
	}
private:
	USE_ROLE(Action);
};


#endif /* SCHEDACTIONADPTER_H_ */
