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
#include "User.h"
#include "SubjectManager.h"

/// USER MODULE

ControllerUser::ControllerUser () { }
ControllerUser::~ControllerUser() { }

void ControllerUser::manageUserData(User * user) {
    /// Esta funcao exibe o menu de alteracao das informacoes pessoais do usuario,
    /// recebe uma solicitacao e chama a funcao adequada para processar a
    /// solicitacao recebida.
    int sel = -1;
    while(sel != 0) {
        system(CLEAR);
        std::cout << "QuizTime - Gerenciamento de Informacoes Pessoais\n\n";
        std::cout << "1. Alterar nome\n";
        std::cout << "2. Alterar senha\n";
        std::cout << "0. Voltar\n";
        std::cout << "\nInforme a opcao desejada: ";

        std::cin  >> sel;

        switch(sel) {
            case 1: changeName(user); sel = -1; break;
            case 2: changePass(user); sel = -1; break;
            default: break;
        }
    }
}

void ControllerUser::manageUserSubjects(User * user) {
    /// Esta funcao exibe o menu de gerenciamento de disciplinas do usuario, recebe
    /// uma solicitacao e chama a funcao adequada para processar a solicitacao.
    int sel = -1;
    while(sel != 0) {
        system(CLEAR);
        std::cout << "QuizTime - Gerenciamento de Disciplinas\n\n";

        std::cout << "1. Mostrar disciplinas em curso\n";
        std::cout << "2. Fazer matricula em disciplina\n";
        std::cout << "3. Trancar disciplina\n";
        std::cout << "0. Voltar\n";
        std::cout << "\nInforme a opcao desejada: ";

        std::cin  >> sel;

        switch(sel) {
            case 1: showSubjects(user);   sel = -1; break;
            case 2: includeSubject(user); sel = -1; break;
            case 3: removeSubject(user);  sel = -1; break;
            default: break;
        }
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
    std::cout << "O seu nome atual é" << name << "\n";
    std::cout << "Insira um novo nome: ";
    getline(std::cin, new_name);

    user->setName(name);
}

void ControllerUser::changePass(User * user) {
    /// Esta funcao recebe do usuario uma entrada para alteracao de senha e altera a
    /// senha do usuario.
    std::string new_pass;
    system(CLEAR);
    std::cout << "QuizTime - Alterar Senha\n\n";
    std::cout << "Senha atual: " << user->getPassword() << "\n";
    std::cout << "Nova senha: ";
    getline(std::cin, new_pass);
    user->setPassword(new_pass);
}

void ControllerUser::showSubjects(User * user) {
    //user->showSubjects();  //TODO
    //getchar();
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
        printf("QuizTime - Matricula em Disciplina\n\n");
        i = 1;
        for(auto it:*(SubjectManager::instance()->getSubjects())){
            //TODO: verificar se a disciplina nao esta no caderno do usuario!
            Subject * sub = it;
            std::cout << i << sub->getName() << "\n";
            subs_map[i] = sub;
            i++;
        }
        std::cout << "0. Voltar\n";
        std::cout << "\nInforme a opcao desejada: ";
        std::cin  >> sel;

        if(sel != 0 && sel < i) {
            //user->getNotebook()->addSubject(subs_map[sel]); //TODO: colocar a funcao certa
        }
    }
}

void ControllerUser::removeSubject(User * user) {
    /// Esta funcao solicida ao modulo de logica de negocio a lista das disciplinas
    /// cadastradas, mostra um menu ao usuario para que ele selecione uma disciplina
    /// para trancamento e solicita ao módulo de logica de negocio que realize a
    /// remocao da disciplina selecionada.
    std::map <int, Subject*> subs_map;
    int sel = -1;
    int i;
    while(sel != 0) {
        system(CLEAR);
        printf("QuizTime - Trancamento de Disciplina\n\n");
        i = 1;
        for(auto it:*(user->getNotebook()->getSubjects())) {       //TODO: verificar se isso funciona
            Subject * sub = it;
            std::cout << i << sub->getName() << "\n";
            subs_map[i] = sub;
            i++;
        }
        std::cout << "0. Voltar\n";
        std::cout << "\nInforme a opcao desejada: ";
        std::cin  >> sel;

        if(sel != 0 && sel < i) {
            //user->getNotebook()->removeSubject(subs_map[sel]); //TODO: colocar a funcao certa
        }
    }
}
