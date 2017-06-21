/*
 * Quiz.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "Quiz.h"

Quiz::Quiz() {
	this->questions = new std::vector<Question*>();
}

char Quiz::getActive() const
{
    return active;
}

int Quiz::getId() const
{
    return id;
}

std::string Quiz::getName() const
{
    return name;
}

std::vector<Question*> *Quiz::getQuestions() const
{
    return questions;
}

void Quiz::setActive(char active)
{
    this->active = active;
}

void Quiz::setId(int id)
{
    this->id = id;
}

void Quiz::setName(std::string name)
{
    this->name = name;
}

void Quiz::setQuestions(std::vector<Question*> *questions)
{
    this->questions = questions;
}

Quiz::~Quiz() {
	// TODO Auto-generated destructor stub
}
