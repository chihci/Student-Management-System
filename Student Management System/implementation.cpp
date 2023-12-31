#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include "basic.h"
#include "student.h"
#include "teacher.h"
#include "classes.h"
#include "Exam.h"
#include "Assignment.h"

using namespace std;

//basic.h********************************************************************************************************************************************
basic::basic()
{

}

string basic::getName(const string id) //get the Name of student, teacher, and class
{
    ifstream studentFile("student.txt");
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string ID, Name;

            getline(ss, ID, ',');
            getline(ss, Name, ',');

            if (id == ID)
            {
                cout << "---------------------------------------------\n";
                cout << "Your ID is: " << ID << ", Your name is: " << Name << "\n";
                cout << "---------------------------------------------\n";
                cout << endl;
                return Name;
            }
        }
        studentFile.close();
    }
}

void basic::updateSchedule(const string newschedule, const string studentid, const string todaysdate) //update schedule for student, subject for teacher
{
    fstream studentFile("student.txt", ios::in | ios::out);

    if (studentFile.is_open())
    {
        string line;
        size_t position = 0;

        while (getline(studentFile, line)) {
            stringstream ss(line);
            string studentID, studentName, emailaddress,attendanceStatus, classSchedule, Classname, date;

            
            getline(ss, studentID, ',');
            getline(ss, studentName, ',');
            getline(ss, emailaddress, ',');
            getline(ss, attendanceStatus, ',');        
            getline(ss, classSchedule, ',');
            getline(ss, Classname, ',');
            getline(ss, date, ',');
            
            
            if (trim(studentid) == trim(studentID))
            {
                // Update the values
                classSchedule = newschedule;
                date = todaysdate;
                


                // Move to the beginning of the line in the file
                studentFile.seekp(position, ios::beg);
                studentFile.clear();
               
                // Write the modified line back to the file
                studentFile << studentID << ',' << studentName << ',' << emailaddress <<  ',' << attendanceStatus << ',' << classSchedule << ',' << Classname << ',' << date << endl;
                break;
            }

            // Save the position in the file to know where to write back the modified line
            position = studentFile.tellg();
        }
        cout << "---------------------------------------------\n";
        cout << "Student information is Updated \n";
        cout << "---------------------------------------------\n";
        studentFile.close();
    }
}

string basic::trackexamgradee(string passstudentID, string classname)
{
    ifstream ExamFile("Exam.txt");
    if (ExamFile.is_open())
    {
        string line;
        while (getline(ExamFile, line))
        {
            stringstream ss(line);
            string StudentID, StudentName, Classname, ExamGrade; // Add more fields if needed

            getline(ss, StudentID, ',');
            getline(ss, StudentName, ',');
            getline(ss, Classname, ',');
            getline(ss, ExamGrade, ',');
            // compare studentID with enteredid here
            if (trim(StudentID) == trim(passstudentID)&& trim(Classname)== trim(classname)) {
                ExamFile.close();
                return ExamGrade;
            }
        }
        ExamFile.close();
    }
    else
    {
        cout << "---------------------------------------------\n";
        cout << "can't not open file" << endl;
        cout << "---------------------------------------------\n";
    }
}

string basic::trackassignmentgradee(const string passstudentID, const string classname)
{
ifstream AssignmentFile("Assignment.txt");
if (AssignmentFile.is_open())
{
    string line;
    while (getline(AssignmentFile, line))
    {
        stringstream ss(line);
        string studentID, studentName, Classname, AssignmentGrade;

        getline(ss, studentID, ',');
        getline(ss, studentName, ',');
        getline(ss, Classname, ',');
        getline(ss, AssignmentGrade, ',');       
        // You can compare studentID with enteredid here
        if (trim(studentID) == trim(passstudentID) && trim(Classname) == trim(classname)) {
            AssignmentFile.close();
            return AssignmentGrade;
        }
    }
    AssignmentFile.close();
}
else
{
    cout << "---------------------------------------------\n";
    cout << "can't not open file" << endl;
    cout << "---------------------------------------------\n";
}
}

