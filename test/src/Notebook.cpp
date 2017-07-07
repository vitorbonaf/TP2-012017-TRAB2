/*
 * Notebook.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "Notebook.h"

Notebook::Notebook() {
	this->subjects = new std::vector<Subject*>();
}

char Notebook::getActive() const
{
    return active;
}

int Notebook::getId() const
{
    return id;
}

std::vector<Subject*> *Notebook::getSubjects() const
{
    return subjects;
}

void Notebook::setActive(char active)
{
    this->active = active;
}

void Notebook::setId(int id)
{
    this->id = id;
}

void Notebook::setSubjects(std::vector<Subject*> *subjects)
{
    this->subjects = subjects;
}

Notebook::~Notebook() {
	// TODO Auto-generated destructor stub
}
