#include <iostream>
#include <string>
#include <stdio.h>
#include "StudentDB.hpp"
#include "Student.hpp"
#include "course.hpp"

int main() {
    StudentDB salisburyUniversity = StudentDB();
    bool contin = true;
    char choose;
    printf("\nWelcome to the Generic University Student Database\n");
    while (contin){
	printf("====================================================================\n");
        printf("\tMain Menu\n");
        printf("A. Add Student\nB. Delete Student\nC. Edit Student\n");
        printf("D. Display a student's info\nE. Display all student information\n");
        printf("X. Exit Program\n\nSelect: ");
        std::cin>>choose;
        std::cout<<"====================================================================\n";

        switch (choose){
            case 'A':{
                std::string name;
                double gpa=-1.0;
                std::string m,d,y,maj;
                
                printf("Enter the Following Information:\n");
		printf("-------------------------------------\n");
                printf("Name: ");
                std::cin.ignore();
                getline (std::cin, name);
		
                while (gpa<=0.0||gpa>4.0){
                    printf("GPA: ");
                    std::cin>>gpa;
                    if (gpa<=0.0||gpa>4.0)
                        printf("Invalid Entry\n\n");
                }
                
                printf("\nDate of Birth (format printed xx/xx/xxxx or x/x/xx):\n");
		printf("-----------------------------------------------------\n");
                printf("Month: ");
                std::cin>>m;
                printf("Day: ");
                std::cin>>d;
                printf("Year: ");
                std::cin>>y;
                std::string dob = m+"/"+d+"/"+y;

                printf ("\nMajor: ");
                std::cin.ignore();
                getline(std::cin,maj);

                Student stud = Student(name,dob,gpa,maj);
                salisburyUniversity.addStudent(stud);
                break;
            }
            case 'B':{
                std::string search;
                printf("Enter the student name to delete: ");
                std::cin.ignore();
                getline(std::cin,search);
                salisburyUniversity.deleteStudent(search);
                break;
            }
            case 'C':{
                std::string search;
                printf("Enter the student name to edit: ");
                std::cin.ignore();
                getline(std::cin,search);
		printf("====================================================================\n\n");
                salisburyUniversity.editStudent(search);
                break;
            }
            case 'D':{
                std::string search;
                printf("Enter the student name to print: ");
                std::cin.ignore();
                getline(std::cin,search);
		printf("====================================================================\n\n");
                salisburyUniversity.printStudentInfo(search);
                break;
            }
            case 'E':{
		printf("====================================================================\n\n");
                salisburyUniversity.printAllInfo();
                break;
            }
            case 'X':{
                contin = false;
                break;
            }
            default:{
                printf("Invalid Input");
            }
        }
    }
    return 0;
}
