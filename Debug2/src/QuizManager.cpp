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
	std::vector<Quiz*>::iterator it;
	for(it = quizzes->begin(); it != quizzes->end(); ++it){
		if((*it)->getId() == id){
			(*it)->setActive('N');
			std::vector<Question*>::iterator it2;
			for(it2 = (*it)->getQuestions()->begin(); it2 != (*it)->getQuestions()->end(); ++it2){
				QuestionManager::instance()->deleteQuestionById((*it2)->getId());
			}
			break;
		}
	}
}

Quiz *QuizManager::searchQuizById(int id)
{
	std::vector<Quiz*>::iterator it;
	for(it = quizzes->begin(); it != quizzes->end(); ++it){
		if((*it)->getId() == id){
			return (*it);
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
