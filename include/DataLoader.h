/*
 * DataLoader.h
 *
 *  Created on: 15/06/2017
 *      Author: bonav
 */

#ifndef DATALOADER_H_
#define DATALOADER_H_

class DataLoader {
private:
	DataLoader();
	static DataLoader *inst;
	void loadUsers();
	void loadNotebooks();
	void loadSubjects();
	void loadTopics();
	void loadQuizzes();
	void loadQuestions();
	void loadScores();
public:
	virtual ~DataLoader();
	static DataLoader* instance();
	void loadData();
};

#endif /* DATALOADER_H_ */
