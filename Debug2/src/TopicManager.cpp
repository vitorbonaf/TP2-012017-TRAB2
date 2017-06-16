/*
 * TopicManager.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "TopicManager.h"
#include "QuizManager.h"

TopicManager* TopicManager::inst = 0;
int TopicManager::nextTopicID = 1;

TopicManager::TopicManager() {
	this->topics = new std::vector<Topic*>();
}

std::vector<Topic*> *TopicManager::getTopics() const
{
    return topics;
}

TopicManager *TopicManager::instance()
{
	if (TopicManager::inst == NULL){
		TopicManager::inst = new TopicManager();
	}
	return TopicManager::inst;
}

void TopicManager::setTopics(std::vector<Topic*> *topics)
{
    this->topics = topics;
}

TopicManager::~TopicManager() {
	// TODO Auto-generated destructor stub
}

void TopicManager::deleteTopicById(int id)
{
	std::vector<Topic*>::iterator it;
	for(it = topics->begin(); it != topics->end(); ++it){
		if((*it)->getId() == id){
			(*it)->setActive('N');
			std::vector<Quiz*>::iterator it2;
			for(it2 = (*it)->getQuizzes()->begin(); it2 != (*it)->getQuizzes()->end(); ++it2){
				QuizManager::instance()->deleteQuizById((*it2)->getId());
			}
			break;
		}
	}
}

void TopicManager::addTopic(Topic *topic)
{
	topics->push_back(topic);
	TopicManager::nextTopicID++;
}

Topic *TopicManager::searchTopicById(int id)
{
	std::vector<Topic*>::iterator it;
	for(it = topics->begin(); it != topics->end(); ++it){
		if((*it)->getId() == id){
			return (*it);
		}
	}
	return NULL;
}

void TopicManager::addTopicWithoutId(Topic *topic)
{
	topic->setId(TopicManager::nextTopicID);
	topics->push_back(topic);
	TopicManager::nextTopicID++;
}
