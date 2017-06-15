/*
 * QuestionManager.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef QUESTIONMANAGER_H_
#define QUESTIONMANAGER_H_

#include <vector>

#include "../Entity/Question.h"

class QuestionManager {
private:
	QuestionManager();
	static QuestionManager *inst;
	std::vector<Question*> *questions;
	static int nextQuestionID;
public:
	virtual ~QuestionManager();
	static QuestionManager* instance();
    std::vector<Question*> *getQuestions() const;
    void setQuestions(std::vector<Question*> *questions);
    void addQuestion(Question* question);
    void addQuestionWithoutId(Question* question);
    void deleteQuestionById(int id);
    Question* searchQuestionById(int id);
};

#endif /* QUESTIONMANAGER_H_ */
