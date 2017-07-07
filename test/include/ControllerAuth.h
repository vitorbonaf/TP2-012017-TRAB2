#ifndef CONTROLLER_AUTH_H
#define CONTROLLER_AUTH_H

#include <string.h>
#include "User.h"

/// AUTHENTICATION

class ControllerAuth {
private:
	ControllerAuth();
	static ControllerAuth *inst;
public:
	static ControllerAuth* instance();
    User * requestAuth (void);
    User * authenticate (const std::string &, const std::string &);
    ~ControllerAuth(void);
};
#endif
