/*
 * TestTransaction.cpp
 *
 *  Created on: 2014��11��7��
 *      Author: Thoughtworks
 */
#include <gtest/gtest.h>
#include "../include/Transaction/TransactionDSL.h"
#include "SimpleAction.h"

DEF_ACTION(Action1, EV_EVENT_1);
DEF_ACTION(Action2, EV_EVENT_2);
DEF_ACTION(Action3, EV_EVENT_3);

class TestTransaction: public testing::Test {
public:
	void SetUp() {
	}
	void TearDown() {

	}
protected:
	__transaction(
		__sequential(
			__async(Action1),
			__async(Action2),
			__sequential( __async(Action3),
						  __async(Action2),
						  __async(Action1))
			)
	)trans1;

	__transaction(
			__sequential(
					__async(Action1),__async(Action1),__async(Action1),
					__async(Action1),__async(Action1),__async(Action1),
					__async(Action1),__async(Action1),__async(Action1),
					__async(Action1),__async(Action1),__async(Action1),
					__async(Action1),__async(Action1),__async(Action1)
			)
	)trans2;
			
};

TEST_F(TestTransaction, return_unkown_when_error_event)
{
	EXPECT_EQ(CONTINUE, trans1.start());
	EXPECT_EQ(UNKNOWN_EVENT, trans1.handleEvent(EV_EVENT_2));
}

TEST_F(TestTransaction, return_unkown_when_error_event_before_start)
{
	EXPECT_EQ(UNKNOWN_EVENT, trans1.handleEvent(EV_EVENT_2));
}

TEST_F(TestTransaction, can_schedule_sequetial_actions)
{
	EXPECT_EQ(CONTINUE, trans1.start());
	EXPECT_EQ(CONTINUE, trans1.handleEvent(EV_EVENT_1));
	EXPECT_EQ(CONTINUE, trans1.handleEvent(EV_EVENT_2));
	EXPECT_EQ(CONTINUE, trans1.handleEvent(EV_EVENT_3));
	EXPECT_EQ(CONTINUE, trans1.handleEvent(EV_EVENT_2));
	EXPECT_EQ(SUCCESS, trans1.handleEvent(EV_EVENT_1));
	EXPECT_EQ(UNKNOWN_EVENT, trans1.handleEvent(EV_EVENT_2));
}

TEST_F(TestTransaction, can_holds_15_acitons){
	EXPECT_EQ(CONTINUE, trans2.start());
	int actionNum = 0;
	while(1){
		Status status = trans2.handleEvent(EV_EVENT_1);
		actionNum++;
		if (CONTINUE != status){
			break;
		}
	}
	EXPECT_EQ(15, actionNum);
}