void basic::trackattendance(const string studentsid)
{
    ifstream studentFile("student.txt");
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string StudentID, StudentName, emailaddress, AttendanceStatus, ClassSchedule;

            getline(ss, StudentID, ',');
            getline(ss, StudentName, ',');
            getline(ss, emailaddress, ',');
            getline(ss, AttendanceStatus, ',');      
           getline(ss, ClassSchedule, ',');
            // You can compare studentID with enteredid here
            if (trim(StudentID) == trim(studentsid)) {
                cout << "---------------------------------------------\n";
                cout << StudentName << " is " << AttendanceStatus << " in " << ClassSchedule << '\n';
                cout << "---------------------------------------------\n";
                studentFile.close();


            }
        }
        studentFile.close();
    }
}  

void basic::Markattendence(const string passstudentID, const string& entereddate, const string& status)
{
    fstream studentFile("student.txt", ios::in | ios::out);

    if (studentFile.is_open())
    {
        string line;
        size_t position = 0;
        bool checkdate = false;
        while (getline(studentFile, line)) {
            stringstream ss(line);
            string studentID, studentName, emailaddress, attendanceStatus, classSchedule, Classname, date;

            // Assuming the fields are in order: StudentID, StudentName, AttendanceStatus, ExamGrade, AssignmentGrade, ClassSchedule
            getline(ss, studentID, ',');
            getline(ss, studentName, ',');
            getline(ss, emailaddress, ',');
            getline(ss, attendanceStatus, ',');
            getline(ss, classSchedule, ',');
            getline(ss, Classname, ',');
            getline(ss, date, ',');

            // Trim whitespaces from both ends before comparison
            if (trim(passstudentID) == trim(studentID) && trim(entereddate) == trim(date))
            {
                             
                // Update the values
                    attendanceStatus = status;

                    // Move to the beginning of the line in the file
                    studentFile.seekp(position, ios::beg);
                    studentFile.clear();

                    // Write the modified line back to the file with padded status
                    studentFile << studentID << ',' << studentName << ',' << emailaddress << ',' << attendanceStatus << ',' << classSchedule << ',' << Classname <<',' << date << endl;
                    cout << "------------------------------------------------------------------------\n";
                    cout << "Student status updated!\n";
                    cout << "------------------------------------------------------------------------\n";
                    checkdate = true;
                    break;
            }
          
               
            // Save the position in the file to know where to write back the modified line
            position = studentFile.tellg();
        }
   
    if(checkdate==false)
    { 
        cout << "------------------------------------------------------------------------\n";
        cout << "Invalid date" << endl;
        cout << "------------------------------------------------------------------------\n";
    }
    
        studentFile.close();
      
       
    }
    
    
}



//student.h********************************************************************************************************************************************

student::student()
{
    studentName = "";
}

void student::addastudent()
{
    // Open the file in append mode
    ofstream studentFile("student.txt", ios::app);

    if (studentFile.is_open())
    {
        string StudentID, StudentName, emailaddress,AttendanceStatus, ClassSchedule, Classname, date;

        // Take input for the new person's details
        cout << "---------------------------------------------\n";
        cout << "Enter Student ID(number): \n";
        cout << "---------------------------------------------\n";
        cin >> StudentID;
        cout << "---------------------------------------------\n";
        cout << "Enter Student Name: \n";
        cout << "---------------------------------------------\n";
        cin.ignore();  // Ignore the newline character in the buffer
        getline(cin, StudentName);
        cout << "---------------------------------------------\n";
        cout << "Enter Email Address: \n";
        cout << "---------------------------------------------\n";
        cin >> emailaddress;
        cout << "---------------------------------------------\n";
        cout << "Enter Attendance Status(present, absent,tardy): \n";
        cout << "---------------------------------------------\n";
        cin >> AttendanceStatus;
        cout << "---------------------------------------------\n";
        cout << "Enter Class Schedule(one day of the week): \n";
        cout << "---------------------------------------------\n";
        cin.ignore();  // Ignore the newline character in the buffer
        getline(cin, ClassSchedule);
        cout << "---------------------------------------------\n";
        cout << "Enter Class Name: \n";
        cout << "---------------------------------------------\n";
        cin >> Classname;
        cout << "---------------------------------------------\n";
        cout << "Enter Date(in YYYYMMDD format): \n";
        cout << "---------------------------------------------\n";
        cin >> date;
        cout << "---------------------------------------------\n";

        // Write the details to the file
        studentFile << '\n' << '\n' << StudentID << ',' << StudentName << ',' << emailaddress << ',' << AttendanceStatus << ',' << ClassSchedule << ',' << Classname << ',' << date << '\n';
        cout << "---------------------------------------------\n";
        cout << "Person added successfully!" << endl;
        cout << "---------------------------------------------\n";
    }
    else
    {
        cout << "---------------------------------------------\n";
        cout << "Error opening student file." << endl;
        cout << "---------------------------------------------\n";
    }

    // Close the file
    studentFile.close();
}

