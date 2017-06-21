/*
 * ScoreManager.h
 *
 *  Created on: 18/06/2017
 *      Author: bonav
 */

#ifndef SCOREMANAGER_H_
#define SCOREMANAGER_H_

#include <vector>

#include "Score.h"

class ScoreManager {
private:
	ScoreManager();
	static ScoreManager *inst;
	std::vector<Score*> *scores;
public:
	static ScoreManager* instance();
	virtual ~ScoreManager();
	void addScore(Score *score);
	std::vector<Score*>* getScores();
};

#endif /* SCOREMANAGER_H_ */
