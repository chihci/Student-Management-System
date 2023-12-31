#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include "basic.h"
#include <algorithm>
#include <cctype>
#include <locale>

using namespace std;

class student : public basic
{
private:
string studentName;

public:

student();//initializes the studentName member

void addastudent();// add a student to student.txt file

bool checkstudentid(string enteredid);//check if the student student id is in student.txt file(check if the student exists in the student.txt file)

double calculatclassexamgrade(const string studentid, const string classname);// returns the student's assignment grade in the specified class

double calculatclassassignmentgrade(const string studentid, const string classname);// returns the student's assignment grade in the specified class

void updatestudentinfomation(const string id, const string newemail);//update student's information
};
#endif