bool student::checkstudentid(string enteredid)//check entered id to see if it’s valid to enter specific page(student, teacher, class) of the program
{
    ifstream studentFile("student.txt");
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string ID; 

            getline(ss, ID, ',');
            //  compare studentID with enteredid here
            if (ID == enteredid) {
                studentFile.close();
                return true;
            }
            
            ss.str("");
            ss.clear();
        }
        return false;
        studentFile.close();
    }
    else
    {
        cout << "---------------------------------------------\n";
        cout << "Can not open student file" << endl;
        cout << "---------------------------------------------\n";
    }
}

double student::calculatclassexamgrade(const string studentid, const string classname)
{
    ifstream studentFile("Exam.txt");
    double sum = 0;
    int studentnumber = 0;
    double classaverage = 0.0;
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string StudentID, StudentName, Classname, ExamGrade;

            getline(ss, StudentID, ',');
            getline(ss, StudentName, ',');   
            getline(ss, Classname, ',');
            getline(ss, ExamGrade, ',');    
           
            
            if (trim(Classname) == trim(classname))
                {
                sum += stod(ExamGrade);//string to int
               studentnumber++;
                    
                }
            
        }
        if (studentnumber > 0)
        classaverage = sum / studentnumber;

        return classaverage;
    }
    studentFile.close();
}   

double student::calculatclassassignmentgrade(const string studentid, const string classname)
{
    ifstream studentFile("Assignment.txt");
    double sum = 0.0;
    int studentnumber = 0;
    double classaverage = 0.0;
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string StudentID, StudentName, Classname, AssignmentGrade;

            getline(ss, StudentID, ',');
            getline(ss, StudentName, ',');
            getline(ss, Classname, ',');
            getline(ss, AssignmentGrade, ',');
           

            if (trim(Classname) == trim(classname))
            {
                sum += stod(AssignmentGrade);//string to int
                studentnumber++;

            }

        }
        if (studentnumber > 0)
            classaverage = sum / studentnumber;

        return classaverage;
    }
    studentFile.close();
}

void student::updatestudentinfomation(const string id, const string newemail)
{
    fstream studentFile("student.txt", ios::in | ios::out);

    if (studentFile.is_open())
    {
        string line;
        size_t position = 0;

        while (getline(studentFile, line)) {
            stringstream ss(line);
            string studentID, studentName, emailaddress, attendanceStatus, classSchedule, Classname, date;

            // Assuming the fields are in order: StudentID, StudentName, AttendanceStatus, ExamGrade, AssignmentGrade, ClassSchedule
            getline(ss, studentID, ',');
            getline(ss, studentName, ',');
            getline(ss, emailaddress, ',');
            getline(ss, attendanceStatus, ',');
            getline(ss, classSchedule, ',');
            getline(ss, Classname, ',');
            getline(ss, date, ',');

            // Trim whitespaces from both ends before comparison
            if (trim(id) == trim(studentID))
            {
                // Update the values

                emailaddress = newemail;


                // Move to the beginning of the line in the file
                studentFile.seekp(position, ios::beg);
                studentFile.clear();
                // Write the modified line back to the file
                studentFile << studentID << ',' << studentName << ',' << emailaddress << ',' << attendanceStatus << ',' << classSchedule << ',' << Classname << ',' << date << endl;
                break;
            }

            // Save the position in the file to know where to write back the modified line
            position = studentFile.tellg();
        }

        studentFile.close();
    }
    cout << "---------------------------------------------\n";
    cout << "Student information is Updated \n";
    cout << "---------------------------------------------\n";
}




//teacher.h********************************************************************************************************************************************

teacher::teacher() : teacherID(new string(" ")), teachername(new string(" ")), subjecttaught(new string(" ")), emailaddresss(new string(" ")) {
   
}

teacher::~teacher() 
{
    delete teacherID;
    delete teachername;
    delete subjecttaught;
    delete emailaddresss;
}

