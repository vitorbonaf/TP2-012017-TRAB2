#ifndef CONTROLLER_ADMIN_H
#define CONTROLLER_ADMIN_H

class ControllerAdmin {
private:
	static ControllerAdmin *inst;
	ControllerAdmin();
public:
	static ControllerAdmin* instance();
    void manageStudents();
    void includeStudent();
    void removeStudent();
    void manageSubjects();
    void includeSubject();
    void includeTopic();
    void includeQuiz();
    void removeSubject();
    void removeTopic();
    void removeQuiz();
    ~ControllerAdmin();
}; 

#endif

