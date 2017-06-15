/*
 * Topic.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "Topic.h"

Topic::Topic() {
	this->quizzes = new std::vector<Quiz*>();
}

char Topic::getActive() const
{
    return active;
}

int Topic::getId() const
{
    return id;
}

std::string Topic::getName() const
{
    return name;
}

std::vector<Quiz*> *Topic::getQuizzes() const
{
    return quizzes;
}

void Topic::setActive(char active)
{
    this->active = active;
}

void Topic::setId(int id)
{
    this->id = id;
}

void Topic::setName(std::string name)
{
    this->name = name;
}

void Topic::setQuizzes(std::vector<Quiz*> *quizzes)
{
    this->quizzes = quizzes;
}

Topic::~Topic() {
	// TODO Auto-generated destructor stub
}
