/*
 * Subject.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "Subject.h"

Subject::Subject() {
	this->topics = new std::vector<Topic*>();
}

char Subject::getActive() const
{
    return active;
}

int Subject::getId() const
{
    return id;
}

std::string Subject::getName() const
{
    return name;
}

std::vector<Topic*> *Subject::getTopics() const
{
    return topics;
}

void Subject::setActive(char active)
{
    this->active = active;
}

void Subject::setId(int id)
{
    this->id = id;
}

void Subject::setName(std::string name)
{
    this->name = name;
}

void Subject::setTopics(std::vector<Topic*> *topics)
{
    this->topics = topics;
}

Subject::~Subject() {
	// TODO Auto-generated destructor stub
}
