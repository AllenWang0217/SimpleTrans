/*
 * ActionStatus.h
 *
 *  Created on: 2014��11��8��
 *      Author: Thoughtworks
 */

#ifndef ACTIONSTATUS_H_
#define ACTIONSTATUS_H_
#include "CommonDefine.h"

class ActionStatus {
public:
	ActionStatus():status(SUCCESS){
	}

	ActionStatus(const Status status):status(status)
	{
	}

	bool isDone()const{
		return status == SUCCESS;
	}

	ActionStatus& operator=(const ActionStatus& rhs){
		status = rhs.status;
		return *this;
	}

	//ActionStatus��Status����ת��ʹ��
	operator Status()const{
		return status;
	}
private:
	Status status;
};





#endif /* ACTIONSTATUS_H_ */
