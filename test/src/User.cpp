/*
 * User.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "User.h"

User::User() {
// TODO Auto-generated constructor stub
}

char User::getActive() const
{
    return active;
}

int User::getId() const
{
    return id;
}

std::string User::getLogin() const
{
    return login;
}

std::string User::getName() const
{
    return name;
}

Notebook *User::getNotebook() const
{
    return notebook;
}

std::string User::getPassword() const
{
    return password;
}

char User::getProfile() const
{
    return profile;
}

void User::setActive(char active)
{
    this->active = active;
}

void User::setId(int id)
{
    this->id = id;
}

void User::setLogin(std::string login)
{
    this->login = login;
}

void User::setName(std::string name)
{
    this->name = name;
}

void User::setNotebook(Notebook *notebook)
{
    this->notebook = notebook;
}

void User::setPassword(std::string password)
{
    this->password = password;
}

void User::setProfile(char profile)
{
    this->profile = profile;
}

User::~User() {
	// TODO Auto-generated destructor stub
}
