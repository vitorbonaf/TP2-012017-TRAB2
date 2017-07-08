/*
 * SubjectManager.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef SUBJECTMANAGER_H_
#define SUBJECTMANAGER_H_

#include <vector>

#include "Subject.h"

class SubjectManager {
private:
	SubjectManager();
	static SubjectManager *inst;
	std::vector<Subject*> *subjects;
	static int nextSubjectID;
public:
	virtual ~SubjectManager();
	static SubjectManager* instance();
    std::vector<Subject*> *getSubjects() const;
    void setSubjects(std::vector<Subject*> *subjects);
    void addSubject(Subject* subject);
    int addSubjectWithoutId(Subject* subject);
    int deleteSubjectById(int id);
    Subject* searchSubjectById(int id);
};

#endif /* SUBJECTMANAGER_H_ */
