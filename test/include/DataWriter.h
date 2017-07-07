/*
 * DataWriter.h
 *
 *  Created on: 16/06/2017
 *      Author: bonav
 */

#ifndef DATAWRITER_H_
#define DATAWRITER_H_

class DataWriter {
private:
	DataWriter();
	static DataWriter* inst;
public:
	virtual ~DataWriter();
	static DataWriter* instance();
	void saveData();
	void saveUsers();
	void saveNotebooks();
	void saveSubjects();
	void saveTopics();
	void saveQuizzes();
	void saveQuestions();
	void saveScores();
};

#endif /* DATAWRITER_H_ */
