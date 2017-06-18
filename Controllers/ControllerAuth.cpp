#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#include <cstdlib>
#include <iostream>
#include <string>
#include "ControllerAuth.h"
#include "../Entity/User.h"
#include "../Manager/UserManager.h"

/// AUTHENTICATION MODULE
ControllerAuth* ControllerAuth::inst = 0;

ControllerAuth::ControllerAuth () { }
ControllerAuth::~ControllerAuth() { }

ControllerAuth* ControllerAuth::instance(){
	if (ControllerAuth::inst == NULL){
		ControllerAuth::inst = new ControllerAuth();
	}
	return ControllerAuth::inst;
}

User * ControllerAuth::authenticate(const std::string & login, const std::string & pwd) {
    /// Esta funcao recebe como parametros um login e uma senha, solicita ao modulo
    /// de persistencia que retorne do banco de dados um ponteiro para o usuário com
    /// aquele login e verifica se a senha corresponde a senha do usuario recebido.
    /// Retorna um ponteiro para o usuário, caso ele esteja no banco de dados e a
    /// senha corresponda a senha recebida, e um ponteiro nulo, caso contrario.
    User * user = UserManager::instance()->searchUserByUsername(login);
    if (user != NULL) {
        if (!pwd.compare(user->getPassword())) {
            return user;
        } else {
            return NULL;
        }
    }
    else return NULL;
}

User * ControllerAuth::requestAuth() {
    /// Esta funcao recebe do usuario as entradas de login e senha e solicita ao
    /// modulo de lógica de negócio que tente realizar login no sistema com os dados
    /// fornecidos. Retorna um ponteiro para uma instancia da classe User, caso o
    /// login seja bem-sucedido, e um ponteiro nulo, caso contrário.
    std::string login;
    std::string pass;

    system(CLEAR);
    std::cout << "QuizTime - Log-in\n\n";
    std::cout << "Login: ";
    std::cin  >> login;
    std::cout << "Senha: ";
    std::cin  >> pass;

    return authenticate(login,pass);
}
