/*
 * main.cpp
 *
 *  Created on: 15/06/2017
 *      Author: bonav
 */

#include <vector>
#include <iostream>

#include "Loader-Writer/DataLoader.h"
#include "Entity/Question.h"
#include "Entity/Quiz.h"
#include "Entity/Topic.h"
#include "Entity/Subject.h"
#include "Entity/Notebook.h"
#include "Entity/User.h"

#include "Manager/QuestionManager.h"
#include "Manager/QuizManager.h"
#include "Manager/TopicManager.h"
#include "Manager/SubjectManager.h"
#include "Manager/NotebookManager.h"
#include "Manager/UserManager.h"


int main(){

	// Comando para carregar os dados dos arquivos
	DataLoader::instance()->loadData();

	/*
	 * Bloco de teste que printa todas as questões
	 */
	std::cout << "************" << std::endl;
	std::cout << "* QUESTÕES *" << std::endl;
	std::cout << "************" << std::endl << std::endl;

	std::vector<Question*> *questions = QuestionManager::instance()->getQuestions();
	std::cout << "Questions quantity: " << questions->size() << std::endl << std::endl;

	for(unsigned int i = 0; i < questions->size(); i++){
		std::cout << "ID: " << questions->at(i)->getId()
					<< "\tACTIVE: " << questions->at(i)->getActive() << std::endl
					<< "TEXT: " << questions->at(i)->getText() << std::endl
					<< "TYPE: " << questions->at(i)->getType()
					<< "\tVALUE: " << questions->at(i)->getValue()
					<< "\tCORRECT ANSWER INDEX: " << questions->at(i)->getCorrect_answer_index() << std::endl
					<< "RESPOSTAS: " << std::endl;

		std::vector<std::string> *respostas = questions->at(i)->getAnswers();
		for(unsigned int j = 0; j < respostas->size(); j++){
			std::cout << "INDICE: " << j << "\tRESPOSTA: " << respostas->at(j) << std::endl;
		}
		std::cout << std::endl << std::endl;
	}

	/*
	 * Bloco de teste que printa todos os quizzes
	 */
	std::cout << "***********" << std::endl;
	std::cout << "* QUIZZES *" << std::endl;
	std::cout << "***********" << std::endl << std::endl;

	std::vector<Quiz*> *quizzes = QuizManager::instance()->getQuizzes();
	std::cout << "Quizzes quantity: " << quizzes->size() << std::endl << std::endl;

	for(unsigned int i = 0; i < quizzes->size(); i++){
		std::cout << "ID " << quizzes->at(i)->getId()
					<< "\tACTIVE: " << quizzes->at(i)->getActive() << std::endl
					<< "NAME: " << quizzes->at(i)->getName() << std::endl
					<< "QUESTÕES ASSOCIADAS:";

		std::vector<Question*> *questionsQ = quizzes->at(i)->getQuestions();

		for(unsigned int j = 0; j < questionsQ->size(); j++){
			std::cout << "\t" << questionsQ->at(j)->getId();
		}
		std::cout << std::endl << std::endl;
	}

	/*
	 * Bloco de teste que printa todos os tópicos
	 */
	std::cout << "***********" << std::endl;
	std::cout << "* TÓPICOS *" << std::endl;
	std::cout << "***********" << std::endl << std::endl;

	std::vector<Topic*> *topics = TopicManager::instance()->getTopics();
	std::cout << "Topics quantity: " << topics->size() << std::endl << std::endl;

	for(unsigned int i = 0; i < topics->size(); i++){
		std::cout << "ID " << topics->at(i)->getId()
							<< "\tACTIVE: " << topics->at(i)->getActive() << std::endl
							<< "NAME: " << topics->at(i)->getName() << std::endl
							<< "QUIZZES ASSOCIADOS:";
		std::vector<Quiz*> *quizzesT = topics->at(i)->getQuizzes();

		for(unsigned int j = 0; j < quizzesT->size(); j++){
			std::cout << "\t" << quizzesT->at(j)->getId();
		}
		std::cout << std::endl << std::endl;
	}

	/*
	 * Bloco de teste que printa todas as disciplinas
	 */
	std::cout << "***************" << std::endl;
	std::cout << "* DISCIPLINAS *" << std::endl;
	std::cout << "***************" << std::endl << std::endl;

	std::vector<Subject*> *subjects = SubjectManager::instance()->getSubjects();
	std::cout << "Subjects quantity: " << topics->size() << std::endl << std::endl;

	for(unsigned int i = 0; i < subjects->size(); i++){
		std::cout << "ID " << subjects->at(i)->getId()
					<< "\tACTIVE: " << subjects->at(i)->getActive() << std::endl
					<< "NAME: " << subjects->at(i)->getName() << std::endl
					<< "TÓPICOS ASSOCIADOS:";
		std::vector<Topic*> *topicosS = subjects->at(i)->getTopics();

		for(unsigned int j = 0; j < topicosS->size(); j++){
			std::cout << "\t" << topicosS->at(j)->getId();
		}
		std::cout << std::endl << std::endl;
	}

	/*
	 * Bloco de teste que printa todos os cadernos
	 */
	std::cout << "************" << std::endl;
	std::cout << "* CADERNOS *" << std::endl;
	std::cout << "************" << std::endl << std::endl;

	std::vector<Notebook*> *notebooks = NotebookManager::instance()->getNotebooks();
	std::cout << "Notebooks quantity: " << notebooks->size() << std::endl << std::endl;

	for(unsigned int i = 0; i < notebooks->size(); i++){
		std::cout << "ID " << notebooks->at(i)->getId()
					<< "\tACTIVE: " << notebooks->at(i)->getActive() << std::endl
					<< "DISCIPLINAS ASSOCIADAS:";
		std::vector<Subject*> *subjectN = notebooks->at(i)->getSubjects();

		for(unsigned int j = 0; j < subjectN->size(); j++){
			std::cout << "\t" << subjectN->at(j)->getId();
		}
		std::cout << std::endl << std::endl;
	}

	/*
	 * Bloco de teste que printa todos os cadernos
	 */
	std::cout << "************" << std::endl;
	std::cout << "* USUÁRIOS *" << std::endl;
	std::cout << "************" << std::endl << std::endl;

	std::vector<User*> *users= UserManager::instance()->getUsers();
	std::cout << "Users quantity: " << users->size() << std::endl << std::endl;

	for(unsigned int i = 0; i < users->size(); i++){
		std::cout << "ID " << users->at(i)->getId() << "\tACTIVE: " << users->at(i)->getActive() << std::endl;
		std::cout << "NAME: " << users->at(i)->getName() << "\tPROFILE: " << users->at(i)->getProfile() << std::endl;
		std::cout << "LOGIN: " << users->at(i)->getLogin() << "\tPASSWORD: " << users->at(i)->getPassword() << std::endl;
		std::cout << "CADERNO ASSOCIADO: " << users->at(i)->getNotebook()->getId() << std::endl << std::endl;
	}


	return 0;
}
