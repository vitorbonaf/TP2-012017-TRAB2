/*
 * DataLoader.cpp
 *
 *  Created on: 15/06/2017
 *      Author: bonav
 */

#include "DataLoader.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

#include "Question.h"
#include "Topic.h"
#include "Notebook.h"
#include "Quiz.h"
#include "Subject.h"
#include "User.h"
#include "Score.h"

#include "QuestionManager.h"
#include "NotebookManager.h"
#include "QuizManager.h"
#include "SubjectManager.h"
#include "TopicManager.h"
#include "UserManager.h"
#include "ScoreManager.h"

DataLoader* DataLoader::inst = 0;

DataLoader::DataLoader() {
	// TODO Auto-generated constructor stub
}


DataLoader *DataLoader::instance()
{
	if (DataLoader::inst == NULL){
		DataLoader::inst = new DataLoader();
	}
	return DataLoader::inst;
}

void DataLoader::loadQuizzes()
{
	FILE *fp;

	// Abertura de arquivo j� existente
	// Caso n�o exista o arquivo o programa encerra com uma mensagem indicando o erro.
	if((fp = fopen("./Data/quiz.txt", "r")) == NULL){
		std::cout << "Arquivo de quizzes n�o encontrado. Programa encerrado." << std::endl;
		exit(1);
	}else{
		// Print para controle durante o desenvolvimento
		std::cout << "Arquivo de quizzes aberto" << std::endl;

		// lineData � utilizado para leitura da linha
		// charSplit � usado para receber o retorno da fun��o de divis�o pelo separador
		char lineData[250], *charSplit;

		// Vari�vel auxiliar para saber o campo sendo lido no momento
		int i;
		while(!feof(fp)){
			// L� uma linha
			fgets(lineData, 250, fp);
			// Ignora o \n ao final da linha
			charSplit = strtok(lineData, "\n");
			// Separa os dados da linha a cada | (separador escolhido)
			charSplit = strtok(lineData, "|");

			// Alocando mem�ria para o quiz a ser adicionado
			Quiz *quiz= new Quiz();

			// Definindo i = 0 para indicar a leitura do primeiro campo de quest�o
			i = 0;

			// Alocando mem�ria para vector de quest�es
			std::vector<Question*> *questions = new std::vector<Question*>();

			while(charSplit != NULL){
				switch(i){
				// Primeiro campo do arquivo: id
				case 0: quiz->setId(atoi(charSplit));
						break;
				// Segundo campo do arquivo: active
				case 1: quiz->setActive(charSplit[0]);
						break;
				// Terceiro campo do arquivo: name
				case 2:	quiz->setName(std::string(charSplit));
						break;
				// Demais campos do arquivo: id das quest�es do quiz
				default:questions->push_back(QuestionManager::instance()->searchQuestionById(atoi(charSplit)));
						break;
				}
				i++;
				charSplit = strtok(NULL, "|");
			}
			quiz->setQuestions(questions);
			QuizManager::instance()->addQuiz(quiz);
		}


	}

	// Fecha arquivo
	fclose(fp);
	// Print para controle durante o desenvolvimento
	std::cout << "Arquivo de quizzes fechado" << std::endl;

}

