#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include "ControllerAdmin.h"
#include "ControllerInit.h"

#include "User.h"
#include "Subject.h"
#include "Notebook.h"
#include "Topic.h"
#include "Quiz.h"
#include "Question.h"

#include "UserManager.h"
#include "NotebookManager.h"
#include "SubjectManager.h"
#include "TopicManager.h"
#include "QuizManager.h"
#include "QuestionManager.h"

/// ADMINISTRATOR MODULE
ControllerAdmin* ControllerAdmin::inst = 0;
ControllerAdmin::ControllerAdmin () { }
ControllerAdmin::~ControllerAdmin() { }

ControllerAdmin* ControllerAdmin::instance(){
	if (ControllerAdmin::inst == NULL){
		ControllerAdmin::inst = new ControllerAdmin();
	}
	return ControllerAdmin::inst;
}

void ControllerAdmin::manageStudents() {
    /// Esta funcao exibe um menu para que o usuario selecione a acao desejada.
    /// Apos a selecao, chama a funcao adequada para realizacao da acao desejada.
    int sel = -1;

	system(CLEAR);
	std::cout << "QuizTime - Gerenciamento de Contas\n\n";

	std::cout << "1. Cadastrar novo aluno\n";
	std::cout << "2. Remover aluno\n";
	std::cout << "0. Voltar\n";
	std::cout << "\nInforme a opcao desejada: ";
	std::cin  >> sel;

	switch(sel) {
		case 1: includeStudent(); 	manageStudents(); break;
		case 2: removeStudent(); 	manageStudents(); break;
		case 0: ControllerInit::instance()->showUI(); break;
		default: manageStudents(); break;
	}
}

void ControllerAdmin::includeStudent() {
    /// Esta funcao permite ao usuario dar entrada nos dados de cadastro de um novo
    /// aluno e cadastra um usuario com as informacoes recebidas.
    std::string name, login, pass, adm = "", aux;
    User *user = new User();
    Notebook *notebook = new Notebook();
    system(CLEAR);
    std::cout << "QuizTime - Cadastro de Aluno\n\n";
    std::cout << "Nome do aluno: ";
    getline(std::cin, aux);
    getline(std::cin, name);
    std::cout <<"Login: ";
    std::cin  >> login;
    getline(std::cin, aux);
    std::cout <<"Senha: ";
    std::cin  >> pass;
    getline(std::cin, aux);
    std::cout << "Deseja atribuir ao aluno status de admin? (s/n)";
    std::cin >> adm;
    getline(std::cin, aux);
    while(adm != "s" && adm != "n" && adm != "S" && adm != "N"){
    	std::cout << "Resposta inadequada. Deseja atribuir ao aluno status de admin? (s/n)";
    	std::cin >> adm;
    }
    //TODO: checar se já existe usuario com esse login
    user->setName(name);
    user->setLogin(login);
    user->setPassword(pass);
    if(adm == "s" || adm == "S") user->setProfile('A');
    else user->setProfile('U');
    user->setActive('S');
    notebook->setActive('S');
    user->setNotebook(notebook);
    UserManager::instance()->addUserWithoutId(user);
    NotebookManager::instance()->addNotebookWithoutId(notebook);
    std::cout << "\nAluno cadastrado com sucesso.\n";
    getchar();

}

void ControllerAdmin::removeStudent() {
    /// Esta funcao solicita ao modulo de logica de negocio o banco de dados de
    /// usuarios, exibe um menu para que o administrador possa selecionar um usuario
    /// para ser removido e remove o usuario selecionado.
    std::map <int, User*> user_map;
    int sel = -1;
    int i = 1;
    std::vector<User*> *users = UserManager::instance()->getUsers();

	system(CLEAR);
	std::cout << "QuizTime - Remover Usuario\n\n";

	for(unsigned int j = 0; j < users->size() ; j++){
		if((users->at(j)->getProfile() == 'U') && (users->at(j)->getActive() == 'S')) {
			std::cout << i << ". " << users->at(j)->getName() << std::endl;
			user_map[i] = users->at(j);
			i++;
		}
	}

	std::cout << "0. Voltar\n";
	std::cout << "\nInforme o numero do usuario a ser removido: ";
	std::cin  >> sel;

	while(sel < 0 || sel >= i){
		std::cout << "\n Usuário inválido. Informe novamento o número do usuário a ser removido: ";
		std::cin >> sel;
	}

	if(sel != 0) {
		UserManager::instance()->deleteUserById(user_map[sel]->getId());
		std::cout << "\nAluno removido com sucesso.\n";
		getchar();
	}

}

