#ifndef CONTROLLER_USER_H
#define CONTROLLER_USER_H

#include <map>
#include <string.h>
#include "User.h"

/// USER

class ControllerUser {
private:
	ControllerUser();
	static ControllerUser *inst;
	bool subjectInNotebook(User *user, Subject *subject);
public:
	static ControllerUser* instance();
    void manageUserData (User *);
    void manageUserSubjects (User *);
    void changeName(User *);
    void changePass(User *);
    void showSubjects(User *);
    void includeSubject(User *);
    void removeSubject(User *);
    ~ControllerUser(void);
};

#endif
