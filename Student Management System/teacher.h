#ifndef TEACHER_H
#define TEACHER_H
#include "basic.h"

class teacher : public basic
{
private:
	string* teacherID;
	string* teachername;
	string* subjecttaught;
	string* emailaddresss;
	
public:
teacher();//initializes the teacher pointers

~teacher();//delete the teacher pointers

string getName(const string id) override;//retrieves the corresponding teacher's information from a file teacher.txt, and prints it to the screen.

bool checkteacherid(string enteredid);//check if a teacher's data is in teacher.txt file

double calculateoverallexamgradefortheclass(const string classname);//Calculate overall exam grade for a selected class, doesn't recive student id as an argument compare with the caculate over grade function in student.h

double calculateoverallassignmentgradefortheclass(const string classname);//Calculate overall assignment grade for a selected class, doesn't recive student id as an argument compare with the caculate over grade function in student.h

void addateacher();//add a teacher to teacher.txt file

void enterexamgrade(const string studentsid, const string studentgrade, const string classname);//enter an exam grade for a student

void enterassignmentgrade(const string studentsid, const string studentgrade, const string classname);//enter an assignment grade for a student


};
#endif