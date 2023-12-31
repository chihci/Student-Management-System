#ifndef CLASSES_H
#define CLASSES_H
#include <vector>
#include <algorithm>
#include "student.h"

class classes
{
private:

public:

bool checkclassname(const string name);//check if the class name is in student.txt file

bool checkclassname2(const string name);//check if the class name is in classes.txt file

void trackattendance(const string& studentid, const string& classname);// track student's attendance status by using their student id and the class attending

string generateAttendanceReport(const int& startDate, const int& endDate, const string classname);// generate an attendance report

string trim(const string& str)//implementation for trimming leading and trailing whitespaces from a string.
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return (first != string::npos && last != string::npos) ? str.substr(first, (last - first + 1)) : "";
}          

string trackexamgrade(string classname,const string studentid);//same as basic class ? use vitrual function ?

string trackassignmentgrade(string classname, const string  studentid);//same as basic class? use vitrual function?

void addStudent(const string studentname, const string classname, const string teachername);// add a student to a class

void printclass(const string classname, const string teachername);//print the information of a class (class name, teacher name, list of student)

void removeStudent(const string studentneme, const string classname, const string teachername);//remove a student from a class

void createClass(const string classname, const string teachername);//create a new class (Ex.history class, math class)


};
#endif