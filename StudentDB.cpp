#include "StudentDB.hpp"
#include "Student.hpp"
#include "course.hpp"
#include <iostream>
#include <stdio.h>
#include <string>

StudentDB::StudentDB(){
    head = NULL;
}

StudentDB::~StudentDB(){
    studList* track = head;
    while (track){
        if (track->next && track->previous){
            track->previous->next = track->next;
            track->next->previous = track->previous;
        }
        else if (track->next){
            track->next->previous=track->previous;
            head=track->next;
        }
        else if (track->previous){
            track->previous->next=track->next;
            tail = track->previous;
        }
        else{
            head=tail=NULL;
        }
        studList* tmp = track;
        tmp->s.deleteAllCourses();
        delete track;
        track = tmp->next;
    }
}


void StudentDB::addStudent(Student stud){
    studList* newNode = new studList;
    char add = 'y';
    newNode->s = stud;

    if (!head){
        head = tail = newNode;
        tail->next = NULL;
        printf("\nWould you like to add any courses?\n");
        std::cin>>add;
    }
    else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        tail->next = NULL;
        printf("\nWould you like to add courses?\n");
        std::cin>>add;
    }
    while (add == 'y'){
        int num = 0;
        std::string depart;
        std::string semes;
        char grade = '1';
        
        while (num>=1000 || num<=100){
            printf("Enter the course number: ");
            std::cin>>num;
            if (num>=1000 || num<=100)
                printf("\nInvalid Value\n\n");
        }
        
        printf("Enter the department: ");
        std::cin.ignore();
        getline(std::cin,depart);
        
        while (grade!='A'&&grade!='B'&&grade!='C'&&grade!='D'&&grade!='F'){
            printf("Enter the grade: ");
            std::cin>>grade;
            if (grade!='A'&&grade!='B'&&grade!='C'&&grade!='D'&&grade!='F')
                printf("\nInvalid Value\n\n");
        }
        
        printf("Enter the semester completed: ");
        std::cin.ignore();
        getline(std::cin,semes);
        
        Course cour = Course(depart,num,grade,semes);
        tail->s.addCourse(cour);
        printf("\nCourse Added!\n\nWould you like to add another: ");
        std::cin>>add;
    }
    printf("\nStudent Added!\n");
}

void StudentDB::deleteStudent(std::string n){
    if (!head)
        printf("\nStudent List is Empty!\n");
    
    else{
        studList* left = head;
        studList* right = tail;
        studList* use;
        
        if (head->s.getName() == n)
            use = head;
        else if (tail->s.getName() == n)
            use = tail;
        else{
            while (left!=right && left->next!=right){
                if (left->s.getName()==n && right->s.getName() ==  n)
                    break;
                else{
                    left = left->next;
                    right = right->previous;
                }
            }
        }
        if (left->s.getName() == n)
            use = left;
        else if (right->s.getName() == n)
            use = right;
        else{
            printf("\nStudent not found\n");
            return;
        }
            
        if (use->next && use->previous){
            use->previous->next = use->next;
            use->next->previous = use->previous;
        }
        else if (use->next){
            use->next->previous=use->previous;
            head=use->next;
        }
        else if (use->previous){
            use->previous->next=use->next;
            tail = use->previous;
        }
        else{
            head = tail = NULL;
        }
        delete use;
    }
}


