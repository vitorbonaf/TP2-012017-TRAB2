/*
 * QuizManager.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef QUIZMANAGER_H_
#define QUIZMANAGER_H_

#include <vector>

#include "../Entity/Quiz.h"

class QuizManager {
private:
	QuizManager();
	static QuizManager *inst;
	std::vector<Quiz*> *quizzes;
	static int nextQuizID;
public:
	virtual ~QuizManager();
	static QuizManager* instance();
    std::vector<Quiz*> *getQuizzes() const;
    void setQuizzes(std::vector<Quiz*> *quizzes);
    void addQuiz(Quiz* quiz);
    void addQuizWithoutId(Quiz* quiz);
    void deleteQuizById(int id);
    Quiz* searchQuizById(int id);
};

#endif /* QUIZMANAGER_H_ */
