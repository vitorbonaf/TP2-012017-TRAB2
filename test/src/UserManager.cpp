/*
 * UserManager.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "UserManager.h"
#include "NotebookManager.h"

UserManager* UserManager::inst = 0;
int UserManager::nextUserID = 1;

UserManager::UserManager() {
	this->users = new std::vector<User*>();
}

std::vector<User*> *UserManager::getUsers() const
{
    return users;
}

UserManager *UserManager::instance()
{
	if (UserManager::inst == NULL){
		UserManager::inst = new UserManager();
	}
	return UserManager::inst;
}

void UserManager::setUsers(std::vector<User*> *users)
{
    this->users = users;
}

UserManager::~UserManager()
{
	// TODO Auto-generated destructor stub
}

void UserManager::deleteUserById(int id)
{
	for(unsigned int i = 0; i < users->size(); i++){
		if(users->at(i)->getId() == id){
			users->at(i)->setActive('N');
			NotebookManager::instance()->deleteNotebookById(users->at(i)->getNotebook()->getId());
			break;
		}
	}
}

void UserManager::addUserWithoutId(User *user)
{
	user->setId(UserManager::nextUserID);
	users->push_back(user);
	UserManager::nextUserID++;
}

void UserManager::addUser(User *user)
{
	users->push_back(user);
	UserManager::nextUserID++;
}

User *UserManager::searchUserById(int id)
{
	for(unsigned int i = 0; i < users->size(); i++){
		if(users->at(i)->getId() == id){
			return users->at(i);
		}
	}
	return NULL;
}

User* UserManager::searchUserByUsername(std::string username){

	for(unsigned int i = 0; i < users->size(); i++){
		if(users->at(i)->getLogin() == username){
			return users->at(i);
		}
	}
	return NULL;
}
