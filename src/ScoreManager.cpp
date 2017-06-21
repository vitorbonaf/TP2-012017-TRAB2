/*
 * ScoreManager.cpp
 *
 *  Created on: 18/06/2017
 *      Author: bonav
 */

#include "ScoreManager.h"

#include <cstdlib>

ScoreManager* ScoreManager::inst = 0;

ScoreManager::ScoreManager() {
	this->scores = new std::vector<Score*>();
}

ScoreManager::~ScoreManager() {
	// TODO Auto-generated destructor stub
}

ScoreManager* ScoreManager::instance(){
	if (ScoreManager::inst == NULL){
		ScoreManager::inst = new ScoreManager();
	}
	return ScoreManager::inst;
}

void ScoreManager::addScore(Score *score){
	scores->push_back(score);
}

std::vector<Score*>* ScoreManager::getScores(){
	return scores;
}
