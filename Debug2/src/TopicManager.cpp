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
	for(unsigned int i = 0; i < topics->size(); i++){
		if(topics->at(i)->getId() == id){
			topics->at(i)->setActive('N');
			for(unsigned int j = 0; j < topics->at(i)->getQuizzes()->size(); j++){
				QuizManager::instance()->deleteQuizById(topics->at(i)->getQuizzes()->at(j)->getId());
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
	for(unsigned int i = 0; i < topics->size(); i++){
		if(topics->at(i)->getId() == id){
			return topics->at(i);
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
