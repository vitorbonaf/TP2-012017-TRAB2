#ifndef CONTROLLER_ADMIN_H
#define CONTROLLER_ADMIN_H

class ControllerAdmin {
public:
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
    ControllerAdmin();
    ~ControllerAdmin();
}; 

#endif

