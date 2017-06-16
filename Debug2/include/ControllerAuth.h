#ifndef CONTROLLER_AUTH_H
#define CONTROLLER_AUTH_H

#include <string.h>
#include "User.h"

/// AUTHENTICATION

class ControllerAuth {

public:
    User * requestAuth (void);
    User * authenticate (const std::string &, const std::string &);
    ~ControllerAuth(void);
    ControllerAuth(void);
};
#endif
