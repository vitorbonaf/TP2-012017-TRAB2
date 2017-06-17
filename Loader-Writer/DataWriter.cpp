/*
 * DataWriter.cpp
 *
 *  Created on: 16/06/2017
 *      Author: bonav
 */

#include "DataWriter.h"

#include <vector>
#include <fstream>

#include "../Entity/Question.h"
#include "../Entity/Topic.h"
#include "../Entity/Notebook.h"
#include "../Entity/Quiz.h"
#include "../Entity/Subject.h"
#include "../Entity/User.h"

#include "../Manager/QuestionManager.h"
#include "../Manager/NotebookManager.h"
#include "../Manager/QuizManager.h"
#include "../Manager/SubjectManager.h"
#include "../Manager/TopicManager.h"
#include "../Manager/UserManager.h"

DataWriter* DataWriter::inst = 0;

DataWriter::DataWriter() {
	// TODO Auto-generated constructor stub

}

void DataWriter::saveSubjects()
{
	std::ofstream fp("./Data/subject.txt");

	std::vector<Subject*> *subjects = SubjectManager::instance()->getSubjects();

	for(unsigned int i = 0; i < subjects->size(); i++){
		if(i !=0){
			fp << std::endl;
		}

		fp << subjects->at(i)->getId() << "|";
		fp << subjects->at(i)->getActive() << "|";
		fp << subjects->at(i)->getName();

		std::vector<Topic*> *topics = subjects->at(i)->getTopics();
		for(unsigned int j = 0; j < topics->size(); j++){
			fp << "|" << topics->at(j)->getId();
		}
	}

	fp.close();
}

void DataWriter::saveUsers()
{
	std::ofstream fp("./Data/user.txt");

	std::vector<User*> *users = UserManager::instance()->getUsers();

	for(unsigned int i = 0; i < users->size(); i++){
		if(i !=0){
			fp << std::endl;
		}

		fp << users->at(i)->getId() << "|";
		fp << users->at(i)->getActive() << "|";
		fp << users->at(i)->getName() << "|";
		fp << users->at(i)->getLogin() << "|";
		fp << users->at(i)->getPassword() << "|";
		fp << users->at(i)->getProfile() << "|";
		fp << users->at(i)->getNotebook()->getId();
	}

	fp.close();
}

void DataWriter::saveQuestions()
{
	std::ofstream fp("./Data/question.txt");

	std::vector<Question*> *questions = QuestionManager::instance()->getQuestions();

	for(unsigned int i = 0; i < questions->size(); i++){
		if(i !=0){
			fp << std::endl;
		}

		fp << questions->at(i)->getId() << "|";
		fp << questions->at(i)->getActive() << "|";
		fp << questions->at(i)->getText() << "|";
		fp << questions->at(i)->getType() << "|";
		fp << questions->at(i)->getCorrect_answer_index() << "|";
		fp << questions->at(i)->getValue();

		std::vector<std::string> *answers= questions->at(i)->getAnswers();

		for(unsigned int j = 0; j < answers->size(); j++){
			fp << "|" << answers->at(j);
		}

	}

	fp.close();
}

void DataWriter::saveQuizzes()
{
	std::ofstream fp("./Data/quiz.txt");

	std::vector<Quiz*> *quizzes = QuizManager::instance()->getQuizzes();

	for(unsigned int i = 0; i < quizzes->size(); i++){
		if(i !=0){
			fp << std::endl;
		}

		fp << quizzes->at(i)->getId() << "|";
		fp << quizzes->at(i)->getActive() << "|";
		fp << quizzes->at(i)->getName();

		std::vector<Question*> *questions= quizzes->at(i)->getQuestions();

		for(unsigned int j = 0; j < questions->size(); j++){
			fp << "|" << questions->at(j)->getId();
		}

	}

	fp.close();
}

void DataWriter::saveNotebooks()
{
	std::ofstream fp("./Data/notebook.txt");

	std::vector<Notebook*> *notebooks = NotebookManager::instance()->getNotebooks();

	for(unsigned int i = 0; i < notebooks->size(); i++){
		if(i !=0){
			fp << std::endl;
		}

		fp << notebooks->at(i)->getId() << "|";
		fp << notebooks->at(i)->getActive();


		std::vector<Subject*> *subjects= notebooks->at(i)->getSubjects();

		for(unsigned int j = 0; j < subjects->size(); j++){
			fp << "|" << subjects->at(j)->getId();
		}

	}

	fp.close();
}

void DataWriter::saveTopics()
{
	std::ofstream fp("./Data/topic.txt");

	std::vector<Topic*> *topics= TopicManager::instance()->getTopics();

	for(unsigned int i = 0; i < topics->size(); i++){
		if(i !=0){
			fp << std::endl;
		}

		fp << topics->at(i)->getId() << "|";
		fp << topics->at(i)->getActive() << "|";
		fp << topics->at(i)->getName();

		std::vector<Quiz*> *quizzes= topics->at(i)->getQuizzes();

		for(unsigned int j = 0; j < quizzes->size(); j++){
			fp << "|" << quizzes->at(j)->getId();
		}

	}

	fp.close();
}

DataWriter::~DataWriter() {
	// TODO Auto-generated destructor stub
}

void DataWriter::saveData()
{
	// Os objetos podem ser salvos em qualquer ordem sem alteração no resultado
	saveQuestions();
	saveQuizzes();
	saveTopics();
	saveSubjects();
	saveNotebooks();
	saveUsers();
}

DataWriter *DataWriter::instance()
{
	if (DataWriter::inst == NULL){
		DataWriter::inst = new DataWriter();
	}
	return DataWriter::inst;
}
