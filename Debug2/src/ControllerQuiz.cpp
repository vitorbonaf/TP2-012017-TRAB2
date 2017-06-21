#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#include "ControllerQuiz.h"

#include "User.h"
#include "Quiz.h"
#include "Question.h"
#include "Subject.h"
#include "Topic.h"
#include "Notebook.h"
#include "Score.h"

#include "ControllerTimer.h"
#include "ScoreManager.h"


#include <vector>
#include <map>
#include <string>
#include <iostream>
#include<algorithm>
ControllerQuiz* ControllerQuiz::inst = 0;

ControllerQuiz::ControllerQuiz(){

}

ControllerQuiz* ControllerQuiz::instance(){
	if (ControllerQuiz::inst == NULL){
		ControllerQuiz::inst = new ControllerQuiz();
	}
	return ControllerQuiz::inst;
}

void ControllerQuiz::answerQuiz(User * user) {

	std::map <int, Subject*> subs_map;
	std::map <int, Topic*> tops_map;
	std::map <int, Quiz*> quiz_map;
	std::string name, quest, bufferClear;
	int sel1 = -1, sel2 = -1, sel3 = -1;
	int i;
	int answer;
	int points = 0;

	while(sel1 != 0) {
		system(CLEAR);
		std::cout << "QuizTime - Responder Quiz\n\n";
		i = 1;
		std::vector<Subject*> *subjects = user->getNotebook()->getSubjects();
		for(unsigned int j = 0; j < subjects->size(); j++){
			Subject *sub = subjects->at(j);
			if(sub->getActive() == 'S'){
				std::cout << i << ". "<< sub->getName() << "\n";
				subs_map[i] = sub;
				i++;
			}

		}
		std::cout << "0. Voltar\n";
		std::cout << "\nSelecione uma disciplina para responder o quiz: ";
		std::cin  >> sel1;

		if(sel1 != 0 && sel1 < i) {
			while(sel2 != 0) {
				system(CLEAR);
				std::cout << "QuizTime - Responder Quiz\n\n";
				i = 1;
				for(unsigned int k = 0; k < subs_map[sel1]->getTopics()->size(); k++){
					Topic * top = subs_map[sel1]->getTopics()->at(k);
					if(top->getActive() == 'S'){
					std::cout << i <<". "<< top->getName() << "\n";
						tops_map[i] = top;
						i++;
					}
				}
				std::cout << "0. Voltar\n";
				std::cout << "\nSelecione um topico para responder o quiz: ";
				std::cin  >> sel2;

				if(sel2 != 0 && sel2 < i) {
					while(sel3 != 0){
						system(CLEAR);
						std::cout << "QuizTime - Responder Quiz\n\n";
						i = 1;
						for(unsigned int l = 0; l < tops_map[sel2]->getQuizzes()->size(); l++){
							Quiz * quiz = tops_map[sel2]->getQuizzes()->at(l);
							std::cout << i <<". "<< quiz->getName() << "\n";
							quiz_map[i] = quiz;
							i++;
						}
						std::cout << "0. Voltar\n";
						std::cout << "\nSelecione um quiz para responder: ";
						std::cin  >> sel3;
						getline(std::cin, bufferClear);
						if(sel3 != 0 && sel3 < i){
							Quiz *quiz = quiz_map[sel3];
							ControllerTimer::instance()->startTimer();
							for(unsigned int j = 0; j < quiz->getQuestions()->size(); j++){
								system(CLEAR);
								std::cout << quiz->getName() << std::endl;
								std::cout << "\n" << j+1 << ". " << quiz->getQuestions()->at(j)->getText() << std::endl << std::endl;
								std::cout << "1. Responder" << std::endl << "0. Pular" << std::endl << std::endl;
								std::cout << "Selecione uma opção: ";
								std::cin >> answer;
								getline(std::cin, bufferClear);

								while(answer != 0 && answer != 1){
									std::cout << "\nSelecione uma opção: ";
									std::cin >> answer;
									getline(std::cin, bufferClear);
								}

								if(answer){
									system(CLEAR);
									std::cout << quiz->getName() << std::endl;
									std::cout << "\n" << j+1 << ". " << quiz->getQuestions()->at(j)->getText() << std::endl << std::endl;
									std::cout << "Respostas:" << std::endl;
									for(unsigned int k = 0; k < quiz->getQuestions()->at(j)->getAnswers()->size(); k++){
										std::cout << k+1 << ". " << quiz->getQuestions()->at(j)->getAnswers()->at(k) << std::endl;
									}
									std::cout << "Selecione uma resposta (1-" << quiz->getQuestions()->at(j)->getAnswers()->size() << "): ";
									std::cin >> answer;
									getline(std::cin, bufferClear);
									while(answer < 1 || (unsigned int) answer > quiz->getQuestions()->at(j)->getAnswers()->size()){
										std::cout << "Selecione uma resposta válida (1-" << quiz->getQuestions()->at(j)->getAnswers()->size() << "): ";
										std::cin >> answer;
										getline(std::cin, bufferClear);
									}
									if((answer-1) == quiz->getQuestions()->at(j)->getCorrect_answer_index()){
										points += quiz->getQuestions()->at(j)->getValue();
									}
								}
							}
							ControllerTimer::instance()->endTimer();
							//Colocar adição de pontos aqui ao invés de printar o resultado
							Score *score = new Score();
							score->setUser(user->getLogin());
							score->setPoints(points);
							score->setTime(ControllerTimer::instance()->timeElapsed());
							std::cout << "Usuario: " << score->getUser() << "\tPoints: " << score->getPoints() << "\tTime: " << score->getTime();
							ScoreManager::instance()->addScore(score);
							getline(std::cin, bufferClear);
						}else{
							if(sel3!=0){
								std::cout << "Selecao de quiz invalida.\n";
								getline(std::cin, bufferClear);
							}
						}
					}
				} else {
					if(sel2 != 0) {
						std::cout << "Selecao de topico invalida.\n";
						getline(std::cin, bufferClear);
					}
				}
			}
		} else {
			if(sel1 != 0) {
				std::cout << "Selecao de disciplina invalida.\n";
				getline(std::cin, bufferClear);
			}
		}
	}

}
