/*
 * Question.cpp
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#include "Question.h"

Question::Question() {
	this->answers = new std::vector<std::string>();

}

char Question::getActive() const
{
    return active;
}

std::vector<std::string> *Question::getAnswers() const
{
    return answers;
}

int Question::getCorrect_answer_index() const
{
    return correct_answer_index;
}

int Question::getId() const
{
    return id;
}

std::string Question::getText() const
{
    return text;
}

int Question::getType() const
{
    return type;
}

int Question::getValue() const
{
    return value;
}

void Question::setActive(char active)
{
    this->active = active;
}

void Question::setAnswers(std::vector<std::string> *answers)
{
    this->answers = answers;
}

void Question::setCorrect_answer_index(int correct_answer_index)
{
    this->correct_answer_index = correct_answer_index;
}

void Question::setId(int id)
{
    this->id = id;
}

void Question::setText(std::string text)
{
    this->text = text;
}

void Question::setType(int type)
{
    this->type = type;
}

void Question::setValue(int value)
{
    this->value = value;
}

Question::~Question() {
	// TODO Auto-generated destructor stub
}
