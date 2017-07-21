/*
 * TransactionHelper.h
 *
 *  Created on: 2014��11��8��
 *      Author: Thoughtworks
 */

#ifndef TRANSACTIONHELPER_H_
#define TRANSACTIONHELPER_H_
#include "../Transaction/ActionBasedTransaction.h"

template <typename ACTION>
class TRANSACTION__ : public ActionBasedTransaction{
public:
	SchedAction& getSchedAction(){
		return _action;
	}
private:
	ACTION _action;
};


#endif /* TRANSACTIONHELPER_H_ */