void StudentDB::editStudent(std::string n){
    bool check = true;
    char choice;
    studList* left = head;
    studList* right = tail;
    studList* use;
    
    if (!head){
        printf("\nStudent list empty!\n");
        return;
    }
    
    if (head->s.getName() == n)
        use = head;
    else if (tail->s.getName() == n)
        use = tail;
    else{
        while (left!=right && left->next!=right && left->s.getName()!=n && right->s.getName() !=  n){
            left = left->next;
            right = right->previous;
        }
        if (left->s.getName() == n)
            use = left;
        else if (right->s.getName()==n)
            use = right;
        else{
            printf("\nStudent not found!\n");
            return;
        }
    }
        
    while(check){
        printf("====================================================================\n");
        printf("\t%s's Menu\n",use->s.getName().c_str());
        printf("a)Display Student\nb)Edit Name\nc)Edit GPA\nd)Edit Birthdate\ne)Edit Major\n");
        printf("f)Add a Course\ng)Edit a Course\nh)Display Courses\n");
	printf("i)Delete a Course\nX)Exit Menu\n\nSelect: ");
        std::cin>>choice;
            
        switch (choice){
	    case 'a':{
		printf("==================================================\n");
		printStudentInfo(use->s.getName());
		break;
	    }
            case 'b':{
                std::string newName;
                printf("\nEnter a new name: ");
                std::cin.ignore();
                getline(std::cin,newName);
                use->s.setStudent(newName);
                printf("\nName Changed\n");
                break;
            }
            case 'c':{
                double newGPA = 0;
                while (newGPA<=0.0||newGPA>4.0){
                    printf("Enter new GPA: ");
                    std::cin>>newGPA;
                    if (newGPA<=0.0||newGPA>4.0)
                        printf("\n\nInvalid Entry\n");
                    else
                        printf("\nGPA Changed");
                    }
		use->s.setGPA(newGPA);
                break;
            }
            case 'd':{
                std::string m,d,y,dob;
                printf("\nNew Month:");
                std::cin>>m;
                printf("New Day: ");
                std::cin>>d;
                printf("New Year: ");
                std::cin>>y;
                dob = m + "/" + d + "/" + y;
                use->s.setDOB(dob);
                printf("\nBirthdate Changed\n");
                break;
            }
            case 'e':{
                std::string newMajor;
                printf("\nEnter new major: ");
                std::cin.ignore();
                getline(std::cin,newMajor);
                use->s.setMajor(newMajor);
                printf("\nMajor changed\n");
                break;
            }
            case 'f':{
                char add = 'y';
                while (add == 'y'){
                    int num = 0;
                    std::string depart;
                    std::string semes;
                    char grade = '1';

                    while (num>=1000 || num<=100){
                        printf("Enter the course number: ");
                        std::cin>>num;
                        if (num>=1000 || num<=100)
                            printf("\nInvalid Value\n");
                    }

                    printf("Enter the department: ");
                    std::cin.ignore();
                    getline(std::cin,depart);
                    
                    while (grade!='A'&&grade!='B'&&grade!='C'&&grade!='D'&&grade!='F'){
                        printf("Enter the grade: ");
                        std::cin>>grade;
                        if (grade!='A'&&grade!='B'&&grade!='C'&&grade!='D'&&grade!='F')
                            printf("\nInvalid Value\n");
                    }
                    
                    printf("Enter the semester completed: ");
                    std::cin.ignore();
                    getline(std::cin,semes);

                    Course cour = Course(depart,num,grade,semes);
                    use->s.addCourse(cour);
                    printf("\nCourse Added!\nWould you like to add another: ");
                    std::cin>>add;
                    }
                break;
            }
            case 'g':{
                std::string name;
                int num=0;
                    
                while (num>=1000 || num<=100){
                    printf("Enter the course number: ");
                    std::cin>>num;
                    if (num>=1000 || num<=100)
                        printf("\nInvalid Value\n");
                }
                
                printf("Enter the department: ");
                std::cin>>name;
                
                use->s.editCourse(num,name);
                break;
            }
	    case 'h':{
		printf("-------------------------------------------------------\n");
	        use->s.printCourses();
		printf("-------------------------------------------------------\n");
		break;
	    }
            case 'i':{
                std::string name;
                int num=0;
                    
                while (num>=1000 || num<=100){
                    printf("Enter the course number: ");
                    std::cin>>num;
                    if (num>=1000 || num<=100)
                        printf("\nInvalid Value\n");
                }
                
                printf("Enter the department: ");
                std::cin>>name;
                
                use->s.deleteCourse(num, name);
                break;
            }
            case 'X':{
                check = false;
                break;
            }
            default:
                printf("\nInvalid input!\n");
        }
    }
    printf("=========================================\n");
}


void StudentDB::printStudentInfo(std::string n){
    studList* left = head;
    studList* right = tail;
    studList* use;
    
    if (!head){
        printf("\nStudent list is empty!\n");
        return;
    }
    
    if (head->s.getName() == n)
        use = head;
    else if (tail->s.getName() == n)
        use = tail;
    else{
        while (left!=right && left->next!=right && left->s.getName()!=n && right->s.getName() != n){
            left = left->next;
            right = right->previous;
        }
        if (left->s.getName() == n)
            use = left;
        else if (right->s.getName()==n)
            use = right;
        else{
            printf("\nStudent not found!\n");
            return;
        }
    }
    printf("==================================================\n");
    printf("|%s:",use->s.getName().c_str());
    printf("\n|\tMajor: %s\n",use->s.getMajor().c_str());
    printf("|\tGPA: %0.2f\n",use->s.getGPA());
    printf("|\tBirthdate: %s\n|\n",use->s.getDOB().c_str());
    printf("|Courses:\n");
    use->s.printCourses();
    printf("==================================================\n\n");
}

void StudentDB::printAllInfo(){
    if (!head)
        printf("Student list is empty!\n");
    else{
        studList* use = head;
        printf("=======================================================\n");
        while(use){
            printf("|%s:",use->s.getName().c_str());
            printf("\n|\tMajor: %s\n",use->s.getMajor().c_str());
            printf("|\tGPA: %0.2f\n",use->s.getGPA());
            printf("|\tBirthdate: %s\n|\n",use->s.getDOB().c_str());
            printf("|Courses:\n");
            use->s.printCourses();
            if (use->next)
                printf("|--------------------------------------------------\n");
            use = use->next;
        }
        printf("=======================================================\n\n");
    }
}
