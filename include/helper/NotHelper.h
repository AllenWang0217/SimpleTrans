/*
 * notHelper.h
 *
 *  Created on: 2014��11��9��
 *      Author: Thoughtworks
 */

#ifndef NOTHELPER_H_
#define NOTHELPER_H_

template<typename CONDITION>
class NOT__
{
public:
	bool operator()(){
		return !condition();
	}
private:
	CONDITION condition;
};




#endif /* NOTHELPER_H_ */
