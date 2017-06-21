#ifndef CONTROLLER_QUIZ_H
#define CONTROLLER_QUIZ_H

#include "User.h"

/// Quiz

class ControllerQuiz {
private:
	ControllerQuiz();
	static ControllerQuiz *inst;
public:
	static ControllerQuiz* instance();
    void answerQuiz(User *);
    ~ControllerQuiz();
};

#endif
