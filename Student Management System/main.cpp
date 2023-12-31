#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include "basic.h"
#include "student.h"
#include "teacher.h"
#include "classes.h"
#include "Assignment.h"
#include "Exam.h"

using namespace std;

int main()
{
    int choice= 0;
   
    while(choice == 0)
    {
        
        cout << "******************************\n";
        cout << "*        Main Menu         *\n";
        cout << "******************************\n";
        cout << "Select your option" << endl;
        cout << "1. Student" << endl;
        cout << "2. Teacher" << endl;
        cout << "3. Class" << endl;
        cout << "******************************\n";
        cin >> choice;



        switch (choice)
        {

        case 1://Student
        {
            student student;
            string studentid;
            cout << "---------------------------------------------\n";
            cout << "enter student id or enter y to add a student" << endl;
            cout << "---------------------------------------------\n";
            cin >> studentid;
            if (studentid != "y")
            {

                if (student.checkstudentid(studentid))
                {
                   student.getName(studentid);
                   // Enter student menu if id is valid
                   cout << "******************************\n";
                   cout << "*        Student Menu         *\n";
                   cout << "******************************\n";
                   cout << "1. Track attendance\n";
                   cout << "2. Submit an assignment\n";
                   cout << "3. Track grade\n";
                   cout << "4. Calculate average class grade\n";
                   cout << "5. Update schedule\n";
                   cout << "6. Mark attendance\n";
                   cout << "7. Update student information\n";
                   cout << "8. Back to main menu\n";
                   cout << "******************************\n";


                   int purpose;
                   cin >> purpose;

                   switch (purpose) {
                   case 1: // Track attendance
                   {

                       student.trackattendance(studentid);

                       break;
                   }

                   case 2: // Submit assignment
                   {
                       assignment homework;
                       string subject;
                       cout << "---------------------------------------------\n";
                       cout << "Enter the subject you want to submit" << endl;
                       cout << "---------------------------------------------\n";
                       cin >> subject;
                       string grade;
                       cout << "---------------------------------------------\n";
                       cout << "Enter the grade you received" << endl;
                       cout << "---------------------------------------------\n";
                       cin >> grade;
                       string Name = student.getName(studentid);

                       homework.submitassginment(subject, grade, studentid, Name);
                       break;
                   }

                   case 3://Track grade
                   {
                       cout << "---------------------------------------------\n";
                       cout << "1.Track exam grade" << endl;
                       cout << "---------------------------------------------\n";
                       cout << "2.Track assignment grade" << endl;
                       cout << "---------------------------------------------\n";
                       int selecttrack;
                       cin >> selecttrack;
                       string classname;
                       cout << "---------------------------------------------\n";
                       cout << "Enter class name" << endl;
                       cout << "---------------------------------------------\n";
                       cin >> classname;
                       if (selecttrack == 1)//Track exam grade
                       {
                           cout << "---------------------------------------------\n";
                           cout << "The exam grade is: " << student.trackexamgradee(studentid, classname) << endl;
                           cout << "---------------------------------------------\n";
                       }
                       else if (selecttrack == 2)//Track assignment grade
                       {
                           cout << "---------------------------------------------\n";
                           cout << "The assignment grade is: " << student.trackassignmentgradee(studentid, classname) << endl;
                           cout << "---------------------------------------------\n";
                       }
                       else
                       {
                           cout << "---------------------------------------------\n";
                           cout << "Invalid entry" << endl;
                           cout << "---------------------------------------------\n";
                       }
                       break;
                   }

                   case 4://Calculate class grade
                   {
                       cout << "---------------------------------------------\n";
                       cout << "1.Calculate class average exam grade" << endl;
                       cout << "---------------------------------------------\n";
                       cout << "2.Calculate class average assignment grade" << endl;
                       cout << "---------------------------------------------\n";
                       int choice;
                       cin >> choice;
                       cout << "---------------------------------------------\n";
                       cout << "Enter class name(Hist for history, Chem for chemistry):" << endl;
                       cout << "---------------------------------------------\n";
                       string classname;
                       cin >> classname;
                       if (choice == 1)//calculate exam grade
                       {
                           cout << "---------------------------------------------\n";
                           cout << "The exam average grade is: " << student.calculatclassexamgrade(studentid, classname) << endl;
                           cout << "---------------------------------------------\n";
                       }
                       else if (choice == 2)//calculate assignment grade
                       {
                           cout << "---------------------------------------------\n";
                           cout << "The assignment average grade is: " << student.calculatclassassignmentgrade(studentid, classname) << endl;
                           cout << "---------------------------------------------\n";
                       }
                       else
                       {
                           cout << "---------------------------------------------\n";
                           cout << "Invalid entry" << endl;
                           cout << "---------------------------------------------\n";
                       }
                       break;
                   }

                   case 5://Update schedule
                   {
                       cout << "------------------------------------------------------------------------\n";
                       cout << "Enter the new schedule(day in a week) \n";
                       cout << "------------------------------------------------------------------------\n";
                       string newschedule, todaysdate;
                       cin >> newschedule;

                       cout << "------------------------------------------------------------------------\n";
                       cout << "Enter the date(in the format of YYYYMMDD) of the new schedule \n";
                       cout << "------------------------------------------------------------------------\n";
                       cin >> todaysdate;
                       student.updateSchedule(newschedule, studentid, todaysdate);
                       break;
                   }

                   case 6://Mark attendance
                   {
                       cout << "------------------------------------------------------------------------\n";
                       cout << "Enter the date you want to mark(in YYYYMMDD format)\n";
                       cout << "------------------------------------------------------------------------\n";
                       string enterdatedate, status;
                       cin >> enterdatedate;
                       cout << "------------------------------------------------------------------------\n";
                       cout << "Enter the status you want to mark(present, absent, or tardy)\n";
                       cout << "------------------------------------------------------------------------\n";
                       cin >> status;
                       student.Markattendence(studentid, enterdatedate, status);
                       break;
                   }

                   case 7://Update student information
                   {
                       string newemail;
                       cout << "------------------------------------------------------------------------\n";
                       cout << "Enter new email address:" << endl;
                       cout << "------------------------------------------------------------------------\n";
                       cin >> newemail;

                       student.updatestudentinfomation(studentid, newemail);
                       break;
                   }

                   case 8://back to main menu
                   {
                       break;
                   }

                   default:
                   {
                       cout << "---------------------------------------------\n";
                       cout << "Invalid choice in the student menu" << endl;
                       cout << "---------------------------------------------\n";
                       break;
                   }
                   }
                }
                else
                {
                    cout << "---------------------------------------------\n";
                    cout << "Student not found.\n" ;
                    cout << "---------------------------------------------\n";
                    break;
                }



             
            }
            else
            {
                student.addastudent();
                break;
            }

            break;
        }




        case 2://Teacher
        {
            teacher* newteacher = new teacher;
          
            string teacherid;
            cout << "---------------------------------------------\n";
            cout << "enter teacher id or enter y to add a teacher\n";
            cout << "---------------------------------------------\n";
            cin >> teacherid;

            if (teacherid != "y")
            {


                if (newteacher->checkteacherid(teacherid))//check if teacher id is valid
                {
                    newteacher->getName(teacherid);//print teacher name and id

                    //enter student menu if id is valid
                    cout << "******************************\n";
                    cout << "*        Teacher Menu         *\n";
                    cout << "******************************\n";
                    cout << "1. Enter grade\n";
                    cout << "2. Calculate overall grade\n";
                    cout << "3. Track grade\n";
                    cout << "4. Track attendance\n";
                    cout << "5. Mark attendance\n";  
                    cout << "6. Back to main menu\n";
                    cout << "******************************\n";

                    int purpose;
                    cin >> purpose;

                    switch (purpose)
                    {
                    case 1://Enter grade
                    {
                        cout << "---------------------------------------------\n";
                        cout << "1.Enter exam grade\n";
                        cout << "---------------------------------------------\n";
                        cout << "2.Enter assignment grade\n";
                        cout << "---------------------------------------------\n";
                        int selectenter;
                        cin >> selectenter;
                        cout << "---------------------------------------------\n";
                        cout << "Enter class name\n";
                        cout << "---------------------------------------------\n";
                        string classname;
                        cin >> classname;
                        if (selectenter == 1)//enter exam grade
                        {
                            cout << "---------------------------------------------\n";
                            cout << "Enter student's id\n";
                            cout << "---------------------------------------------\n";
                            string studentid;
                            cin >> studentid;
                            
                            cout << "---------------------------------------------\n";
                            cout << "Enter student's grade, range 0 - 100\n";
                            cout << "---------------------------------------------\n";
                            string studentgrade;
                            cin >> studentgrade;
                            newteacher->enterexamgrade(studentid, studentgrade, classname);//enter exam grade
                        }
                        else//enter assignment grade
                        {
                            cout << "---------------------------------------------\n";
                            cout << "Enter student's id\n";
                            cout << "---------------------------------------------\n";
                            string studentid;
                            cin >> studentid;
                            cout << "---------------------------------------------\n";
                            cout << "Enter student's letter grade, range 0 - 100\n";
                            cout << "---------------------------------------------\n";
                            string studentgrade;
                            cin >> studentgrade;
                            newteacher->enterassignmentgrade(studentid, studentgrade, classname);//enter assignment grade
                        }
                        break;
                    }

                    case 2://Calculate overall grade
                    {
                        cout << "---------------------------------------------\n";
                        cout << "1.Track overall exam grade\n";
                        cout << "---------------------------------------------\n";
                        cout << "2.Track overall assignment grade\n";
                        cout << "---------------------------------------------\n";
                        int choice;
                        cin >> choice;
                        cout << "---------------------------------------------\n";
                        cout << "Enter the calss you want to calculate\n";
                        cout << "---------------------------------------------\n";
                        string classname;
                        cin >> classname;
                        if (choice == 1)
                        {
                            cout << "---------------------------------------------\n";
                            cout << "th overall Exam grade of the class is: " << newteacher->calculateoverallexamgradefortheclass(classname) << endl;//calculate overall exam grade for the class
                            cout << "---------------------------------------------\n";
                        }
                        else if (choice == 2)
                        {
                            cout << "---------------------------------------------\n";
                            cout << "the overall assignment grade of the class is: " << newteacher->calculateoverallassignmentgradefortheclass(classname) << endl;//calculate overall assignment grade for the class
                            cout << "---------------------------------------------\n";
                        }
                        break;
                    }
                    case 3://Track grade
                    {
                        cout << "---------------------------------------------\n";
                        cout << "1. Track exam grade" << endl;
                        cout << "---------------------------------------------\n";
                        cout << "2. Track assignment grade" << endl;
                        cout << "---------------------------------------------\n";
                        int selecttrack;
                        cin >> selecttrack;

                        cout << "---------------------------------------------\n";
                        cout << "Enter the student's id you want to track " << endl;
                        cout << "---------------------------------------------\n";
                        string studentid;
                        cin >> studentid;

                        cout << "---------------------------------------------\n";
                        cout << "Enter the class name " << endl;
                        cout << "---------------------------------------------\n";
                        string classname;
                        cin >> classname;

                        if (selecttrack == 1)//Track exam grade
                        {
                            cout << "---------------------------------------------\n";
                            cout << "The exam grade is: " << newteacher->trackexamgradee(studentid, classname) << endl;
                            cout << "---------------------------------------------\n";
                        }
                        else if (selecttrack == 2)//Track assignment grade
                        {
                            cout << "---------------------------------------------\n";
                            cout << "The assignment grade is: " << newteacher->trackassignmentgradee(studentid, classname) << endl;
                            cout << "---------------------------------------------\n";
                        }
                        else
                        {
                            cout << "---------------------------------------------\n";
                            cout << "Invalid entry" << endl;
                            cout << "---------------------------------------------\n";
                        }
                        break;
                    }


                    case 4://Track attendance
                    {
                        cout << "---------------------------------------------\n";
                        cout << "Enter the student's id you want to track" << endl;
                        cout << "---------------------------------------------\n";
                        string studentid;
                        cin >> studentid;
                        newteacher->trackattendance(studentid);
                        break;
                    }

                    case 5://Mark attendance
                    {
                        string enterdatedate, status, studentid;
                        cout << "------------------------------------------------------------------------\n";
                        cout << "Enter the date you want to mark(in YYYYMMDD format) \n";
                        cout << "------------------------------------------------------------------------\n";
                        cin >> enterdatedate;

                        cout << "------------------------------------------------------------------------\n";
                        cout << "Enter the student id\n";
                        cout << "------------------------------------------------------------------------\n";
                        cin >> studentid;

                        cout << "------------------------------------------------------------------------\n";
                        cout << "Enter the status you want to mark(present, absent, or tardy)\n";
                        cout << "------------------------------------------------------------------------\n";
                        cin >> status;

                        newteacher->Markattendence(studentid, enterdatedate, status);
                        break;
                    }

                    case 6://back to main menu
                    {
                        break;
                    }

                    default:
                    {
                        cout << "---------------------------------------------\n";
                        cout << "Invalid choice in teacher menu" << endl;
                        cout << "---------------------------------------------\n";
                        break;
                    }

                    }

                    break;// program for student
                }
                else
                {
                    cout << "---------------------------------------------\n";
                    cout << "Invalid teacher id. \n";
                    cout << "---------------------------------------------\n";
                }
                
                break;
            }
            else
            {
                newteacher->addateacher();
                delete newteacher;
                break;
                }
        }




        case 3://Class
        {
            classes classs;
            string classname;




            cout << "******************************\n";
            cout << "*        Class Menu          *\n";
            cout << "******************************\n";

            cout << "1.Track attendance(based on class selected)\n" ;
            cout << "2.Add a grade\n";
            cout << "3.Generate attendance report\n" ;
            cout << "4.Track grade\n";
            cout << "5.Manange student of a class\n";   
            cout << "6.Back to main menu\n";
            cout << "******************************\n";

            int purpose;
            cin >> purpose;

            switch (purpose)
            {
            case 1://Track attendance
            {

                cout << "---------------------------------------------\n";
                cout << "enter class name : ";
                cout << "---------------------------------------------\n";
                cin >> classname;
                if (classs.checkclassname(classname))
                {
                    cout << "---------------------------------------------\n";
                    cout << "Enter the student's id you want to track" << endl;
                    cout << "---------------------------------------------\n";
                    string studentid;
                    cin >> studentid;
                    classs.trackattendance(studentid, classname);
                }
                else
                {
                    cout << "---------------------------------------------\n";
                    cout << "Class not found \n" ;
                    cout << "---------------------------------------------\n";
                }
                break;

            }

            case 2://Add an exam grades
            {
                
                exam exam;
             
                string grade,studentid,name, classname;
            
                cout << "---------------------------------------------\n";
                cout << "Enter student's id: \n" ;
                cout << "---------------------------------------------\n";
                cin >> studentid;
               
                cin.ignore();
                cout << "---------------------------------------------\n";
                cout << "Enter student name: \n" ;
                cout << "---------------------------------------------\n";
                getline(cin, name);             

                cout << "---------------------------------------------\n";
                cout << "enter class name : \n";
                cout << "---------------------------------------------\n";
                cin >> classname;

                cout << "---------------------------------------------\n";
                cout << "Enter exam grade: \n";
                cout << "---------------------------------------------\n";              
                cin >> grade;
                
               
                exam.enterexamgrade(classname, grade, studentid, name);
                break;
            }



            case 3://Generate attendance report for specific class
            {
                cout << "---------------------------------------------\n";
                cout << "enter class name :" << endl;
                cout << "---------------------------------------------\n";
                cin >> classname;
                if (classs.checkclassname(classname))
                {
                    int startDate, endDate;
                    cout << "---------------------------------------------\n";
                    cout << "Enter star date in YYYYMMDD format" << endl;
                    cout << "---------------------------------------------\n";
                    cin >> startDate ;

                    cout << "---------------------------------------------\n";
                    cout << "Enter end date in YYYYMMDD format" << endl;
                    cout << "---------------------------------------------\n";
                    cin >> endDate;
                    cout << classs.generateAttendanceReport(startDate, endDate, classname) << endl;
                }
                break;

            }

            case 4://Track grade
            {
                cout << "---------------------------------------------\n";
                cout << "enter class name :" << endl;
                cout << "---------------------------------------------\n";
                cin >> classname;
                if (classs.checkclassname(classname))
                {
                    cout << "---------------------------------------------\n";
                    cout << "1.Track exam grade" << endl;
                    cout << "---------------------------------------------\n";
                    cout << "2.Track assignment grade" << endl;
                    cout << "---------------------------------------------\n";
                    int selecttrack;
                    cin >> selecttrack;

                    cout << "---------------------------------------------\n";
                    cout << "enter the student's id you want ot track" << endl;
                    cout << "---------------------------------------------\n";
                    string studentid;
                    cin >> studentid;

                    if (selecttrack == 1)//Track exam grade
                    {
                        cout << "---------------------------------------------\n";
                        cout << "The exam grade is: " << classs.trackexamgrade(classname, studentid) << endl;
                        cout << "---------------------------------------------\n";
                    }
                    else if (selecttrack == 2)//Track assignment grade
                    {
                        cout << "---------------------------------------------\n";
                        cout << "The assignment grade is: " << classs.trackassignmentgrade(classname, studentid) << endl;
                        cout << "---------------------------------------------\n";
                    }
                    else
                    {
                        cout << "---------------------------------------------\n";
                        cout << "Invalid entry" << endl;
                        cout << "---------------------------------------------\n";
                    }
                }
                else
                {
                    cout << "---------------------------------------------\n";
                    cout << "Class not found" << endl;
                    cout << "---------------------------------------------\n";
                }

                break;
            }

            case 5://Manange student of a class
            {

                cout << "---------------------------------------------\n";
                cout << "1.add a student to a class" << endl;//yes
                cout << "2.remove a student from a class" << endl;  //yes   
                cout << "3.add a class" << endl;//
                cout << "---------------------------------------------\n";
                int choice;
                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    cout << "---------------------------------------------\n";
                    cout << "enter class name :" << endl;
                    cout << "---------------------------------------------\n";
                    cin >> classname;
                    cin.ignore();
                    if (classs.checkclassname2(classname))
                    {
                       
                        string newStudent,teachername;
                        cout << "---------------------------------------------\n";
                        cout << "Enter the name of the teacher: \n";
                        cout << "---------------------------------------------\n";
                        getline(cin, teachername);
                        cout << "---------------------------------------------\n";
                        cout << "Enter the name of the student to add: \n";
                        cout << "---------------------------------------------\n";
                        getline(cin, newStudent);
                       
                        classs.addStudent(newStudent, classname,teachername);
                        
                    }
                    else
                    {
                        cout << "---------------------------------------------\n";
                        cout << "Class not found" << endl;
                        cout << "---------------------------------------------\n";
                    }
                    break;

                }

                case 2:
                {
                    string studentname, teachername;
                    cout << "---------------------------------------------\n";
                    cout << "enter class name :" << endl;
                    cout << "---------------------------------------------\n";
                    cin >> classname;
                    cin.ignore();  // Clear the newline character from the buffer

                    cout << "---------------------------------------------\n";
                    cout << "Enter the name of the teacher: \n";
                    cout << "---------------------------------------------\n";
                    getline(cin, teachername);

                    if (classs.checkclassname2(classname))
                    {
                        classs.printclass(classname, teachername);
                        cout << "---------------------------------------------\n";
                        cout << "Enter the name of the student to delete: \n";
                        cout << "---------------------------------------------\n";
                        getline(cin, studentname);

                        classs.removeStudent(studentname, classname, teachername);
                    }
                    else
                    {
                        cout << "---------------------------------------------\n";
                        cout << "Class not found" << endl;
                        cout << "---------------------------------------------\n";
                    }
                    break;
                }

                case 3:
                {
                    string classname, teachername;
                    cout << "---------------------------------------------\n";
                    cout << "Enter the class you want to create: " << endl;
                    cout << "---------------------------------------------\n";
                    cin >> classname;
                    cin.ignore();
                    cout << "---------------------------------------------\n";
                    cout << "Enter the teacher name for the new class: " << endl;
                    cout << "---------------------------------------------\n";
                    getline(cin, teachername);
                  classs.createClass(classname, teachername);
                    break;
                }

                default:
                {
                    cout << "---------------------------------------------\n";
                    cout << "Invalid choice in create class menu" << endl;
                    cout << "---------------------------------------------\n";
                    break;
                }
                }
                break;
            }

            case 6://back to main menu
            {
                break;
            }

            default:
            {
                cout << "---------------------------------------------\n";
                cout << "Invalid choice in class menu" << endl;
                cout << "---------------------------------------------\n";
                break;
            }
            }

            break;
        }

        default:
        {
            cout << "---------------------------------------------\n";
            cout << "Invalid entry in main menu" << endl;
            cout << "---------------------------------------------\n";
            break;
        }
        break;
        }

        cout << "---------------------------------------------\n";
        cout << "Enter 0 to back to main menu, or any other key to quit the program." << endl;
        cout << "---------------------------------------------\n";
        cin >> choice;
    }
        
    return 0;
}

    
   

