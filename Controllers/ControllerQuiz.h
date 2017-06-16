#ifndef CONTROLLER_QUIZ_H
#define CONTROLLER_QUIZ_H

#include "../Entity/User.h"

/// Quiz

class ControllerQuiz {
public:
    void answerQuiz(User *);
    ControllerQuiz();
    ~ControllerQuiz();
};

#endif
