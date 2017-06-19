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
	for(unsigned int i = 0; i < subjects->size(); i++){
		if(subjects->at(i)->getId() == id){
			subjects->at(i)->setActive('N');
			for(unsigned int j = 0; j < subjects->at(i)->getTopics()->size(); j++){
				TopicManager::instance()->deleteTopicById(subjects->at(i)->getTopics()->at(j)->getId());
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
	for(unsigned int i = 0; i < subjects->size(); i++){
		if(subjects->at(i)->getId() == id){
			return subjects->at(i);
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
