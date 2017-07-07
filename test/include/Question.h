/*
 * Question.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef QUESTION_H_
#define QUESTION_H_

#include <string>
#include <vector>

class Question {

private:
	int id;
	char active;
	std::string text;
	// 1 = VouF | 2 = MultiplaEscolha
	int type;
	std::vector<std::string> *answers;
	int correct_answer_index;
	int value;
public:
	Question();
	virtual ~Question();
    char getActive() const;
    std::vector<std::string> *getAnswers() const;
    int getCorrect_answer_index() const;
    int getId() const;
    std::string getText() const;
    int getType() const;
    int getValue() const;
    void setActive(char active);
    void setAnswers(std::vector<std::string> *answers);
    void setCorrect_answer_index(int correct_answer_index);
    void setId(int id);
    void setText(std::string text);
    void setType(int type);
    void setValue(int value);
};

#endif /* QUESTION_H_ */