bool teacher::checkteacherid(string enteredid)//check entered id to see if it’s valid to enter specific page(student, teacher, class) of the program
{
    ifstream studentFile("teacher.txt");
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string ID; // Add more fields if needed

            getline(ss, ID, ',');
            // You can compare studentID with enteredid here
            if (ID == enteredid) {
                studentFile.close();
                return true;
            }
            ss.str("");
            ss.clear();
        }
        studentFile.close();
        return false;
    }
    else
    {
        cout << "Can't open teacher file \n";
        return false;
    }
}

string teacher::getName(const string id) //get the Name of student, teacher, and class
{
    ifstream studentFile("teacher.txt");
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string ID, Name;

            getline(ss, ID, ',');
            getline(ss, Name, ',');

            if (id == ID)
            {
                cout << "---------------------------------------------\n";
                cout << "Your ID is: " << ID << ", Your name is: " << Name << "\n";
                cout << "---------------------------------------------\n";
                cout << endl;
                return Name;
            }
        }
        studentFile.close();
    }
}

void teacher::enterexamgrade(const string studentsid, const string studentgrade, const string classname)
{
    fstream studentFile("Exam.txt", ios::in | ios::out);

    if (studentFile.is_open())
    {
        string line;
        size_t position = 0;

        while (getline(studentFile, line)) {
            stringstream ss(line);
            string StudentID, StudentName, Classname, ExamGrade;

            // Assuming the fields are in order: StudentID, StudentName, AttendanceStatus, ExamGrade, AssignmentGrade, ClassSchedule
            getline(ss, StudentID, ',');
            getline(ss, StudentName, ',');
            getline(ss, Classname, ',');
            getline(ss, ExamGrade, ',');
       

            // Trim whitespaces from both ends before comparison
            if (trim(studentsid) == trim(StudentID) && trim(classname) == trim(Classname))
            {

                ExamGrade=studentgrade;

                studentFile.seekp(position, ios::beg);
                studentFile.clear();
               
                studentFile << StudentID << ',' << StudentName << ',' << Classname << ',' << ExamGrade << '\n';
                studentFile.close();
                break;
            }

            // Save the position in the file to know where to write back the modified line
            position = studentFile.tellg();
        }

        studentFile.close();
    }
}

void teacher::enterassignmentgrade(const string studentsid, const string studentgrade, const string classname)
{
    fstream studentFile("Assignment.txt", ios::in | ios::out);

    if (studentFile.is_open())
    {
        string line;
        size_t position = 0;

        while (getline(studentFile, line)) {
            stringstream ss(line);
            string StudentID, StudentName, Classname, AssignmentGrade;

            // Assuming the fields are in order: StudentID, StudentName, AttendanceStatus, ExamGrade, AssignmentGrade, ClassSchedule
            getline(ss, StudentID, ',');
            getline(ss, StudentName, ',');
            getline(ss, Classname, ',');
            getline(ss, AssignmentGrade, ',');


            // Trim whitespaces from both ends before comparison
            if (trim(studentsid) == trim(StudentID) && trim(classname) == trim(Classname))
            {

                AssignmentGrade = studentgrade;

                studentFile.seekp(position, ios::beg);
                studentFile.clear();

                studentFile << StudentID << ',' << StudentName << ',' << Classname << ',' << AssignmentGrade << endl;
                studentFile.close();
                break;
            }

            // Save the position in the file to know where to write back the modified line
            position = studentFile.tellg();
        }

        studentFile.close();
    }
}

double teacher::calculateoverallexamgradefortheclass(const string classname)
{
    ifstream studentFile("Exam.txt");
    int Classgrade;
    double sum = 0;
    int studentnumber = 0;
    double classaverage;
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string StudentID, StudentName, Classname, ExamGrade;

            getline(ss, StudentID, ',');
            getline(ss, StudentName, ',');
            getline(ss, Classname, ',');
            getline(ss, ExamGrade, ',');
           

            if (trim(Classname) == trim(classname))
            {
                sum += stod(ExamGrade);//string to int
                studentnumber++;

            }

        }
        if (studentnumber > 0)
            classaverage = sum / studentnumber;

        return classaverage;
    }
    studentFile.close();
}

