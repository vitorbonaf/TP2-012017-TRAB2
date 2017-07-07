/*
 * NotebookManager.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "NotebookManager.h"
#include "SubjectManager.h"

NotebookManager* NotebookManager::inst = 0;
int NotebookManager::nextNotebookID = 1;

NotebookManager::NotebookManager() {
	this->notebooks = new std::vector<Notebook*>();
}

std::vector<Notebook*> *NotebookManager::getNotebooks() const
{
    return notebooks;
}

NotebookManager *NotebookManager::instance()
{
	if (NotebookManager::inst == NULL){
		NotebookManager::inst = new NotebookManager();
	}
	return NotebookManager::inst;
}

void NotebookManager::setNotebooks(std::vector<Notebook*> *notebooks)
{
    this->notebooks = notebooks;
}

NotebookManager::~NotebookManager() {
	// TODO Auto-generated destructor stub
}



void NotebookManager::addNotebookWithoutId(Notebook *notebook)
{
	notebook->setId(NotebookManager::nextNotebookID);
	notebooks->push_back(notebook);
	NotebookManager::nextNotebookID++;
}



Notebook *NotebookManager::searchNotebookById(int id)
{
	for(unsigned int i = 0; i < notebooks->size(); i++){
		if(notebooks->at(i)->getId() == id){
			return notebooks->at(i);
		}
	}
	return NULL;
}



void NotebookManager::addNotebook(Notebook *notebook)
{
	notebooks->push_back(notebook);
	NotebookManager::nextNotebookID++;
}



void NotebookManager::deleteNotebookById(int id)
{
	for(unsigned int i = 0; notebooks->size(); i++){
		if(notebooks->at(i)->getId() == id){
			notebooks->at(i)->setActive('N');
			break;
		}
	}
}


