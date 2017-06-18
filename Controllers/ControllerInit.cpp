#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#include <cstdlib>
#include <string>
#include <iostream>

#include "ControllerInit.h"

#include "../Loader-Writer/DataLoader.h"
#include "../Loader-Writer/DataWriter.h"

ControllerInit* ControllerInit::inst = 0;
/// INITIALIZATION MODULE

ControllerInit::ControllerInit(){

}
void ControllerInit::initializeSystem(){
	DataLoader::instance()->loadData();
	showUI();
}

ControllerInit* ControllerInit::instance(){
	if (ControllerInit::inst == NULL){
		ControllerInit::inst = new ControllerInit();
	}
	return ControllerInit::inst;
}

ControllerInit::~ControllerInit() {
}

void ControllerInit::showUI() {
    /// Esta funcao mostra o menu principal do QuizTime para o usuario, recebe a
    /// informacao sobre o que o usuario gostaria de fazer e solicita o servico
    /// requerido a interface adequada.

    int sel = -1;

	system(CLEAR);
	std::cout << "QuizTime - Menu principal\n\n";

	if(user == NULL) {
		std::cout << "1. Fazer log-in\n";
	} else {
		std::cout << "1. Gerenciar informacoes pessoais\n";
		std::cout << "2. Gerenciar disciplinas\n";
		std::cout << "3. Responder quiz\n";
		if(user->getProfile() == 'A') {
			std::cout << "4. Gerenciar banco de dados de alunos\n";
			std::cout << "5. Gerenciar banco de dados de disciplinas\n";
		}
		std::cout << "9. Fazer log-out\n";
	}
	std::cout << "0. Sair\n";
	std::cout << "\nInforme a opcao desejada: ";

	std::cin >> sel;

	if(user == NULL){
		switch(sel){
		case 1: user = ControllerAuth::instance()->requestAuth(); showUI();break;
		case 0: DataWriter::instance()->saveData(); break;
		default: showUI();
		}
	}else{
		if (user->getProfile() == 'A'){
			switch(sel) {
			case 1: ControllerUser::instance()->manageUserData(user); break;
			case 2: ControllerUser::instance()->manageUserSubjects(user); break;
			case 3: ControllerQuiz::instance()->answerQuiz(user); showUI(); break;
			case 4: ControllerAdmin::instance()->manageStudents(); break;
			case 5: ControllerAdmin::instance()->manageSubjects(); break;
			case 9: user = NULL; showUI(); break;
			case 0: DataWriter::instance()->saveData();break;
			default: showUI();
			}
		}else{
			switch(sel){
			case 1: ControllerUser::instance()->manageUserData(user); break;
			case 2: ControllerUser::instance()->manageUserSubjects(user); break;
			case 3: ControllerQuiz::instance()->answerQuiz(user); showUI(); break;
			case 9: user = NULL; showUI();break;
			case 0: DataWriter::instance()->saveData();break;
			default: showUI();
			}
		}
	}

} 

User* ControllerInit::getLoggedUser(){
	return user;
}