double teacher::calculateoverallassignmentgradefortheclass(const string classname)
{
    ifstream studentFile("Assignment.txt");
    int Classgrade;
    double sum = 0;
    int studentnumber = 0;
    double classaverage;
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string StudentID, StudentName, Classname, AssignmentGrade;

            getline(ss, StudentID, ',');
            getline(ss, StudentName, ',');
            getline(ss, Classname, ',');
            getline(ss, AssignmentGrade, ',');


            if (trim(Classname) == trim(classname))
            {
                sum += stod(AssignmentGrade);//string to int
                studentnumber++;

            }

        }
        if (studentnumber > 0)
            classaverage = sum / studentnumber;

        return classaverage;
    }
    studentFile.close();
}

void teacher::addateacher()
{
    ofstream teacherFile("teacher.txt", ios::app);

    if (teacherFile.is_open())
    {
        

        // Take input for the new person's details
        cout << "---------------------------------------------\n";
        cout << "Enter teacher ID: \n";
        cout << "---------------------------------------------\n";
        cin >> *teacherID;  // Use the dynamically allocated string
      
        
        cout << "---------------------------------------------\n";
        cout << "Enter teacher Name: \n";
        cout << "---------------------------------------------\n";
        cin.ignore();  // Ignore the newline character in the buffer
        getline(cin, *teachername);  // Use the dynamically allocated string
      
        
        cout << "---------------------------------------------\n";
        cout << "Enter subject taught: \n";
        cout << "---------------------------------------------\n";
        getline(cin, *subjecttaught);  // Use the dynamically allocated string
    
        
        cout << "---------------------------------------------\n";
        cout << "Enter email address: \n";
        cout << "---------------------------------------------\n";  
        getline(cin, *emailaddresss);  // Use the dynamically allocated string
       
        
        // Write the details to the file
        teacherFile << *teacherID << ',' << *teachername << ',' << *subjecttaught << ','  << *emailaddresss << '\n';

        cout << "---------------------------------------------\n";
        cout << "Person added successfully!" << endl;
        cout << "---------------------------------------------\n";
        
    }
    else
    {
        cout << "---------------------------------------------\n";
        cout << "Error opening teacher file." << endl;
        cout << "---------------------------------------------\n";
    }

    // Close the file
    teacherFile.close();
}





//classes.h********************************************************************************************************************************************

bool classes::checkclassname(const string name)//check from student file
{
    ifstream studentFile("student.txt");
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string studentID, studentName, emailaddress, AttendanceStatus, ClassSchedule, Classname; // Add more fields if needed

            getline(ss, studentID, ',');
            getline(ss, studentName, ',');
            getline(ss, emailaddress, ',');
            getline(ss, AttendanceStatus, ',');        
            getline(ss, ClassSchedule, ',');
            getline(ss, Classname, ',');
            // You can compare studentID with enteredid here
            if (Classname == name) {
                studentFile.close();
                return true;
            }
            ss.str("");
            ss.clear();
        }
        studentFile.close();
    }
    return false;
}

bool classes::checkclassname2(const string name)//check from classes.txt
{
    ifstream classFile("classes.txt");
    if (classFile.is_open())
    {
        string line;
        while (getline(classFile, line))
        {
            stringstream ss(line);
            string Classname, Teacher, listofstudents; // Add more fields if needed

            getline(ss, Classname, ',');
            getline(ss, Teacher, ',');
            getline(ss, listofstudents, ',');

            // You can compare studentID with enteredid here
            if (Classname == name) {
                classFile.close();
                return true;
            }
            ss.str("");
            ss.clear();
        }
        classFile.close();
    }
    return false;
}

string classes::generateAttendanceReport(const int& startDate, const int& endDate, const string classname)
{
    ifstream studentFile("student.txt");
    stringstream report;

    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string studentID, studentName, emailaddress, attendanceStatus, classSchedule, ClassName, date;

            getline(ss, studentID, ',');
            getline(ss, studentName, ',');
            getline(ss, emailaddress, ',');
            getline(ss, attendanceStatus, ',');
            getline(ss, classSchedule, ',');
            getline(ss, ClassName, ',');
            getline(ss, date, ',');

            try
            {
                // Convert the date from string to int

                if (ClassName == classname)
                {
                    int dateInt = stoi(date);

                    if ((dateInt >= startDate && dateInt <= endDate))
                    {
                        // Print or store the information as needed
                        report << "Student ID: " << studentID << ", Student Name: " << studentName
                            << ", Attendance Status: " << attendanceStatus << endl;
                    }
                }
            }
            catch (const invalid_argument& e)
            {
                // Handle conversion errors
                continue;
            }
        }

        studentFile.close();
    }
    else
    {
        cout << "---------------------------------------------\n";
        cerr << "Error opening student file." << endl;
        cout << "---------------------------------------------\n";
    }

    return report.str();
}

