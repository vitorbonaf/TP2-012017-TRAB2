/*
 * ControllerTimer.h
 *
 *  Created on: 18/06/2017
 *      Author: bonav
 */

#ifndef CONTROLLERTIMER_H_
#define CONTROLLERTIMER_H_

#include <ctime>

class ControllerTimer {
private:
	ControllerTimer();
	static ControllerTimer *inst;
	time_t startTime;
	time_t endTime;
public:
	static ControllerTimer* instance();
	virtual ~ControllerTimer();
	void startTimer();
	void endTimer();
	int timeElapsed();
};

#endif /* CONTROLLERTIMER_H_ */
