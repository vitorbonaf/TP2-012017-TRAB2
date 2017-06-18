#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#include <cstdlib>
#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "ControllerUser.h"
#include "ControllerInit.h"

#include "../Manager/SubjectManager.h"

#include "../Entity/User.h"
#include "../Entity/Subject.h"

/// USER MODULE
ControllerUser* ControllerUser::inst = 0;

ControllerUser::ControllerUser () { }
ControllerUser::~ControllerUser() { }

ControllerUser* ControllerUser::instance(){
	if (ControllerUser::inst == NULL){
		ControllerUser::inst = new ControllerUser();
	}
	return ControllerUser::inst;
}

void ControllerUser::manageUserData(User * user) {
    /// Esta funcao exibe o menu de alteracao das informacoes pessoais do usuario,
    /// recebe uma solicitacao e chama a funcao adequada para processar a
    /// solicitacao recebida.
    int sel = -1;

	system(CLEAR);
	std::cout << "QuizTime - Gerenciamento de Informacoes Pessoais\n\n";
	std::cout << "1. Alterar nome\n";
	std::cout << "2. Alterar senha\n";
	std::cout << "0. Voltar\n";
	std::cout << "\nInforme a opcao desejada: ";

	std::cin  >> sel;

	switch(sel) {
		case 1: changeName(user); manageUserData(user); break;
		case 2: changePass(user); manageUserData(user); break;
		case 0: ControllerInit::instance()->showUI(); break;
		default: manageUserData(user);
	}

}

void ControllerUser::manageUserSubjects(User * user) {
    /// Esta funcao exibe o menu de gerenciamento de disciplinas do usuario, recebe
    /// uma solicitacao e chama a funcao adequada para processar a solicitacao.
    int sel = -1;

	system(CLEAR);
	std::cout << "QuizTime - Gerenciamento de Disciplinas\n\n";

	std::cout << "1. Mostrar disciplinas em curso\n";
	std::cout << "2. Fazer matricula em disciplina\n";
	std::cout << "3. Trancar disciplina\n";
	std::cout << "0. Voltar\n";
	std::cout << "\nInforme a opcao desejada: ";

	std::cin  >> sel;

	switch(sel) {
		case 1: showSubjects(user);   manageUserSubjects(user); break;
		case 2: includeSubject(user); manageUserSubjects(user); break;
		case 3: removeSubject(user);  manageUserSubjects(user); break;
		case 0: ControllerInit::instance()->showUI(); break;
		default: manageUserSubjects(user); break;
	}

}

void ControllerUser::changeName(User * user) {
    /// Esta funcao recebe do usuario uma entrada para alteracao de nome e altera o
    /// nome do usuario.
    std::string name;
    std::string new_name;
    name = user->getName();
    system(CLEAR);
    std::cout << "QuizTime - Alterar Nome\n\n";
    std::cout << "O seu nome atual È: " << name << "\n";
    std::cout << "Insira um novo nome: ";
    // Primeiro getline usado para limpar o buffer
    getline(std::cin, new_name);
    getline(std::cin, new_name);

    user->setName(new_name);
}

void ControllerUser::changePass(User * user) {
    /// Esta funcao recebe do usuario uma entrada para alteracao de senha e altera a
    /// senha do usuario.
    std::string new_pass;
    system(CLEAR);
    std::cout << "QuizTime - Alterar Senha\n\n";
    std::cout << "Senha atual: " << user->getPassword() << "\n";
    std::cout << "Nova senha: ";
    // Primeiro getline usado para limpar o buffer
    getline(std::cin, new_pass);
    getline(std::cin, new_pass);
    user->setPassword(new_pass);
}

void ControllerUser::showSubjects(User * user) {
	std::vector<Subject*> *subjects = user->getNotebook()->getSubjects();
	std::string aux;
	std::cout << std::endl << "Disciplinas em curso:" << std::endl;
    for(unsigned int i = 0; i < subjects->size(); i++){
    	std:: cout << i+1 << ". " << subjects->at(i)->getName() << std::endl;
    }
    getline(std::cin, aux);
    getline(std::cin, aux);
}

bool ControllerUser::subjectInNotebook(User *user, Subject *subject){
	std::vector<Subject*> *subjects = user->getNotebook()->getSubjects();
	for(unsigned int i = 0; i < subjects->size(); i++){
		if(subjects->at(i)->getId() == subject->getId()){
			return true;
		}
	}
	return false;
}

void ControllerUser::includeSubject(User * user) {
    /// Esta funcao permite ao usuario selecionar uma disciplina na qual ele deseje
    /// se matricular e inclui a disciplina no caderno do usuario.
    std::map <int, Subject*> subs_map;
    int sel = -1;
    int i;
    while(sel != 0) {
        //auto subs=user->getNotebook()->getSubjects();
        system(CLEAR);
        std::cout <<"QuizTime - Matricula em Disciplina\n\n";
        i = 1;
        //for(auto it:*(SubjectManager::instance()->getSubjects())){
        for(unsigned int j = 0; j < SubjectManager::instance()->getSubjects()->size(); j++){
            Subject * sub = SubjectManager::instance()->getSubjects()->at(j);
            if((!subjectInNotebook(user, sub)) && (sub->getActive() == 'S')){
            	std::cout << i << sub->getName() << "\n";
				subs_map[i] = sub;
				i++;
            }
        }
        std::cout << "0. Voltar\n";
        std::cout << "\nInforme a opcao desejada: ";
        std::cin  >> sel;

        while(sel < 0 || sel >= i){
        	std::cout << "\n\nOpÁ„o inv·lida.";
			std::cout << "\nInforme a opÁ„o desejada novamente: ";
			std::cin  >> sel;
        }

        if(sel != 0) {
        	user->getNotebook()->getSubjects()->push_back(subs_map[sel]);
        }
    }
}

void ControllerUser::removeSubject(User * user) {
    /// Esta funcao solicida ao modulo de logica de negocio a lista das disciplinas
    /// cadastradas, mostra um menu ao usuario para que ele selecione uma disciplina
    /// para trancamento e solicita ao m√≥dulo de logica de negocio que realize a
    /// remocao da disciplina selecionada.
    std::map <int, Subject*> subs_map;
    int sel = -1;
    int i;
    while(sel != 0) {
        system(CLEAR);
        std::cout << "QuizTime - Trancamento de Disciplina\n\n";
        i = 1;
        //for(auto it:*(user->getNotebook()->getSubjects())) {       //TODO: verificar se isso funciona
        for(unsigned int j = 0; j < user->getNotebook()->getSubjects()->size(); j++){
            Subject *sub = user->getNotebook()->getSubjects()->at(j);
            std::cout << i << sub->getName() << "\n";
            subs_map[i] = sub;
            i++;
        }

        std::cout << "0. Voltar\n";
        std::cout << "\nInforme a opcao desejada: ";
        std::cin  >> sel;

        while(sel < 0 || sel >= i){
			std::cout << "\n\nOpÁ„o inv·lida.";
			std::cout << "\nInforme a opÁ„o desejada novamente: ";
			std::cin  >> sel;
		}

        if(sel != 0) {
        	user->getNotebook()->getSubjects()->erase(user->getNotebook()->getSubjects()->begin()+sel-1);
        }
    }
}
