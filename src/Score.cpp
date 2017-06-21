/*
 * Score.cpp
 *
 *  Created on: 18/06/2017
 *      Author: bonav
 */

#include "Score.h"

Score::Score() {
	// TODO Auto-generated constructor stub

}

int Score::getPoints() const
{
    return points;
}

int Score::getTime() const
{
    return time;
}

std::string Score::getUser() const
{
    return user;
}

void Score::setPoints(int points)
{
    this->points = points;
}

void Score::setTime(int time)
{
    this->time = time;
}

void Score::setUser(std::string user)
{
    this->user = user;
}

Score::~Score() {
	// TODO Auto-generated destructor stub
}