void classes::trackattendance(const string& studentid, const string& classname)
{
    ifstream studentFile("student.txt");
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string studentID, studentName, emailaddress, AttendanceStatus, ClassSchedule, Classname;

            getline(ss, studentID, ',');
            getline(ss, studentName, ',');
            getline(ss, emailaddress, ',');
            getline(ss, AttendanceStatus, ',');
            getline(ss, ClassSchedule, ',');
            getline(ss, Classname, ',');
            // You can compare studentID with enteredid here
            if (trim(studentID) == trim(studentid)) {
                if(trim(Classname) ==trim(classname))
                cout << studentName << " is " << AttendanceStatus << " in " << ClassSchedule << endl;
                studentFile.close();


            }
        }
        studentFile.close();
    }
}

string classes::trackexamgrade(const string classname, const string studentid)
{
    ifstream studentFile("Exam.txt");
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string StudentID, StudentName, Classname, ExamGrade; // Add more fields if needed

            getline(ss, StudentID, ',');
            getline(ss, StudentName, ',');
            getline(ss, Classname, ',');
            getline(ss, ExamGrade, ',');
            //Compare studentID with enteredid here
            if (trim(Classname) == trim(classname) && trim(StudentID) == trim(studentid))
            {
                studentFile.close();
                return ExamGrade;
            }
        }
        studentFile.close();
    }
    else
    {
        cout << "---------------------------------------------\n";
        cout << "can't not open file" << endl;
        cout << "---------------------------------------------\n";
    }
}

string classes::trackassignmentgrade(const string classname, const string studentid)
{
    ifstream studentFile("Assignment.txt");
    if (studentFile.is_open())
    {
        string line;
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            string StudentID, StudentName, Classname, AssignmentGrade; // Add more fields if needed

            getline(ss, StudentID, ',');
            getline(ss, StudentName, ',');
            getline(ss, Classname, ',');
            getline(ss, AssignmentGrade, ',');
            //Compare studentID with enteredid here
            if (trim(Classname) == trim(classname) && trim(StudentID) == trim(studentid))
            {
                studentFile.close();
                return AssignmentGrade;
            }
        }
        studentFile.close();
    }
    else
    {
        cout << "---------------------------------------------\n";
        cout << "can't not open file" << endl;
        cout << "---------------------------------------------\n";
    }
}

void classes::addStudent(const string studentname, const string Classname, const string Teachername)
{
    ifstream inFile("classes.txt");
    ofstream outFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open())
    {
        cout << "---------------------------------------------\n";
        cout << "Error opening files." << endl;
        cout << "---------------------------------------------\n";
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        string classname, teacher, students;

        getline(ss, classname, ',');
        getline(ss, teacher, ',');
        getline(ss, students);

        if (trim(classname) == trim(Classname) && trim(teacher) == trim(Teachername))
        {
            // Append the new student to the existing list with a comma if the list is not empty
            if (!students.empty())
            {
                students += ", ";
            }

            students += studentname;
        }

        // Write the line to the temporary file
        outFile << classname << ',' << teacher << ',' << students << '\n';
    }

    inFile.close();
    outFile.close();

    // Replace the original file with the temporary file
    if (remove("classes.txt") != 0)
    {
        cout << "---------------------------------------------\n";
        cout << "Error removing original file." << endl;
        cout << "---------------------------------------------\n";
        return;
    }

    if (rename("temp.txt", "classes.txt") != 0)
    {
        cout << "---------------------------------------------\n";
        cout << "Error renaming temporary file." << endl;
        cout << "---------------------------------------------\n";
        return;
    }

    cout << "---------------------------------------------\n";
    cout << "New student is added" << endl;
    cout << "---------------------------------------------\n";
}

