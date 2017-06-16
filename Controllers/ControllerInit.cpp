#include <cstdlib>
#include <string>
#include <iostream>
#include "ControllerInit.h"
#include "ControllerAuth.h"
#include "ControllerUser.h"
#include "ControllerAdmin.h"
#include "ControllerQuiz.h"

/// INITIALIZATION MODULE

void ControllerInit::initialize() {
    /// Esta funcao cria todas os modulos e interfaces e define as relacoes do tipo
    /// cliente-servidor.
    this->controllerAuth  = new ControllerAuth();
    this->controllerUser  = new ControllerUser();
    this->controllerAdmin = new ControllerAdmin();
    this->controllerQuiz  = new ControllerQuiz();
}

ControllerInit::~ControllerInit() {
    /// Destrutor da classe controladora de inicializacao. Destroi todos os modulos.
    delete controllerAuth;
    delete controllerUser;
    delete controllerAdmin;
    delete controllerQuiz;
}

void ControllerInit::showUI() {
    /// Esta funcao mostra o menu principal do QuizTime para o usuario, recebe a
    /// informacao sobre o que o usuario gostaria de fazer e solicita o servico
    /// requerido a interface adequada.

    int sel = -1;
    while(sel != 0) {
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

        switch(sel) {
            case 1: user = this->controllerAuth->requestAuth();     sel = -1; break;
            case 2: this->controllerUser->manageUserSubjects(user); sel = -1; break;
            case 3: this->controllerQuiz->answerQuiz(user);         sel = -1; break;
            case 4: this->controllerAdmin->manageStudents();        sel = -1; break;
            case 5: this->controllerAdmin->manageSubjects();        sel = -1; break;
            case 9: user = NULL;                                    sel = -1; break;
            default: break;
        }
    }
} 
