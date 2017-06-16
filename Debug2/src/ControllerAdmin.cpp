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
#include <algorithm>
#include "ControllerAdmin.h"
#include "User.h"
#include "Subject.h"
#include "Notebook.h"
#include "Topic.h"
#include "Quiz.h"
#include "Question.h"
#include "UserManager.h"
#include "SubjectManager.h"
#include "TopicManager.h"
#include "QuizManager.h"

// ADMINISTRATOR MODULE

ControllerAdmin::ControllerAdmin () { }
ControllerAdmin::~ControllerAdmin() { }

void ControllerAdmin::manageStudents() {
    /// Esta funcao exibe um menu para que o usuario selecione a acao desejada. Após
    /// a selecao, é chamada a funcao adequada para realizacao da acao desejada.
    int sel = -1;
    while(sel != 0) {
        system(CLEAR);
        std::cout << "QuizTime - Gerenciamento de Contas\n\n";

        std::cout << "1. Cadastrar novo aluno\n";
        std::cout << "2. Remover aluno\n";
        std::cout << "0. Voltar\n";
        std::cout << "\nInforme a opcao desejada: ";
        std::cin  >> sel;

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
    std::cout << "QuizTime - Cadastro de Aluno\n\n";
    std::cout << "Nome do aluno: ";
    std::cin  >> name;
    std::cout <<"Login: ";
    std::cin  >> login;
    std::cout <<"Senha: ";
    std::cin  >> pass;
    std::cout << "Deseja atribuir ao aluno status de admin? (s/n)";
    while(adm != "s" && adm != "n") std::cin >> adm;
    user->setName(name);
    user->setLogin(login);
    user->setPassword(pass);
    if(adm == "s") user->setProfile('A');
    else user->setProfile('U'); 
    UserManager::instance()->addUserWithoutId(user);
    std::cout << "\nAluno cadastrado com sucesso.\n";
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
        std::cout << "QuizTime - Remover Usuario\n\n";
        i = 1;
        for(auto it:*(UserManager::instance()->getUsers())){
            User *user=it;
            if(user->getProfile() == 'U') {
                std::cout << i << user->getName() << "\n";
                user_map[i] = user;
                i++;
            }
        }
        std::cout << "0. Voltar\n";
        std::cout << "\nInforme o numero do usuario a ser removido: ";
        std::cin  >> sel;

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
        std::cout << "QuizTime - Gerenciamento de Disciplinas\n\n";
        std::cout << "1. Criar nova disciplina\n";
        std::cout << "2. Adicionar novo topico a disciplina\n";
        std::cout << "3. Criar novo quiz\n";
        std::cout << "4. Remover disciplina\n";
        std::cout << "5. Remover topico de disciplina\n";
        std::cout << "6. Remover quiz\n";
        std::cout << "0. Voltar\n";
        std::cout << "\nInforme a opcao desejada: ";
        std::cin  >> sel;

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
    std::cout << "QuizTime - Cadastro de Disciplina\n\n";
    std::cout << "Nome da disciplina: ";
    getline(std::cin, name);
    //std::vector<Subject*> * subs = SubjectManager::instance()->getSubjects();
    //auto iter=std::find_if(subs->begin(),subs->end(),[it](Subject* comp){return comp.getName()==it->getName();});
    //if(iter!=subs->end()) {
        //std::cout << "Erro: disciplina ja cadastrada.\n";
        //getchar();
    //} else {
        sub->setName(name);
        SubjectManager::instance()->addSubject(sub);
        std::cout << "\nDisciplina cadastrada com sucesso.\n";
        getchar();
    //}
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
        std::cout << "QuizTime - Inserir Topico\n\n";
        i = 1;
        for(auto it:*(SubjectManager::instance()->getSubjects())){
            Subject *sub=it;
            std::cout << i << sub->getName() << "\n";
            subs_map[i] = sub;
            i++;
        }
        std::cout << "0. Voltar\n";
        std::cout << "\nSelecione uma disciplina para inserir o topico: ";
        std::cin  >> sel;

        if(sel != 0 && sel < i) {
            std::cout << "Nome do novo topico: ";
            getline(std::cin, name);

            //std::vector<Topic*> * topics = TopicManager::instance()->getTopics(); 
            //auto iter=std::find_if(topics->begin(),topics->end(),[it](Topic * comp){return comp.getName()==it->getName();});
            //if(iter!=topics->end()) {
                //std::cout << "Erro: topico ja cadastrado.\n";
                //getchar();
            //} else {
                top->setName(name);  
                TopicManager::instance()->addTopic(top);
                std::cout << "\nTopico cadastrado com sucesso.\n";
                getchar();
            //}
        }
        else {
            if(sel != 0) {
                std::cout << "Selecao de disciplina invalida.\n";
                getchar();
            }
        }
    }
}

void ControllerAdmin::includeQuiz() {
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
        for(auto it:*(SubjectManager::instance()->getSubjects())){
            Subject *sub=it;
            std::cout << i << sub->getName() << "\n";
            subs_map[i] = it;
            i++;
        } 
        std::cout << "0. Voltar\n";
        std::cout << "\nSelecione uma disciplina para inserir o quiz: ";
        std::cin  >> sel1;

        if(sel1 != 0 && sel1 < i) {
            while(sel2 != 0) {
                system(CLEAR);
                std::cout << "QuizTime - Criar Novo Quiz\n\n";
                i = 1;
                for(auto it:*(subs_map[sel1]->getTopics())){
                    Topic * top = it;
                    std::cout << i << top->getName() << "\n";
                    tops_map[i] = top;
                    i++;
                }
                std::cout << "0. Voltar\n";
                std::cout << "\nSelecione um topico para inserir o quiz: ";
                std::cin  >> sel2;

                if(sel2 != 0 && sel2 < i) {
                    std::cout << "Nome do novo quiz: ";
                    getline(std::cin, name);

                    for(int k=0; k<10; k++) {
                        ans = 'O';
                        std::cout << "Pergunta numero"<< k+1 <<": ";
                        getline(std::cin, quest);
                        while(ans != 'V' && ans != 'F') {
                            std::cout << "Resposta (V/F): ";
                            std::cin  >> ans;
                        }
                        Question * question = new Question();
                        question->setText(quest); // TODO: set answer
                        questions.push_back(question);
                    }
                    //std::vector<Quiz*> * quizzes = QuizManager::instance()->getQuizzes();
                    //auto iter=std::find_if(quizzes->begin(),quizzes->end(),[it](Quiz * comp){return comp.getName()==it->getName();});
                    //if(iter!=quizzes->end()) {
                        //std::cout << "\nErro: quiz já cadastrado.\n";
                        //getchar();
                    //} else {
                        Quiz * quiz = new Quiz();
                        quiz->setName(name);
                        quiz->setQuestions(&questions);
                        QuizManager::instance()->addQuiz(quiz);
                        std::cout << "\nQuiz cadastrado com sucesso.\n";
                        getchar();
                    //}
                } else {
                    if(sel2 != 0) {
                        std::cout << "Selecao de topico invalida.\n";
                        getchar();
                    }
                }
            }
        } else {
            if(sel1 != 0) {
                std::cout << "Selecao de disciplina invalida.\n";
                getchar();
            }
        }
    }
}

void ControllerAdmin::removeSubject() {}
void ControllerAdmin::removeTopic() {}
void ControllerAdmin::removeQuiz() {}

