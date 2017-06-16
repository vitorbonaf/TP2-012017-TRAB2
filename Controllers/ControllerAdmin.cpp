#include <cstdlib>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "ControllerAdmin.h"
#include "../Entity/User.h"

// ADMINISTRATOR MODULE

ControllerAdmin::ControllerAdmin () { }
ControllerAdmin::~ControllerAdmin() { }

void ControllerAdmin::manageStudents() {
    /// Esta funcao exibe um menu para que o usuario selecione a acao desejada. Após
    /// a selecao, é chamada a funcao adequada para realizacao da acao desejada.
    int sel = -1;
    while(sel != 0) {
        system(CLEAR);
        cout << "QuizTime - Gerenciamento de Contas\n\n";

        cout << "1. Cadastrar novo aluno\n";
        cout << "2. Remover aluno\n";
        cout << "0. Voltar\n";
        cout << "\nInforme a opcao desejada: ";
        cin  >> sel;

        switch(sel) {
            case 1: includeStudent(); sel = -1; break;
            case 2: removeStudent();  sel = -1; break;
            default: break;
        }
    }
}

void ControllerAdmin::includeStudent() {
    /// Esta funcao permite ao usuario dar entrada nos dados de cadastro de um novo
    /// aluno e cadastra um usuario com as informacoes recebidas.
    std::string name, login, pass, adm;
    User * user = new User();
    system(CLEAR);
    cout << "QuizTime - Cadastro de Aluno\n\n";
    cout << "Nome do aluno: ";
    cin  >> name;
    cout <<"Login: ";
    cin  >> login;
    cout <<"Senha: ";
    cin  >> pass;
    cout << "Deseja atribuir ao aluno status de admin? (s/n)";
    while(adm != "s" && adm != "n") cin >> adm;
    user->setName(name);
    user->setLogin(login);
    user->setPassword(pass);
    if(adm == "s") user->setProfile('A');
    else user->setProfile('U'); 
    UserManager::instance()->addUserWithoutId(user);
    cout << "\nAluno cadastrado com sucesso.\n";
    getchar();
}

void ControllerAdmin::removeStudent() {
    /// Esta funcao solicita ao modulo de logica de negocio o banco de dados de
    /// usuarios, exibe um menu para que o administrador possa selecionar um usuario
    /// para ser removido e remove o usuario selecionado.
    std::map <int, User*> user_map;
    int sel = -1;
    int i;
    while(sel != 0) {
        system(CLEAR);
        cout << "QuizTime - Remover Usuario\n\n";
        i = 1;
        for(auto it:UserManager::instance()->getUsers()){
            User *user=it;
            if(user->getProfile() == 'U') {
                cout << i << user->getName() << "\n";
                user_map[i] = user;
                i++;
            }
        }
        cout << "0. Voltar\n";
        cout << "\nInforme o numero do usuario a ser removido: ";
        cin  >> sel;

        if(sel != 0 && sel < i) {
            UserManager::instance()->deleteUserById(user_map[sel]->getId());
        }
    }
}

void ControllerAdmin::manageSubjects() {
    /// Esta funcao exibe um menu para que o usuario possa solicitar uma acao
    /// relacionada ao gerenciamento de disciplinas e chama a funcao adequada para
    /// realizacao da acao solicitada.
    int sel = -1;
    while(sel != 0) {
        system(CLEAR);
        cout << "QuizTime - Gerenciamento de Disciplinas\n\n";
        cout << "1. Criar nova disciplina\n";
        cout << "2. Adicionar novo topico a disciplina\n";
        cout << "3. Criar novo quiz\n";
        cout << "4. Remover disciplina\n";
        cout << "5. Remover topico de disciplina\n";
        cout << "6. Remover quiz\n";
        cout << "0. Voltar\n";
        cout << "\nInforme a opcao desejada: ";
        cin  >> sel;

        switch(sel) {
            case 1: includeSubject(); sel = -1; break;
            case 2: includeTopic();   sel = -1; break;
            case 3: includeQuiz();    sel = -1; break;
            case 4: removeSubject();  sel = -1; break;
            case 5: removeTopic();    sel = -1; break;
            case 6: removeQuiz();     sel = -1; break;
            default: break;
        }
    }
}

