#include "course.hpp"
#include <string>

Course::Course(){
    depart="";
}
Course::Course(std::string area, int num, char lett, std::string semes){
    depart = area;
    courseNum = num;
    grade = lett;
    semester = semes;
}

int Course::getCourseNum(){
    return courseNum;
}
char Course::getGrade(){
    return grade;
}
std::string Course::getSemester(){
    return semester;
}
std::string Course::getDepartment(){
    return depart;
}

void Course::setCourseNum(int num){
    courseNum = num;
}
void Course::setGrade(char lett){
    grade = lett;
}
void Course::setSemester(std::string semes){
    semester = semes;
}
void Course::setDepartment(std::string area){
    depart = area;
}
