#ifndef CONTROLLER_INIT_H
#define CONTROLLER_INIT_H

#include <cstdlib>
#include "ControllerAuth.h"
#include "ControllerUser.h"
#include "ControllerAdmin.h"
#include "ControllerQuiz.h"
#include "../Entity/User.h"

/// INITIALIZATION

class ControllerInit {
private:
    User * user = NULL;
    static ControllerInit *inst;
    ControllerInit();
public:
    void initializeSystem();
    static ControllerInit* instance();
    ~ControllerInit(void);
    User* getLoggedUser();
    void showUI();
};

#endif
