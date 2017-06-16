/*
 * Quiz.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef QUIZ_H_
#define QUIZ_H_

#include <string>
#include <vector>

#include "Question.h"

class Quiz {
private:
	int id;
	char active;
	std::string name;
	std::vector<Question*> *questions;
public:
	Quiz();
	virtual ~Quiz();
    char getActive() const;
    int getId() const;
    std::string getName() const;
    std::vector<Question*> *getQuestions() const;
    void setActive(char active);
    void setId(int id);
    void setName(std::string name);
    void setQuestions(std::vector<Question*> *questions);
};

#endif /* QUIZ_H_ */
