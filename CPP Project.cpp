//Shadan Khan DS SC6/SC1 project
#include <iostream>
#include <stdio.h>
using namespace std;

class Student
{
    //create objects type student
    //student constructer ==> parameters -> (name, ID, GPA)
public:
    int ID;
    string name;
    double GPA;
    Student *next;

    Student(Student *next, string name, int ID, double GPA)
    {
        this->name = name;
        this->ID = ID;
        this->GPA = GPA;
        this->next = next;
    }
    //getters
    string getStudentName()
    {
        return name;
    }
    int getStudentID()
    {
        return ID;
    }
    double getStudentGPA()
    {
        return GPA;
    }
    Student *getNext()
    {
        return next;
    }
    //setters
    void setStudentName(string name)
    {
        this->name = name;
    }

    void setStudentID(int ID)
    {
        this->ID = ID;
    }

    void setStudentGPA(double GPA)
    {
        this->GPA = GPA;
    }
    void setNext(Student *next)
    {
        this->next = next;
    }
};

class StudentList
{
private:
    Student *head;

public:
    StudentList()
    {
        head = NULL;
    }
    //getter for head node
    Student *getHead()
    {
        return head;
    }
    int getSize()
    {
        int i = 0;
        Student *temp = head;
        while (temp != NULL)
        {
            i++;
            temp = temp->getNext();
        }
        return i;
    }

    Student *ADDSTUDENT(string name, int ID, double GPA)
    {
        //enter details for a new student
        if(head==NULL){
            head = new Student(head, name, ID, GPA);
        }else
        {
            Student *temp = head;
            while (temp->getNext() != NULL)
            {
                temp = temp->getNext();
            }
            Student *newStudent = new Student(temp->getNext(), name, ID, GPA);
            temp->setNext(newStudent);
        }
        return head;
    }
    void STUDENTINFO(int ID)
    {
        //search for student through id
        //if found, print their record
        //if not print "There is no record of this student in this system"
        Student *temp = head;
        bool f = false;
        while (temp != NULL)
        {
            if (temp->getStudentID() == ID)
            {
                cout << "Student name= " << temp->getStudentName();
                cout << "\nStudent ID= " << temp->getStudentID();
                cout << "\nStudent GPA= " << temp->getStudentGPA() << endl;
                f = true;
            }
            temp = temp->getNext();
        }
        if (f == false)
            cout << "There is no record of this student in the system." << endl;
    }
    void DELETESTUDENT(int ID)
    {
        //iterate through my linked list and delete student(node)
        //if not found, print "There is no student with the id "#######" in the system"
        Student *temp = head;
        Student *node2Del;
        bool f = false;
        while (temp->getNext() != NULL)
        {
            if (temp->getNext()->getStudentID() == ID)
            {
                node2Del = temp->getNext();
                temp->setNext(node2Del->getNext());
                free(node2Del);
                f = true;
            }
            else
                temp = temp->getNext();
        }
        if (f == false)
        {
            cout << "There is no student with the ID " << ID << " in the system." << endl;
        }
        else
            cout << "The student record was deleted successfully." << endl;
    }

    void FINDLARGEST()
    {
        //print information of student with highest gpa
        double max = 0;
        int maxID;
        Student *temp = head;
        temp = head->getNext();
        while (temp != NULL)
        {
            if (temp->getStudentGPA() > max)
            {
                max = temp->getStudentGPA();
                maxID = temp->getStudentID();
            }
            temp = temp->getNext();
        }
        cout << "The highest GPA is " << max;
        cout << "\nStudent info: \n";
        STUDENTINFO(maxID);
    }
    void PRINTLIST()
    {
        //print all students records
        Student *temp = head;
        int i = 1;
        while (temp != NULL)
        {
            cout << i << "- Student ID= " << temp->getStudentID() << "\nstudent name= " << temp->getStudentName() << "\nstudent GPA= " << temp->getStudentGPA() << endl;
            cout << "\n----------------------\n";
            temp = temp->getNext();
            i++;
        }
    }
    void REVERSEPRINTLIST(Student *node, int c)
    {
        //printlist but in reverse *USING RECURSION*
        int i = c;
        if (node != NULL)
        {
            REVERSEPRINTLIST(node->getNext(), ++i);
            cout << i << "- Student Name= " << node->getStudentName() << "\nStudent ID= " << node->getStudentID() << "\nstudent GPA= " << node->getStudentGPA();
            cout << "\n----------------------\n";
            
        }
    }
};

//main class

int main()
{
    int n, id;
    string name, firstName, lastName;
    double gpa;
    StudentList *stu = new StudentList();

    //adding students
    stu->ADDSTUDENT("Sara Ahmad", 1026643, 3.9);
    stu->ADDSTUDENT("Raghad Jameel", 1034271, 4.5);
    stu->ADDSTUDENT("Raneem Mohammad", 1042114, 3.4);
    stu->ADDSTUDENT("Yara Ali", 1092323, 4.7);
    

    cout << "\t\t\t*********************************" << endl;
    cout << "\t\t\t****STUDENT MANAGEMENT SYSTEM****" << endl;
    cout << "\t\t\t*********************************" << endl;
    do
    {
        cout << "1--->Press '1' to ADDSTUDENT" << endl;
        cout << "2--->Press '2' to STUDENTINFO" << endl;
        cout << "3--->Press '3' to DELETESTUDENT" << endl;
        cout << "4--->Press '4' to FINDLARGEST" << endl;
        cout << "5--->Press '5' to PRINTLIST" << endl;
        cout << "6--->Press '6' to REVERSEPRINTLIST" << endl;
        cout << "7--->Press '7' to exit" << endl;
        cin >> n;

        switch (n){
        case 1:
            cout << "Enter student's name: ";
            cin >> firstName >> lastName;
            cout << "Enter student's ID: ";
            cin >> id;
            cout << "Enter student's GPA: ";
            cin >> gpa;
            name = firstName + " " + lastName;
            stu->ADDSTUDENT(name, id, gpa);
            cout << "The student record was added successfully\n";
            break;
        case 2:
            cout << "Enter student's ID: ";
            cin >> id;
            stu->STUDENTINFO(id);
            break;
        case 3:
            cout << "Enter student's ID: ";
            cin >> id;
            stu->DELETESTUDENT(id);
            break;
        case 4:
            stu->FINDLARGEST();
            break;
        case 5:
            stu->PRINTLIST();
            break;
        case 6:
            stu->REVERSEPRINTLIST(stu->getHead(), 0);
            break;
        case 7:
            cout << "Exiting...";
            break;
        }
    } while (n != 7);

    return 0;
}
