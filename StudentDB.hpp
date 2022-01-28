#ifndef StudentDB_hpp
#define StudentDB_hpp

#include <iostream>
#include <string>
#include "Student.hpp"
#include "course.hpp"

class StudentDB{
    private:
    struct studList{
        Student s;
        studList* next;
        studList* previous;
    };
    studList* head;
    studList* tail;
    
    public:
        StudentDB();
        ~StudentDB();
        void deleteStudent(std::string n);
        void editStudent(std::string n);
        void addStudent(Student stud);
        void printStudentInfo(std::string n);
        void printAllInfo();
};

#endif