void DataLoader::loadUsers()
{
	FILE *fp;

	// Abertura de arquivo j� existente
	// Caso n�o exista o arquivo o programa encerra com uma mensagem indicando o erro.
	if((fp = fopen("./Data/user.txt", "r")) == NULL){
		std::cout << "Arquivo de usu�rios n�o encontrado. Programa encerrado." << std::endl;
		exit(1);
	}else{
		// Print para controle durante o desenvolvimento
		std::cout << "Arquivo de usu�rios aberto" << std::endl;

		// lineData � utilizado para leitura da linha
		// charSplit � usado para receber o retorno da fun��o de divis�o pelo separador
		char lineData[250], *charSplit;

		// Vari�vel auxiliar para saber o campo sendo lido no momento
		int i;
		while(!feof(fp)){
			// L� uma linha
			fgets(lineData, 250, fp);
			// Ignora o \n ao final da linha
			charSplit = strtok(lineData, "\n");
			// Separa os dados da linha a cada | (separador escolhido)
			charSplit = strtok(lineData, "|");

			// Alocando mem�ria para o usu�rio a ser adicionado
			User *user = new User();

			// Definindo i = 0 para indicar a leitura do primeiro campo de quest�o
			i = 0;

			while(charSplit != NULL){
				switch(i){
				// Primeiro campo do arquivo: id
				case 0: user->setId(atoi(charSplit));
						break;
				// Segundo campo do arquivo: active
				case 1: user->setActive(charSplit[0]);
						break;
				// Terceiro campo do arquivo: name
				case 2: user->setName(std::string(charSplit));
						break;
				// Quarto campo do arquivo: login
				case 3: user->setLogin(std::string(charSplit));
						break;
				// Quinto campo do arquivo: password
				case 4: user->setPassword(std::string(charSplit));
						break;
				// Sexto campo do arquivo: profile
				case 5: user->setProfile(charSplit[0]);
						break;
				// S�timo campo do arquivo: notebook
				case 6: user->setNotebook(NotebookManager::instance()->searchNotebookById(atoi(charSplit)));
						break;
				}
				i++;
				charSplit = strtok(NULL, "|");
			}
			UserManager::instance()->addUser(user);
		}


	}

	// Fecha arquivo
	fclose(fp);
	// Print para controle durante o desenvolvimento
	std::cout << "Arquivo de usu�rios fechado" << std::endl;

}

void DataLoader::loadTopics()
{
	FILE *fp;

	// Abertura de arquivo j� existente
	// Caso n�o exista o arquivo o programa encerra com uma mensagem indicando o erro.
	if((fp = fopen("./Data/topic.txt", "r")) == NULL){
		std::cout << "Arquivo de t�picos n�o encontrado. Programa encerrado." << std::endl;
		exit(1);
	}else{
		// Print para controle durante o desenvolvimento
		std::cout << "Arquivo de t�picos aberto" << std::endl;

		// lineData � utilizado para leitura da linha
		// charSplit � usado para receber o retorno da fun��o de divis�o pelo separador
		char lineData[250], *charSplit;

		// Vari�vel auxiliar para saber o campo sendo lido no momento
		int i;
		while(!feof(fp)){
			// L� uma linha
			fgets(lineData, 250, fp);
			// Ignora o \n ao final da linha
			charSplit = strtok(lineData, "\n");
			// Separa os dados da linha a cada | (separador escolhido)
			charSplit = strtok(lineData, "|");

			// Alocando mem�ria para o t�pico a ser adicionado
			Topic *topic= new Topic();

			// Definindo i = 0 para indicar a leitura do primeiro campo de quest�o
			i = 0;

			// Alocando mem�ria para vector de quizzes
			std::vector<Quiz*> *quizzes = new std::vector<Quiz*>();

			while(charSplit != NULL){
				switch(i){
				// Primeiro campo do arquivo: id
				case 0: topic->setId(atoi(charSplit));
						break;
				// Segundo campo do arquivo: active
				case 1: topic->setActive(charSplit[0]);
						break;
				// Terceiro campo do arquivo: name
				case 2:	topic->setName(std::string(charSplit));
						break;
				// Demais campos do arquivo: id dos quizzes do t�pico
				default:quizzes->push_back(QuizManager::instance()->searchQuizById(atoi(charSplit)));
						break;
				}
				i++;
				charSplit = strtok(NULL, "|");
			}

			topic->setQuizzes(quizzes);
			TopicManager::instance()->addTopic(topic);
		}

	}

	// Fecha arquivo
	fclose(fp);
	// Print para controle durante o desenvolvimento
	std::cout << "Arquivo de t�picos fechado" << std::endl;

}

