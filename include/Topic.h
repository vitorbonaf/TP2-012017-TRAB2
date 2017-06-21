/*
 * Topic.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef TOPIC_H_
#define TOPIC_H_

#include <string>
#include <vector>

#include "Quiz.h"

class Topic {
private:
	int id;
	char active;
	std::string name;
	std::vector<Quiz*> *quizzes;
public:
	Topic();
	virtual ~Topic();
    char getActive() const;
    int getId() const;
    std::string getName() const;
    std::vector<Quiz*> *getQuizzes() const;
    void setActive(char active);
    void setId(int id);
    void setName(std::string name);
    void setQuizzes(std::vector<Quiz*> *quizzes);
};

#endif /* TOPIC_H_ */
