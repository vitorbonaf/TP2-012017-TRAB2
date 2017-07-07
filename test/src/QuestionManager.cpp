/*
 * QuestionManager.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "QuestionManager.h"

QuestionManager* QuestionManager::inst= 0;
int QuestionManager::nextQuestionID = 1;

QuestionManager::QuestionManager() {
	this->questions = new std::vector<Question*>();
}

std::vector<Question*> *QuestionManager::getQuestions() const
{
    return questions;
}

void QuestionManager::setQuestions(std::vector<Question*> *questions)
{
    this->questions = questions;
}

QuestionManager* QuestionManager::instance(){
	if(QuestionManager::inst== NULL){
		QuestionManager::inst= new QuestionManager();
	}
	return QuestionManager::inst;
}

QuestionManager::~QuestionManager() {
	// TODO Auto-generated destructor stub
}

void QuestionManager::deleteQuestionById(int id)
{
	for(unsigned int i = 0; i < questions->size(); i++){
		if(questions->at(i)->getId() == id){
			questions->at(i)->setActive('N');
			break;
		}
	}
}

void QuestionManager::addQuestion(Question *question)
{
	questions->push_back(question);
	QuestionManager::nextQuestionID++;
}

void QuestionManager::addQuestionWithoutId(Question *question)
{
	question->setId(QuestionManager::nextQuestionID);
	questions->push_back(question);
	QuestionManager::nextQuestionID++;
}

Question *QuestionManager::searchQuestionById(int id)
{
	for(unsigned int i = 0; i < questions->size(); i++){
		if(questions->at(i)->getId() == id){
			return questions->at(i);
		}
	}
	return NULL;
}




