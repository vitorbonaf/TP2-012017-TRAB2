#ifndef CONTROLLER_INIT_H
#define CONTROLLER_INIT_H

#include <cstdlib>
#include "ControllerAuth.h"
#include "ControllerUser.h"
#include "ControllerAdmin.h"
#include "ControllerQuiz.h"
#include "User.h"

/// INITIALIZATION

class ControllerInit {
private:
    ControllerAuth  * controllerAuth;
    ControllerUser  * controllerUser;
    ControllerAdmin * controllerAdmin;
    ControllerQuiz  * controllerQuiz;
    User * user = NULL;
public:
    void showUI (void);
    void initialize(void);
    ~ControllerInit(void);
};

#endif
