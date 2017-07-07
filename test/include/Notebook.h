/*
 * Notebook.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

#include "Subject.h"

class Notebook {
private:
	int id;
	char active;
	std::vector<Subject*> *subjects;
public:
	Notebook();
	virtual ~Notebook();
    char getActive() const;
    int getId() const;
    std::vector<Subject*> *getSubjects() const;
    void setActive(char active);
    void setId(int id);
    void setSubjects(std::vector<Subject*> *subjects);
};

#endif /* NOTEBOOK_H_ */
