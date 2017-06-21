/*
 * Subject.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <string>
#include <vector>

#include "Topic.h"
class Subject {
private:
	int id;
	char active;
	std::string name;
	std::vector<Topic*> *topics;
public:
	Subject();
	virtual ~Subject();
    char getActive() const;
    int getId() const;
    std::string getName() const;
    std::vector<Topic*> *getTopics() const;
    void setActive(char active);
    void setId(int id);
    void setName(std::string name);
    void setTopics(std::vector<Topic*> *topics);
};

#endif /* SUBJECT_H_ */
