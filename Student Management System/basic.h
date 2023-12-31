#ifndef BASIC_H
#define BASIC_H

using namespace std;

#include<string>

class basic
{
private:


public:
	void trackattendance(const string studentsid);//track student attendance

	void Markattendence(const string passstudentID, const string& entereddate, const string& status);//Mark student's attendence status

	basic(); //default constructor 

	virtual string getName(const string studentid); //get Name for student, teacher

	void updateSchedule(const string newschedule, const string studentid, const string todaysdate); //update schedule for student, subject for teacher, student list for class.

	 string trackexamgradee(string enteredid,string classname);//track exam grade

	string trackassignmentgradee(string enteredid, string classname);//track assignment grade

	string trim(const string& str)//implementation for trimming leading and trailing whitespaces from a string.
	{
		size_t first = str.find_first_not_of(" \t\n\r\f\v");
		size_t last = str.find_last_not_of(" \t\n\r\f\v");
		return (first != string::npos && last != string::npos) ? str.substr(first, (last - first + 1)) : "";
	}
};

#endif