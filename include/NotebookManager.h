/*
 * NotebookManager.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef NOTEBOOKMANAGER_H_
#define NOTEBOOKMANAGER_H_

#include <vector>

#include "Notebook.h"

class NotebookManager {
private:
	NotebookManager();
	static NotebookManager *inst;
	std::vector<Notebook*> *notebooks;
	static int nextNotebookID;
public:
	virtual ~NotebookManager();
	static NotebookManager* instance();
    std::vector<Notebook*> *getNotebooks() const;
    void setNotebooks(std::vector<Notebook*> *notebooks);
    void addNotebook(Notebook* notebook);
    void addNotebookWithoutId(Notebook* notebook);
    void deleteNotebookById(int id);
    Notebook* searchNotebookById(int id);
};

#endif /* NOTEBOOKMANAGER_H_ */
