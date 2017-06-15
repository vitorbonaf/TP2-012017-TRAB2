/*
 * SubjectManager.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "SubjectManager.h"
#include "TopicManager.h"

SubjectManager* SubjectManager::inst = 0;
int SubjectManager::nextSubjectID = 1;

SubjectManager::SubjectManager() {
	this->subjects = new std::vector<Subject*>();
}

std::vector<Subject*> *SubjectManager::getSubjects() const
{
    return subjects;
}

SubjectManager *SubjectManager::instance()
{
	if (SubjectManager::inst == NULL){
		SubjectManager::inst = new SubjectManager();
	}
	return SubjectManager::inst;
}

void SubjectManager::setSubjects(std::vector<Subject*> *subjects)
{
    this->subjects = subjects;
}

SubjectManager::~SubjectManager() {
	// TODO Auto-generated destructor stub
}


void SubjectManager::deleteSubjectById(int id)
{
	std::vector<Subject*>::iterator it;
	for(it = subjects->begin(); it != subjects->end(); ++it){
		if((*it)->getId() == id){
			(*it)->setActive('N');
			std::vector<Topic*>::iterator it2;
			for(it2 = (*it)->getTopics()->begin(); it2 != (*it)->getTopics()->end(); ++it2){
				TopicManager::instance()->deleteTopicById((*it2)->getId());
			}
			break;
		}
	}
}



void SubjectManager::addSubject(Subject *subject)
{
	subjects->push_back(subject);
	SubjectManager::nextSubjectID++;
}



Subject *SubjectManager::searchSubjectById(int id)
{
	std::vector<Subject*>::iterator it;
	for(it = subjects->begin(); it != subjects->end(); ++it){
		if((*it)->getId() == id){
			return (*it);
		}
	}
	return NULL;
}



void SubjectManager::addSubjectWithoutId(Subject *subject)
{
	subject->setId(SubjectManager::nextSubjectID);
	subjects->push_back(subject);
	SubjectManager::nextSubjectID++;
}
