/*
 * Score.h
 *
 *  Created on: 18/06/2017
 *      Author: bonav
 */

#ifndef SCORE_H_
#define SCORE_H_

#include <string>

class Score {
private:
	std::string user;
	int points;
	int time;
public:
	Score();
	virtual ~Score();
    int getPoints() const;
    int getTime() const;
    std::string getUser() const;
    void setPoints(int points);
    void setTime(int time);
    void setUser(std::string user);
};

#endif /* SCORE_H_ */