void ControllerAdmin::manageSubjects() {
    /// Esta funcao exibe um menu para que o usuario possa solicitar uma acao
    /// relacionada ao gerenciamento de disciplinas e chama a funcao adequada para
    /// realizacao da acao solicitada.
    int sel = -1;

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
		case 1: includeSubject(); manageSubjects(); break;
		case 2: includeTopic();   manageSubjects(); break;
		case 3: includeQuiz();    manageSubjects(); break;
		case 4: removeSubject();  manageSubjects(); break;
		case 5: removeTopic();    manageSubjects(); break;
		case 6: removeQuiz();     manageSubjects(); break;
		case 0: ControllerInit::instance()->showUI(); break;
		default: manageSubjects(); break;
	}

}

void ControllerAdmin::includeSubject() {
    /// Esta funcao permite ao administrador dar entrada no nome de uma nova
    /// disciplina para cadastro e cadastra uma nova disciplina com o nome
    /// fornecido.
    std::string name;
    Subject * sub = new Subject();
    bool nameAvailable = true;
    system(CLEAR);
    std::cout << "QuizTime - Cadastro de Disciplina\n\n";
    //TODO: Checar se já existe disciplina com esse nome

    do{
    	std::cout << "Nome da disciplina: ";
    	getline(std::cin, name);
        getline(std::cin, name);
//		std::vector<Subject*> *subjects = SubjectManager::instance()->getSubjects();
//		for(unsigned int i; i < subjects->size(); i++){
//			if (!subjects->at(i)->getName().compare(name) && subjects->at(i)->getActive() == 'S'){
//				nameAvailable = false;
//				break;
//			}
//		}

		if(!nameAvailable){
			std::cout << "\nNome indisponível, disciplina já existente. Escolha outro nome.\n\n";
		}
    }while(!nameAvailable);

    sub->setName(name);
	sub->setActive('S');
	SubjectManager::instance()->addSubjectWithoutId(sub);
//	ControllerInit::instance()->getLoggedUser()->getNotebook()->getSubjects()->push_back(sub);
	std::cout << "\nDisciplina cadastrada com sucesso.\n";
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
        std::cout << "QuizTime - Inserir Topico\n\n";
        i = 1;
        for(unsigned int j = 0; j < SubjectManager::instance()->getSubjects()->size(); j++){
            Subject *sub= SubjectManager::instance()->getSubjects()->at(j);
            if(sub->getActive() == 'S'){
            	std::cout << i << ". "<< sub->getName() << "\n";
				subs_map[i] = sub;
				i++;
            }
        }
        std::cout << "0. Voltar\n";
        std::cout << "\nSelecione uma disciplina para inserir o topico: ";
        std::cin  >> sel;

        if(sel != 0 && sel < i) {
            std::cout << "Nome do novo topico: ";
            getline(std::cin, name);
            getline(std::cin, name); 
            
            //TODO: checar se ja existe topico com esse nome!
            top->setName(name);
            top->setActive('S');
            TopicManager::instance()->addTopicWithoutId(top);
            subs_map[sel]->getTopics()->push_back(top);
            std::cout << "\nTopico cadastrado com sucesso.\n";
            getchar();
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
    std::vector<Question*> *questions = new std::vector<Question*>();
    std::string name, quest, aux;
    std::vector<std::string> *answers;
    char ans;
    int sel1 = -1, sel2 = -1;
    int i, choice;

    while(sel1 != 0) {
        system(CLEAR);
        printf("QuizTime - Criar Novo Quiz\n\n");
        i = 1;
        std::vector<Subject*> *subjects = SubjectManager::instance()->getSubjects();
        for(unsigned int j = 0; j < subjects->size(); j++){
            Subject *sub = subjects->at(j);
            if(sub->getActive() == 'S'){
            	std::cout << i << ". "<< sub->getName() << "\n";
				subs_map[i] = sub;
				i++;
            }

        } 
        std::cout << "0. Voltar\n";
        std::cout << "\nSelecione uma disciplina para inserir o quiz: ";
        std::cin  >> sel1;

        if(sel1 != 0 && sel1 < i) {
            while(sel2 != 0) {
                system(CLEAR);
                std::cout << "QuizTime - Criar Novo Quiz\n\n";
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
                std::cout << "\nSelecione um topico para inserir o quiz: ";
                std::cin  >> sel2;

                if(sel2 != 0 && sel2 < i) {
                    std::cout << "Nome do novo quiz: ";
                    getline(std::cin, name);
                    getline(std::cin, name);

                    //TODO: checar se já existe quiz com esse nome!

                    for(int k=0; k<10; k++) {
                        ans = 'O';
                        std::cout << "Pergunta numero"<< k+1 <<": ";
                        getline(std::cin, quest);
                        std::cout << "A pergunta é de V ou F (1) ou Múltipla Escolha (2): ";
                        std::cin >> choice;
                        getline(std::cin, aux);
                        while(choice != 1 && choice != 2){
                        	std::cout << "Opção não existente, tente novamente. A pergunta é de V ou F (1) ou Múltipla Escolha (2): ";
                        	std::cin >> choice;
                        	getline(std::cin, aux);
                        }
                        Question * question = new Question();
                        question->setActive('S');
                        question->setText(quest);
                        question->setType(choice);
                        answers = new std::vector<std::string>();
                        if(choice == 1){
                        	 while(ans != 'V' && ans != 'F') {
								std::cout << "Resposta (V/F): ";
								std::cin  >> ans;
								getline(std::cin, aux);
                        	 }
							 if(ans == 'F'){
								 question->setCorrect_answer_index(1);
							 }else{
								 question->setCorrect_answer_index(0);
							 }
                        	 answers->push_back("Verdadeiro");
                        	 answers->push_back("Falso");

                        }else{
                        	for(int l = 0; l < 4; l++){
                        		std::cout << "Resposta " << l+1 << ": ";
                        		getline(std::cin, aux);
                        		answers->push_back(aux);
                        	}
                        	choice = -1;
                        	while(choice < 1 || choice > 4){
                        		std::cout << "Digite qual a resposta correta (1-4): ";
                        		std::cin >> choice;
                        		getline(std::cin, aux);
                        	}
                        	question->setCorrect_answer_index(choice-1);
                        }
                        question->setAnswers(answers);

                        // solicitar value
                        while(ans != 'S' && ans != 'N'){
                        	std::cout << "Você gostaria de atribuir um valor à questão (S/N)? ";
                        	std::cin >> ans;
                        	getline(std::cin, aux);
                        }

                        choice = -1;
                        if (ans == 'S'){
                        	while(choice < 1 || choice > 10){
                        		std::cout << "Dê um valor de 1-10 a questão: ";
								std::cin >> choice;
								getline(std::cin, aux);
                        	}
                        	question->setValue(choice);
                        }else{
                        	question->setValue(1);
                        }


                        questions->push_back(question);
                        QuestionManager::instance()->addQuestionWithoutId(question);
                        getline(std::cin, quest);
                    }
                        Quiz * quiz = new Quiz();
                        quiz->setName(name);
                        quiz->setQuestions(questions);
                        quiz->setActive('S');
                        QuizManager::instance()->addQuizWithoutId(quiz);
                        tops_map[sel2]->getQuizzes()->push_back(quiz);
                        std::cout << "\nQuiz cadastrado com sucesso.\n";
                        getchar();
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

void ControllerAdmin::removeSubject() {

	std::map <int, Subject*> subs_map;
	std::string name, quest;
	int sel1 = -1;
	int i;

	while(sel1 != 0) {
		system(CLEAR);
		printf("QuizTime - Excluir Disciplina\n\n");
		i = 1;
		std::vector<Subject*> *subjects = SubjectManager::instance()->getSubjects();
		for(unsigned int j = 0; j < subjects->size(); j++){
			Subject *sub = subjects->at(j);
			if(sub->getActive() == 'S'){
				std::cout << i << ". "<< sub->getName() << "\n";
				subs_map[i] = sub;
				i++;
			}

		}
		std::cout << "0. Voltar\n";
		std::cout << "\nSelecione uma disciplina para excluir: ";
		std::cin  >> sel1;

		if(sel1 != 0 && sel1 < i) {

			SubjectManager::instance()->deleteSubjectById(subs_map[sel1]->getId());
			std::vector<Notebook*> *notebooks = NotebookManager::instance()->getNotebooks();
			for(unsigned int j = 0; j < notebooks->size(); j++){
				std::vector<Subject*> *subjects = notebooks->at(j)->getSubjects();
				for(unsigned int k = 0; k < subjects->size(); k++){
					if (subjects->at(k)->getId() == subs_map[sel1]->getId()){
						subjects->erase(subjects->begin()+k);
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


void ControllerAdmin::removeTopic() {

	std::map <int, Subject*> subs_map;
	std::map <int, Topic*> tops_map;
	std::string name, quest;
	int sel1 = -1, sel2 = -1;
	int i;

	while(sel1 != 0) {
		system(CLEAR);
		printf("QuizTime - Excluir Tópico\n\n");
		i = 1;
		std::vector<Subject*> *subjects = SubjectManager::instance()->getSubjects();
		for(unsigned int j = 0; j < subjects->size(); j++){
			Subject *sub = subjects->at(j);
			if(sub->getActive() == 'S'){
				std::cout << i << ". "<< sub->getName() << "\n";
				subs_map[i] = sub;
				i++;
			}

		}
		std::cout << "0. Voltar\n";
		std::cout << "\nSelecione uma disciplina para excluir o tópico: ";
		std::cin  >> sel1;

		if(sel1 != 0 && sel1 < i) {
			while(sel2 != 0) {
				system(CLEAR);
				std::cout << "QuizTime - Excluir Tópico\n\n";
				i = 1;
				for(unsigned int k = 0; k < subs_map[sel1]->getTopics()->size(); k++){
					Topic * top = subs_map[sel1]->getTopics()->at(k);
					std::cout << i <<". "<< top->getName() << "\n";
					tops_map[i] = top;
					i++;

				}
				std::cout << "0. Voltar\n";
				std::cout << "\nSelecione um topico para excluir: ";
				std::cin  >> sel2;

				if(sel2 != 0 && sel2 < i) {
					std::vector<Topic*> *topics = TopicManager::instance()->getTopics();
					for(unsigned int m = 0; m < topics->size(); m++){
						if(topics->at(m)->getId() == tops_map[sel2]->getId()){
							TopicManager::instance()->deleteTopicById(tops_map[sel2]->getId());
							subs_map[sel1]->getTopics()->erase(subs_map[sel1]->getTopics()->begin()+sel2-1);
						}
					}
				} else {
					if(sel2 != 0) {
						std::cout << "Selecao de tópico invalida.\n";
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

void ControllerAdmin::removeQuiz() {

	std::map <int, Subject*> subs_map;
	std::map <int, Topic*> tops_map;
	std::map <int, Quiz*> quiz_map;
	std::string name, quest;
	int sel1 = -1, sel2 = -1, sel3 = -1;
	int i;

	while(sel1 != 0) {
		system(CLEAR);
		printf("QuizTime - Excluir Quiz\n\n");
		i = 1;
		std::vector<Subject*> *subjects = SubjectManager::instance()->getSubjects();
		for(unsigned int j = 0; j < subjects->size(); j++){
			Subject *sub = subjects->at(j);
			if(sub->getActive() == 'S'){
				std::cout << i << ". "<< sub->getName() << "\n";
				subs_map[i] = sub;
				i++;
			}

		}
		std::cout << "0. Voltar\n";
		std::cout << "\nSelecione uma disciplina para excluir o quiz: ";
		std::cin  >> sel1;

		if(sel1 != 0 && sel1 < i) {
			while(sel2 != 0) {
				system(CLEAR);
				std::cout << "QuizTime - Excluir Quiz\n\n";
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
				std::cout << "\nSelecione um topico para excluir o quiz: ";
				std::cin  >> sel2;

				if(sel2 != 0 && sel2 < i) {
					while(sel3 != 0){
						system(CLEAR);
						std::cout << "QuizTime - Excluir Quiz\n\n";
						i = 1;
						for(unsigned int l = 0; l < tops_map[sel2]->getQuizzes()->size(); l++){
							Quiz * quiz = tops_map[sel2]->getQuizzes()->at(l);
							std::cout << i <<". "<< quiz->getName() << "\n";
							quiz_map[i] = quiz;
							i++;

						}
						std::cout << "0. Voltar\n";
						std::cout << "\nSelecione um quiz para excluir: ";
						std::cin  >> sel3;
						if(sel3 != 0 && sel3 < i){
							std::vector<Quiz*> *quizzes = QuizManager::instance()->getQuizzes();
							for(unsigned int m = 0; m < quizzes->size(); m++){
								if(quizzes->at(m)->getId() == quiz_map[sel3]->getId()){
									QuizManager::instance()->deleteQuizById(quiz_map[sel3]->getId());
									tops_map[sel2]->getQuizzes()->erase(tops_map[sel2]->getQuizzes()->begin()+sel3-1);
								}
							}
						}else{
							std::cout << "Selecao de quiz invalida.\n";
							getchar();
						}
					}
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

