/*
 * User.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>

#include "Notebook.h"

class User {
private:
	int id;
	char active;
	std::string name;
	std::string login;
	std::string password;
	char profile;
	Notebook *notebook;

public:
	User();
	virtual ~User();
    char getActive() const;
    int getId() const;
    std::string getLogin() const;
    std::string getName() const;
    Notebook *getNotebook() const;
    std::string getPassword() const;
    char getProfile() const;
    void setActive(char active);
    void setId(int id);
    void setLogin(std::string login);
    void setName(std::string name);
    void setNotebook(Notebook *notebook);
    void setPassword(std::string password);
    void setProfile(char profile);
};

#endif /* USER_H_ */