void classes::printclass(const string classname, const string teachername)
{
    ifstream classFile("classes.txt");
    if (classFile.is_open())
    {
        string line;
        while (getline(classFile, line))
        {
            stringstream ss(line);
            string Classname, Teacher, students;

            getline(ss, Classname, ',');
            getline(ss, Teacher, ',');
            getline(ss, students);

            if (trim(Classname) == trim(classname) && trim(Teacher) == trim(teachername))
            {
                cout << "---------------------------------------------\n";
                cout << "List of Students: " << students << endl;
                cout << "---------------------------------------------\n";
                break;
            }
        }
        classFile.close();
    }
    else
    {
        cout << "---------------------------------------------\n";
        cout << "Error opening file." << endl;
        cout << "---------------------------------------------\n";
    }
}

void classes::removeStudent(const string studentname, const string classname, const string teachername)
{
    ifstream inFile("classes.txt");
    ofstream outFile("temp.txt");

    if (inFile.is_open() && outFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            stringstream ss(line);
            string Classname, Teacher, students;

            getline(ss, Classname, ',');
            getline(ss, Teacher, ',');
            getline(ss, students);

            if (trim(Classname) == trim(classname) && trim(Teacher) == trim(teachername))
            {
                // Find the student in the list
                size_t pos = students.find(trim(studentname));
                while (pos != string::npos)
                {
                    // Check if there is a preceding comma
                    if (pos > 0 && students[pos - 1] == ',')
                    {
                        // Erase the comma along with the student
                        students.erase(pos - 1, trim(studentname).length() + 1);
                    }
                    else
                    {
                        // Erase the student without a leading comma
                        students.erase(pos, trim(studentname).length());
                    }

                    // Find the next occurrence of the student
                    pos = students.find(trim(studentname), pos);
                }
            }

            // Write the modified line to the temporary file
            outFile << Classname << ',' << Teacher << ',' << students << '\n';
        }

        inFile.close();
        outFile.close();

        // Remove the original file and rename the temporary file
        remove("classes.txt");
        rename("temp.txt", "classes.txt");
        cout << "---------------------------------------------\n";
        cout << "Student removed!" << endl;
        cout << "---------------------------------------------\n";
    }
    else
    {
        cout << "Error opening files." << endl;
    }
}

void classes::createClass(const string classname, const string teachername)
{
    ofstream classFile("classes.txt", ios::app);

    if (classFile.is_open())
    {
        classFile << classname << ',' << teachername << ',' << '\n';

        cout << "Class created successfully!" << endl;
        cout << "---------------------------------------------\n";

        classFile.close();
    }
    else
    {
        cout << "Error opening classes file." << endl;
        cout << "---------------------------------------------\n";
    }
}




//assignment.h********************************************************************************************************************************************
void assignment::submitassginment(const string& subject, const string grade, const string studentid, const string name)
{
    ofstream studentFile("Assignment.txt", ios::app);

    if (studentFile.is_open())
    {
        string StudentID, StudentName, Classname, AssignmentGrade;

        // Take input for the new person's details
        
    
        StudentID = studentid;
        StudentName = name;
        Classname = subject;  // Assuming subject is the class name
        AssignmentGrade = grade;
    

        studentFile << '\n' << StudentID << ',' << StudentName << ',' << Classname << ',' << AssignmentGrade << endl;
        cout << "---------------------------------------------\n";
        cout << "Grade entered successfully!" << endl;
        cout << "---------------------------------------------\n";
    }
    else
    {
        cout << "---------------------------------------------\n";
        cout << "Error opening student file." << endl;
        cout << "---------------------------------------------\n";
    }

    // Close the file
    studentFile.close();
}


//Exam.h********************************************************************************************************************************************
void exam::enterexamgrade(const string subject, const string grade, const string studentid, const string name)//use in class case 2
{
    //this enterexamgrade function is used in class case 2
    ofstream studentFile("Exam.txt", ios::app);

    if (studentFile.is_open())
    {
        string StudentID, StudentName, Classname, ExamGrade;

        
        StudentID = studentid;
        StudentName = name;
            Classname = subject;
            ExamGrade = grade;

        

        studentFile << StudentID << ',' << StudentName << ',' << Classname << ',' << ExamGrade;
        cout << "---------------------------------------------\n";
        cout << "Grade entered successfully!" << endl;
        cout << "---------------------------------------------\n";
    }
    else
    {
        cout << "---------------------------------------------\n";
        cout << "Error opening student file." << endl;
        cout << "---------------------------------------------\n";
    }

    // Close the file
    studentFile.close();
}