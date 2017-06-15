/*
 * main.cpp
 *
 *  Created on: 15/06/2017
 *      Author: bonav
 */
#include "./Loader-Writer/DataLoader.h"

int main(){

	DataLoader *dataLoader = DataLoader::instance();

	dataLoader->loadData();

	return 0;
}
