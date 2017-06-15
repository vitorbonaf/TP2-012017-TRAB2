/*
 * UserManager.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef USERMANAGER_H_
#define USERMANAGER_H_

#include <vector>

#include "../Entity/User.h"

class UserManager {
private:
	UserManager();
	static UserManager *inst;
	std::vector<User*> *users;
	static int nextUserID;
public:
	virtual ~UserManager();
	static UserManager* instance();
    std::vector<User*> *getUsers() const;
    void setUsers(std::vector<User*> *users);
    void addUser(User* user);
    void addUserWithoutId(User* user);
    void deleteUserById(int id);
    User* searchUserById(int id);
    User* searchUserByUsername(std::string username);
};

#endif /* USERMANAGER_H_ */
