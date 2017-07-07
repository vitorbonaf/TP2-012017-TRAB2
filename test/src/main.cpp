#include <ControllerAuth.h>
#include <User.h>
#include <UserManager.h>
#include <DataLoader.h>
#include <DataWriter.h>
#include <igloo/igloo_alt.h>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace igloo;

Describe(authentication_test)
{
    void SetUp() {
        DataLoader::instance()->loadData();
    }

    It(invalid_authentication) {
        std::string valid_login = "ADMIN";
        std::string invalid_login = "YMCA";
        std::string invalid_password = "123";
        User * null_user = NULL;

        // Casos invalidos
        Assert::That(ControllerAuth::instance()->authenticate(invalid_login, invalid_password), Is().EqualTo(null_user));
        Assert::That(ControllerAuth::instance()->authenticate(valid_login, invalid_password), Is().EqualTo(null_user));
    }

    It(valid_authentication) {
        std::string valid_login = "ADMIN";
        std::string valid_password = "ADMIN";
        User * null_user = NULL;

        // Caso valido
        Assert::That(ControllerAuth::instance()->authenticate(valid_login, valid_password), Is().Not().EqualTo(null_user));
    }
};

Describe(edit_personal_data_test){

    void SetUp(){
        DataLoader::instance()->loadData();
    }

    It(modify_username){
        std::string username = "anderson";

        User * user = UserManager::instance()->searchUserByUsername(username);

        if (user == NULL)
            user = UserManager::instance()->searchUserByUsername("spider");
        
        std::string new_username;

        user->getLogin() == "anderson" ? new_username = "spider" : new_username = "anderson";

        user->setLogin(new_username);

        DataWriter::instance()->saveUsers();
        DataLoader::instance()->loadUsers();

        User * persisted_user = UserManager::instance()->searchUserById(user->getId());

        Assert::That(user->getLogin(), Is().EqualTo(persisted_user->getLogin()));
        
    }

    It(modify_password){

        User * user = UserManager::instance()->searchUserByUsername("anderson");

        if (user == NULL)
            user = UserManager::instance()->searchUserByUsername("spider");
        
        std::string new_password;

        user->getPassword() == "spider" ? new_password = "aranha" : new_password = "spider";

        user->setPassword(new_password);

        DataWriter::instance()->saveUsers();
        DataLoader::instance()->loadUsers();

        User * persisted_user = UserManager::instance()->searchUserById(user->getId());

        Assert::That(user->getPassword(), Is().EqualTo(persisted_user->getPassword()));
    }


};

int main(int argc, const char *argv[]) {
    return TestRunner::RunAllTests(argc, argv);
}
       

