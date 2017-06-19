/*
 * QuizManager.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "QuizManager.h"
#include "QuestionManager.h"

QuizManager* QuizManager::inst = 0;
int QuizManager::nextQuizID = 1;

QuizManager::QuizManager() {
	this->quizzes = new std::vector<Quiz*>();
}

std::vector<Quiz*> *QuizManager::getQuizzes() const
{
    return quizzes;
}

QuizManager *QuizManager::instance()
{
	if (QuizManager::inst == NULL){
		QuizManager::inst = new QuizManager();
	}
	return QuizManager::inst;
}

void QuizManager::setQuizzes(std::vector<Quiz*> *quizzes)
{
    this->quizzes = quizzes;
}

QuizManager::~QuizManager()
{
	// TODO Auto-generated destructor stub
}

void QuizManager::addQuiz(Quiz *quiz)
{
	quizzes->push_back(quiz);
	QuizManager::nextQuizID++;
}

void QuizManager::deleteQuizById(int id)
{
	for(unsigned int i = 0; i < quizzes->size(); i++){
		if(quizzes->at(i)->getId() == id){
			quizzes->at(i)->setActive('N');
			std::vector<Question*>::iterator it2;
			for(unsigned int j = 0; j < quizzes->at(i)->getQuestions()->size(); j++){
				QuestionManager::instance()->deleteQuestionById(quizzes->at(i)->getQuestions()->at(j)->getId());
			}
			break;
		}
	}
}

Quiz *QuizManager::searchQuizById(int id)
{
	for(unsigned int i = 0; i < quizzes->size(); i++){
		if(quizzes->at(i)->getId() == id){
			return quizzes->at(i);
		}
	}
	return NULL;
}

void QuizManager::addQuizWithoutId(Quiz *quiz)
{
	quiz->setId(QuizManager::nextQuizID);
	quizzes->push_back(quiz);
	QuizManager::nextQuizID++;
}
