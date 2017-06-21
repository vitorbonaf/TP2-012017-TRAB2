/*
 * ControllerTimer.cpp
 *
 *  Created on: 18/06/2017
 *      Author: bonav
 */

#include "ControllerTimer.h"

#include <cstdlib>

ControllerTimer* ControllerTimer::inst = 0;

ControllerTimer::ControllerTimer() {
	// TODO Auto-generated constructor stub

}

ControllerTimer::~ControllerTimer() {
	// TODO Auto-generated destructor stub
}

ControllerTimer* ControllerTimer::instance(){
	if (ControllerTimer::inst == NULL){
		ControllerTimer::inst = new ControllerTimer();
	}
	return ControllerTimer::inst;
}

void ControllerTimer::startTimer(){
	time(&startTime);
}

void ControllerTimer::endTimer(){
	time(&endTime);
}

int ControllerTimer::timeElapsed(){
	int tempo = endTime - startTime;
	startTime = 0;
	endTime = 0;
	return tempo;
}