void ControllerAdmin::includeSubject() {
    /// Esta funcao permite ao administrador dar entrada no nome de uma nova
    /// disciplina para cadastro e cadastra uma nova disciplina com o nome
    /// fornecido.
    std::string name;
    Subject * sub = new Subject();
    system(CLEAR);
    cout << "QuizTime - Cadastro de Disciplina\n\n";
    cout << "Nome da disciplina: ";
    getline(cin, name);
    sub->setName(name);
    SubjectManager::instance()->addSubject(sub)
    cout << "\nDisciplina cadastrada com sucesso.\n";
    getchar();
}

void ControllerAdmin::includeTopic() {
    /// Esta funcao recupera do banco de dados o banco de disciplinas, exibe um menu
    /// para que o usuario selecione uma disciplina na qual deseja incluir um novo
    /// topico e recebe o nome para um novo topico. Em seguida, cadastra o novo
    /// topico.
    std::map <int, Subject*> subs_map;
    std::string name;
    Topic * top = new Topic();
    int sel = -1;
    int i;
    while(sel != 0) {
        system(CLEAR);
        cout << "QuizTime - Inserir Topico\n\n";
        i = 1;
        for(auto it:SubjectManager::instance()->getSubjects()){
            Subject *sub=it;
            cout << i << sub->getName() << "\n";
            subs_map[i] = sub;
            i++;
        }
        cout << "0. Voltar\n";
        cout << "\nSelecione uma disciplina para inserir o topico: ";
        cin  >> sel;

       if(sel != 0 && sel < i) {
            cout << "Nome do novo topico: ";
            getline(cin, name);
          
            top->setName(name);  
            TopicManager::instance()->addTopic(top);
            printf("\nTopico cadastrado com sucesso.\n");
            getchar();
        }
        else {
            if(sel != 0) {
                cout << "Selecao de disciplina invalida.\n";
                getchar();
            }
        }
    }
}

void ControllerUIAdmin::includeQuiz() {
    /// Esta funcao recupera do banco de dados o banco de disciplinas, exibe um menu
    /// para que o usuario selecione uma disciplina e um topico, no qual deseja
    /// incluir um novo quiz e recebe o nome e as perguntas para o novo quiz. Em
    /// seguida, cadastra o novo quiz.
    std::map <int, Subject*> subs_map;
    std::map <int, Topic*> tops_map;
    std::vector<Question*> questions;
    std::string name, quest;
    char ans;
    int sel1 = -1, sel2 = -1;
    int i;

    while(sel1 != 0) {
        system(CLEAR);
        printf("QuizTime - Criar Novo Quiz\n\n");
        i = 1;
        for(auto it:SubjectManager::instance()->getSubjects()){
            Subject *sub=it;
            cout << i << sub->getName() << "\n";
            subs_map[i] = it;
            i++;
        } 
        cout << "0. Voltar\n";
        cout << "\nSelecione uma disciplina para inserir o quiz: ";
        cin  >> sel1;

        if(sel1 != 0 && sel1 < i) {
            while(sel2 != 0) {
                system(CLEAR);
                cout << "QuizTime - Criar Novo Quiz\n\n";
                i = 1;
                for(auto it:subs_map[sel1]->getTopics()){
                    Topic * top = it;
                    cout << i << top->getName() << "\n";
                    tops_map[i] = top;
                    i++;
                }
                cout << "0. Voltar\n";
                cout << "\nSelecione um topico para inserir o quiz: ";
                cin  >> sel2;

                if(sel2 != 0 && sel2 < i) {
                    cout << "Nome do novo quiz: ";
                    getline(cin, name);

                    for(int k=0; k<10; k++) {
                        ans = 'O';
                        cout << "Pergunta numero %d: ", k+1;
                        getline(cin, quest);
                        while(ans != 'V' && ans != 'F') {
                            cout << "Resposta (V/F): ";
                            cin  >> ans;
                        }
                        questions.push_back(new Question(quest, ans));
                    }
                    if(!controllerBL->includeQuiz(name, questions, tops_map[sel2])){
                         cout << "\nErro: topico já cadastrado.\n";
                        getchar();
                    } else {
                        cout << "\nTopico cadastrado com sucesso.\n";
                        getchar();
                    }
                } else {
                    if(sel2 != 0) {
                        cout << "Selecao de topico invalida.\n";
                        getchar();
                    }
                }
            }
        } else {
            if(sel1 != 0) {
                cout << "Selecao de disciplina invalida.\n";
                getchar();
            }
        }
    }
}
