/*
 * TransactionDSL.h
 *
 *  Created on: 2014��11��8��
 *      Author: Thoughtworks
 */

#ifndef TRANSACTIONDSL_H_
#define TRANSACTIONDSL_H_

#include "../helper/SequentialSchedActionHelper.h"
#include "../helper/TransactionHelper.h"
#include "../helper/AsyncHelper.h"

#define __async(...) ASYNC__<__VA_ARGS__>

#define __sequential(...) SEQUENTIAL__<__VA_ARGS__ >

#define __transaction(...)  TRANSACTION__<__VA_ARGS__ >


#endif /* TRANSACTIONDSL_H_ */
