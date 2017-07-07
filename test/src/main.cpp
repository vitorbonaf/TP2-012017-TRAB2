#include <ControllerAuth.h>
#include <User.h>
#include <DataLoader.h>
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

int main(int argc, const char *argv[]) {
    std::cout << (ControllerAuth::instance()->authenticate("ADMIN", "ADMIN") == NULL) << std::endl;
    return TestRunner::RunAllTests(argc, argv);
}
       

