/*
 * TopicManager.h
 *
 *  Created on: 14/06/2017
 *      Author: bonav
 */

#ifndef TOPICMANAGER_H_
#define TOPICMANAGER_H_

#include <vector>

#include "../Entity/Topic.h"

class TopicManager {
private:
	TopicManager();
	static TopicManager *inst;
	std::vector<Topic*> *topics;
	static int nextTopicID;
public:
	virtual ~TopicManager();
	static TopicManager* instance();
    std::vector<Topic*> *getTopics() const;
    void setTopics(std::vector<Topic*> *topics);
    void addTopic(Topic* topic);
    void addTopicWithoutId(Topic* topic);
    void deleteTopicById(int id);
    Topic* searchTopicById(int id);
};

#endif /* TOPICMANAGER_H_ */