void DataLoader::loadQuestions()
{
	FILE *fp;

	// Abertura de arquivo j� existente
	// Caso n�o exista o arquivo o programa encerra com uma mensagem indicando o erro.
	if((fp = fopen("./Data/question.txt", "r")) == NULL){
		std::cout << "Arquivo de quest�es n�o encontrado. Programa encerrado." << std::endl;
		exit(1);
	}else{
		// Print para controle durante o desenvolvimento
		std::cout << "Arquivo de quest�es aberto" << std::endl;

		// lineData � utilizado para leitura da linha
		// charSplit � usado para receber o retorno da fun��o de divis�o pelo separador
		char lineData[250], *charSplit;

		// Vari�vel auxiliar para saber o campo sendo lido no momento
		int i;
		while(!feof(fp)){
			// L� uma linha
			fgets(lineData, 250, fp);
			// Ignora o \n ao final da linha
			charSplit = strtok(lineData, "\n");
			// Separa os dados da linha a cada | (separador escolhido)
			charSplit = strtok(lineData, "|");

			// Alocando mem�ria para a quest�o a ser adicionada
			Question *question = new Question();

			// Definindo i = 0 para indicar a leitura do primeiro campo de quest�o
			i = 0;

			// Alocando mem�ria para vector de respostas
			std::vector<std::string> *answers = new std::vector<std::string>();

			while(charSplit != NULL){

				switch(i){
				// Primeiro campo do arquivo: id
				case 0: question->setId(atoi(charSplit));
						break;
				// Segundo campo do arquivo: active
				case 1: question->setActive(charSplit[0]);
						break;
				// Terceiro campo do arquivo: text
				case 2:	question->setText(std::string(charSplit));
						break;
				// Terceiro campo do arquivo: type
				case 3:	question->setType(atoi(charSplit));
						break;
				// Quarto campo do arquivo: correct_answer_index
				case 4: question->setCorrect_answer_index(atoi(charSplit));
						break;
				// Quinto campo do arquivo: value
				case 5:	question->setValue(atoi(charSplit));
						break;
				// Demais campos do arquivo: answers
				// "Verdadeiro"|"Falso" para quest�es de V ou F
				// "Resposta 1"|"Resposta 2"|...|"Resposta n" para quest�es de m�ltipla escolha
				default: answers->push_back(std::string(charSplit));
						 break;
				}
				i++;
				charSplit = strtok(NULL, "|");
			}
			// Adicionando respostas � quest�o
			question->setAnswers(answers);
			// Adicionando quest�o ao manager adequado
			QuestionManager::instance()->addQuestion(question);

		}
	}

	// Fecha arquivo
	fclose(fp);
	// Print para controle durante o desenvolvimento
	std::cout << "Arquivo de quest�es fechado" << std::endl;
}

void DataLoader::loadNotebooks()
{

	FILE *fp;

	// Abertura de arquivo j� existente
	// Caso n�o exista o arquivo o programa encerra com uma mensagem indicando o erro.
	if((fp = fopen("./Data/notebook.txt", "r")) == NULL){
		std::cout << "Arquivo de cadernos n�o encontrado. Programa encerrado." << std::endl;
		exit(1);
	}else{
		// Print para controle durante o desenvolvimento
		std::cout << "Arquivo de cadernos aberto" << std::endl;

		// lineData � utilizado para leitura da linha
		// charSplit � usado para receber o retorno da fun��o de divis�o pelo separador
		char lineData[250], *charSplit;

		// Vari�vel auxiliar para saber o campo sendo lido no momento
		int i;
		while(!feof(fp)){
			// L� uma linha
			fgets(lineData, 250, fp);
			// Ignora o \n ao final da linha
			charSplit = strtok(lineData, "\n");
			// Separa os dados da linha a cada | (separador escolhido)
			charSplit = strtok(lineData, "|");

			// Alocando mem�ria para o caderno a ser adicionado
			Notebook *notebook= new Notebook();

			// Definindo i = 0 para indicar a leitura do primeiro campo de quest�o
			i = 0;

			// Alocando mem�ria para vector de disciplinas
			std::vector<Subject*> *subjects = new std::vector<Subject*>();

			while(charSplit != NULL){
				switch(i){
				// Primeiro campo do arquivo: id
				case 0: notebook->setId(atoi(charSplit));
						break;
				// Segundo campo do arquivo: active
				case 1: notebook->setActive(charSplit[0]);
						break;
				// Demais campos do arquivo: id das disciplinas do caderno
				default:subjects->push_back(SubjectManager::instance()->searchSubjectById(atoi(charSplit)));
						break;
				}
				i++;
				charSplit = strtok(NULL, "|");
			}
			notebook->setSubjects(subjects);
			NotebookManager::instance()->addNotebook(notebook);
		}


	}

	// Fecha arquivo
	fclose(fp);
	// Print para controle durante o desenvolvimento
	std::cout << "Arquivo de cadernos fechado" << std::endl;

}

