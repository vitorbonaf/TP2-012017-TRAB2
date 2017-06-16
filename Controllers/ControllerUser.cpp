#include <cstdlib>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "ControllerUser.h"
#include "../Entity/User.h"
#include "../Manager/SubjectManager.h"

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
        cout << "QuizTime - Gerenciamento de Informacoes Pessoais\n\n";
        cout << "1. Alterar nome\n";
        cout << "2. Alterar senha\n";
        cout << "0. Voltar\n";
        cout << "\nInforme a opcao desejada: ";

        cin  >> sel;

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
        cout << "QuizTime - Gerenciamento de Disciplinas\n\n";

        cout << "1. Mostrar disciplinas em curso\n";
        cout << "2. Fazer matricula em disciplina\n";
        cout << "3. Trancar disciplina\n";
        cout << "0. Voltar\n";
        cout << "\nInforme a opcao desejada: ";

        cin  >> sel;

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
    cout << "QuizTime - Alterar Nome\n\n";
    cout << "O seu nome atual é" << name << "\n";
    cout << "Insira um novo nome: ";
    cin  >> new_name;

    user->setName(name);
}

void ControllerUser::changePass(User * user) {
    /// Esta funcao recebe do usuario uma entrada para alteracao de senha e altera a
    /// senha do usuario.
    std::string new_pass;
    system(CLEAR);
    cout << "QuizTime - Alterar Senha\n\n";
    cout << "Senha atual: " << user->getPassword() << "\n";
    cout << "Nova senha: ";
    cin  >> new_pass;
    user->setPassword(new_pass){
}

void ControllerUser::showSubjects(User * user) {
    user->showSubjects();
    getchar();
}

void ControllerUser::includeSubject(User * user) {
    /// Esta funcao permite ao usuario selecionar uma disciplina na qual ele deseje
    /// se matricular e inclui a disciplina no caderno do usuario.
    std::map <int, Subject*> subs_map;
    int sel = -1;
    int i;
    while(sel != 0) {
        auto subs=user->getNotebook()->getSubjects();
        system(CLEAR);
        printf("QuizTime - Matricula em Disciplina\n\n");
        i = 1;
        for(auto it:SubjectManager::instance()->getSubjects()){

            auto iter=std::find_if(subs.begin(),subs.end(),[it](const Subject& comp){return comp.getName()==it.second->getName();});
            if(iter!=subs.end())continue;

            cout << i << it.second->getName() << "\n";
            subs_map[i] = it.second;
            i++;
        }
        cout << "0. Voltar\n";
        cout << "\nInforme a opcao desejada: ";
        cin  >> sel;

        if(sel != 0 && sel < i) {
            user->getNotebook()->addSubject(subs_map[sel]); //TODO: colocar a funcao certa
        }
    }
}

void ControllerUser::removeSubject(User * user) {
    /// Esta funcao solicida ao modulo de logica de negocio a lista das disciplinas
    /// cadastradas, mostra um menu ao usuario para que ele selecione uma disciplina
    /// para trancamento e solicita ao módulo de logica de negocio que realize a
    /// remocao da disciplina selecionada.
    std::vector<Subject*> subjects;
    std::map <int, Subject*> subs_map;
    int sel = -1;
    int i;
    while(sel != 0) {
        char buffer[64];
        system(CLEAR);
        printf("QuizTime - Trancamento de Disciplina\n\n");
        subjects = user->getNotebook()->getSubjects();
        i = 1;
        for(Subject* &sub:subjects) {       //TODO: verificar se isso funciona
            cout << i << sub.getName() << "\n";
            subs_map[i] = sub;
            i++;
        }
        cout << "0. Voltar\n";
        cout << "\nInforme a opcao desejada: ";
        cin  >> sel;

        if(sel != 0 && sel < i) {
            user->getNotebook()->removeSubject(subs_map[sel]); //TODO: colocar a funcao certa
        }
    }
}
