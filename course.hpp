#ifndef course_hpp
#define course_hpp

#include <string>

class Course{
    private:
        std::string depart;
        int courseNum;
        char grade;
        std::string semester;
    public:
        Course();
        Course(std::string area, int num, char lett, std::string semes);
        int getCourseNum();
        char getGrade();
        std::string getSemester();
        std::string getDepartment();
        void setCourseNum(int num);
        void setGrade(char lett);
        void setSemester(std::string semes);
        void setDepartment(std::string area);
};

#endif