void DataLoader::loadSubjects()
{

	FILE *fp;

	// Abertura de arquivo j� existente
	// Caso n�o exista o arquivo o programa encerra com uma mensagem indicando o erro.
	if((fp = fopen("./Data/subject.txt", "r")) == NULL){
		std::cout << "Arquivo de disciplinas n�o encontrado. Programa encerrado." << std::endl;
		exit(1);
	}else{
		// Print para controle durante o desenvolvimento
		std::cout << "Arquivo de disciplinas aberto" << std::endl;

		// lineData � utilizado para leitura da linha
		// charSplit � usado para receber o retorno da fun��o de divis�o pelo separador
		char lineData[250], *charSplit;

		// Vari�vel auxiliar para saber o campo sendo lido no momento
		int i;
		while(!feof(fp)){
			// L� uma linha
			fgets(lineData, 250, fp);
			// Ignora o \n ao final da linha
			charSplit = strtok(lineData, "\n");
			// Separa os dados da linha a cada | (separador escolhido)
			charSplit = strtok(lineData, "|");

			// Alocando mem�ria para a disciplina a ser adicionada
			Subject *subject= new Subject();

			// Definindo i = 0 para indicar a leitura do primeiro campo de quest�o
			i = 0;

			// Alocando mem�ria para vector de t�picos
			std::vector<Topic*> *topics= new std::vector<Topic*>();

			while(charSplit != NULL){
				switch(i){
				// Primeiro campo do arquivo: id
				case 0: subject->setId(atoi(charSplit));
						break;
				// Segundo campo do arquivo: active
				case 1: subject->setActive(charSplit[0]);
						break;
				// Terceiro campo do arquivo: name
				case 2:	subject->setName(std::string(charSplit));
						break;
				// Demais campos do arquivo: id dos t�picos da disciplina
				default:topics->push_back(TopicManager::instance()->searchTopicById(atoi(charSplit)));
						break;
				}
				i++;
				charSplit = strtok(NULL, "|");
			}
			subject->setTopics(topics);
			SubjectManager::instance()->addSubject(subject);
		}


	}

	// Fecha arquivo
	fclose(fp);
	// Print para controle durante o desenvolvimento
	std::cout << "Arquivo de disciplinas fechado" << std::endl;

}

void DataLoader::loadScores(){
	FILE *fp;

	// Abertura de arquivo j� existente
	// Caso n�o exista o arquivo o programa encerra com uma mensagem indicando o erro.
	if((fp = fopen("./Data/score.txt", "r")) == NULL){
		std::cout << "Arquivo de pontua��es n�o encontrado. Programa encerrado." << std::endl;
		exit(1);
	}else{
		// Print para controle durante o desenvolvimento
		std::cout << "Arquivo de pontua��es aberto" << std::endl;

		// lineData � utilizado para leitura da linha
		// charSplit � usado para receber o retorno da fun��o de divis�o pelo separador
		char lineData[250], *charSplit;

		// Vari�vel auxiliar para saber o campo sendo lido no momento
		int i;
		while(!feof(fp)){
			// L� uma linha
			fgets(lineData, 250, fp);
			// Ignora o \n ao final da linha
			charSplit = strtok(lineData, "\n");
			// Separa os dados da linha a cada | (separador escolhido)
			charSplit = strtok(lineData, "|");

			// Alocando mem�ria para a pontua��o a ser adicionada
			Score *score= new Score();

			// Definindo i = 0 para indicar a leitura do primeiro campo de pontua��o
			i = 0;

			while(charSplit != NULL){
				switch(i){
				// Primeiro campo do arquivo: user
				case 0: score->setUser(std::string(charSplit));
						break;
				// Segundo campo do arquivo: points
				case 1: score->setPoints(atoi(charSplit));
						break;
				// Terceiro campo do arquivo: time
				case 2:	score->setTime(atoi(charSplit));
						break;
				}
				i++;
				charSplit = strtok(NULL, "|");
			}
			ScoreManager::instance()->addScore(score);
		}

	}

	// Fecha arquivo
	fclose(fp);
	// Print para controle durante o desenvolvimento
	std::cout << "Arquivo de pontua��es fechado" << std::endl;
}

void DataLoader::loadData()
{
	// N�o mudar ordem dos loads. Organizado a partir das depend�ncias de uma classe em rela��o a outra.
	// User cont�m Notebook, Notebook cont�m Subject, etc.
	loadQuestions();
	loadQuizzes();
	loadTopics();
	loadSubjects();
	loadNotebooks();
	loadUsers();
	loadScores();
}
DataLoader::~DataLoader() {
	// TODO Auto-generated destructor stub
}
