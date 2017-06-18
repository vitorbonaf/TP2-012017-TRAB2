/*
 * main.cpp
 *
 *  Created on: 15/06/2017
 *      Author: bonav
 */

#include "Controllers/ControllerInit.h"

int main(){

	ControllerInit::instance()->initializeSystem();

	return 0;
}
