#include <iostream>
#include <iomanip>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string gender;
    string address;
    string phonenumber;

public:
    Person(){};
    Person(string name, int age, string gender, string address, string phonenumber)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->address = address;
        this->phonenumber = phonenumber;
    };

    //  set information
    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setGender(string gender)
    {
        this->gender = gender;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    void setPhonenumber(string phonenumber)
    {
        this->phonenumber = phonenumber;
    }

    //  get information
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    string getGender()
    {
        return gender;
    }
    string getAddress()
    {
        return address;
    }
    string getPhoneNumber()
    {
        return phonenumber;
    }
    void input()
    {
        string name;
        int age;
        string gender;
        string address;
        string phoneNumber;
        cout << "Full Name : ";
        getline(cin, name);
        cout << "Age : ";
        cin >> age;
        cout << "Gender : ";
        cin.get();
        getline(cin, gender);
        cout << "Address : ";
        getline(cin, address);
        cout << "Phone Number : ";
        getline(cin, phoneNumber);
        setName(name);
        setAge(age);
        setGender(gender);
        setAddress(address);
        setPhonenumber(phoneNumber);
    }
    void update()
    {
        string name;
        int age;
        string gender;
        string address;
        string phoneNumber;
        cout << "Name : " << getName() << "  Update To : ";
        getline(cin, name);
        cout << "Age : " << getAge() << "  Update To : ";
        cin >> age;
        cout << "Gender : " << getGender() << "  Update To : ";
        cin.get();
        getline(cin, gender);
        cout << "Address : " << getAddress() << "  Update To : ";
        getline(cin, address);
        cout << "Phone Number : " << getPhoneNumber() << "  Update To : ";
        getline(cin, phoneNumber);
        setName(name);
        setAge(age);
        setGender(gender);
        setAddress(address);
        setPhonenumber(phoneNumber);
    }
    void output()
    {
        cout << "Name : " << getName() << endl;
        cout << "Age : " << getAge() << endl;
        cout << "Gender : " << getGender() << endl;
        cout << "Address : " << getAddress() << endl;
        cout << "Phone Number : " << getPhoneNumber() << endl;
    }
};
class Student : public Person
{
protected:
    int studentId;
    string className;

public:
    float scores[5];

    float findAverage()
    {
        float sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum = sum + scores[i];
        }
        return (sum / 5);
    }
    void setStudentId(int studentId)
    {
        this->studentId = studentId;
    }
    void IdAfterDelete(int studentId)
    {
        studentId = this->studentId;
    }
    void setClassName(string className)
    {
        this->className = className;
    }
    // get information
    int getStudentId()
    {
        return studentId;
    }
    string getClassName()
    {
        return className;
    }
    Student(){};
    Student(string name, int age, string gender, string address, string phonenumber, int studentId, string className) : Person(getName(), getAge(), getGender(), getAddress(), getPhoneNumber())
    {
        this->studentId = studentId;
        this->className = className;
    }
    void update()
    {
        string ClassName;
        cout << "Class Name : " << getClassName() << "  Update To : ";
        cin.get();
        getline(cin, ClassName);
        Person ::update();
        cout << "IN PUT SCORE HERE : " << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << " : " << scores[i] << "  Update To : ";
            cin >> scores[i];
        }
        setStudentId(studentId);
    }

    void input(int index, Student student[], int n, bool IsTrue)
    {
        int StudentID;
        string ClassName;
        do
        {
            IsTrue = false;
            cout << "Student ID : ";
            cin >> StudentID;
            for (int i = 0; i < index + 1; i++)
            {
                if (student[i].getStudentId() == StudentID)
                {
                    cout << "This ID Already Enroll....!" << endl;
                    IsTrue = true;
                }
            }
        } while (IsTrue == true);
        cout << "Class Name : ";
        cin.get();
        getline(cin, ClassName);

        Person ::input();
        cout << "IN PUT SCORE HERE : " << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << " : ";
            cin >> scores[i];
        }
        setStudentId(StudentID);
        setClassName(ClassName);
    }

    void output()
    {
        cout << "Student ID :" << getStudentId() << endl;
        cout << "Class Name : " << getClassName() << endl;
        Person::output();
        cout << "Average Score : " << findAverage();
    }
};

void enter();
void ascending(Student student[], int index);
void descending(Student student[], int index);
void averageDescending(Student student[], int index);

int main()
{
    system("cls");
    int n;
    int option;
    int index = 0;
    int searchId;
    string searchName;
    bool isTrue = false;
    int topScore;
    int idAfterDelete = 0;
    int Dindex;
    int DeleteNum = 0;

    do
    {
        cout << "Enter Number Of Student : ";
        cin >> n;
        if (n <= 0)
        {
            cout << "The Number Of student Should be > 0 " << endl;
        }
    } while (n <= 0);
    Student student[n];
    do
    {
        string optionString;
        cout << "\na.Enroll the student into system " << endl;
        cout << "b.Update the student's information " << endl;
        cout << "c.Search for the student " << endl;
        cout << "d.Delete the student " << endl;
        cout << "e.Display all the student information " << endl;
        cout << "f.Exit Program ....!" << endl;
        cout << "Choose a option (a-f) : ";
        cin >> optionString;
        if (optionString == "a")
        {
            option = 1;
        }
        else if (optionString == "b")
        {
            option = 2;
        }
        else if (optionString == "c")
        {
            option = 3;
        }
        else if (optionString == "d")
        {
            option = 4;
        }
        else if (optionString == "e")
        {
            option = 5;
        }
        else if (optionString == "f")
        {
            option = 6;
        }
        else
        {
            option = 10;
        }
        switch (option)
        {
        case 1:
            system("cls");
            cout << "\n============================||Enroll The Student into System ||============================\n"
                 << endl;
            if (index < n)
            {
                student[index].input(index, student, n, isTrue);
                // cout <<"index befor : "<<index<<endl;
                index++;
                cout << "\f" << index << " student has been enrolled into the system." << endl;
                // cout <<"Index After : "<< index<<endl;
            }
            else
            {
                cout << "System was full....!! You Can't Enroll At The Moment !!....\n"
                     << endl;
            }
            break;
        case 2:
            system("cls");
            if (index <= 0)
            {
                cout << "\nDon't have student in system ......!! Please Check Again!!.......\n"
                     << endl;
            }
            else
            {
                cout << "============================|| Update The  Student's Information ||============================" << endl;
                cout << "Enter Student ID : ";
                cin >> searchId;
                for (int i = 0; i < index; i++)
                {
                    if (student[i].getStudentId() == searchId)
                    {
                        isTrue = true;
                        student[i].update();
                    }
                }
                if (!isTrue)
                {
                    cout << "Student With ID : " << searchId << " Not Found...!";
                }
                else
                {
                    cout << "Successfully Update Student Information ! ";
                }
                isTrue = false;
            }
            cout << endl;
            enter();
            break;
        case 3:
            system("cls");
            if (index <= 0)
            {
                cout << "\nDon't have student in system ......!! Please Check Again!!.......\n"
                     << endl;
            }
            else
            {
                if (index == 1)
                {
                    cout << endl;
                    student[0].output();
                    cout << "\n\nIn system have only 1 student \n"
                         << endl;
                }
                else
                {
                    do
                    {
                        cout << "\n\n=================================||Search Student Information||===================================" << endl;
                        cout << "1.Search By ID" << endl;
                        cout << "2.Search By Name" << endl;
                        cout << "3.Search By Class Name" << endl;
                        cout << "4.Search By Gender " << endl;
                        cout << "5.Exit Search Option " << endl;
                        cout << "Choose a option (1-5) : ";
                        cin >> option;
                        switch (option)
                        {
                        case 1:
                            cout << "================||Search By ID ||================" << endl;
                            cout << "Enter Student ID : ";
                            cin >> searchId;
                            for (int i = 0; i < index; i++)
                            {
                                if (student[i].getStudentId() == searchId)
                                {
                                    cout << endl;
                                    student[i].output();
                                    isTrue = true;
                                }
                            }
                            if (!isTrue)
                            {
                                cout << "Student With ID : \" " << searchId << " \" Not Found....!  " << endl;
                            }
                            isTrue = false;
                            enter();
                            break;
                        case 2:
                            cout << "================||Search By Name ||================" << endl;
                            cout << "Enter Name Of Student : ";
                            cin >> searchName;
                            for (int i = 0; i < index; i++)
                            {
                                // cout << " Get Name "<<student[i].getName();
                                if (student[i].getName() == searchName)
                                {
                                    cout << endl
                                         << endl;
                                    student[i].output();
                                    isTrue = true;
                                }
                                cout << "Student " << i << " name is " << student[i].getName();
                            }
                            if (!isTrue)
                            {
                                cout << "Student Name \" " << searchName << " \"  Not Found " << endl;
                            }
                            isTrue = false;
                            enter();
                            break;
                        case 3:
                            cout << "================|| Search By Class Name ||================" << endl;
                            cout << "Enter Class Name : ";
                            cin >> searchName;
                            for (int i = 0; i < index; i++)
                            {
                                if (student[i].getClassName() == searchName)
                                {
                                    cout << endl
                                         << endl;
                                    student[i].output();
                                    isTrue = true;
                                }
                            }
                            if (!isTrue)
                            {
                                cout << "Class Name \" " << searchName << " \" Not Found " << endl;
                            }
                            isTrue = false;
                            enter();
                            break;
                        case 4:
                            cout << "================|| Search By Gender ||================" << endl;
                            cout << "Enter Gender Of Student : ";
                            cin >> searchName;
                            for (int i = 0; i < index; i++)
                            {
                                if (student[i].getGender() == searchName)
                                {
                                    cout << endl
                                         << endl;
                                    student[i].output();
                                    isTrue = true;
                                }
                            }
                            if (!isTrue)
                            {
                                cout << "Gender : \" " << searchName << " \" Not Found " << endl;
                            }
                            isTrue = false;
                            enter();
                            break;
                        case 5:
                            cout << "Bye Bye ......!! " << endl
                                 << endl;
                            break;
                        default:
                            cout << "Wrong Option .....!! Choose Again !!....." << endl;
                        }
                    } while (option != 5);
                }
            }
            break;
        case 4:
            system("cls");
            do
            {
                if (index <= 0)
                {
                    cout << "\nDon't have student in system ......!!\n"
                         << endl;
                    option = 3;
                }
                else
                {
                    cout << "\n====================|| Delete The Student ||====================\n"
                         << endl;
                    cout << "1.Delete By ID " << endl;
                    cout << "2.Delete By Class Name " << endl;
                    cout << "3.Exit Delete Option " << endl;
                    cout << " Choose a option  (1-3) : ";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                        cout << "=================||Delete By ID ||================\n"
                             << endl;
                        cout << "Enter Student ID : ";
                        cin >> searchId;
                        for (int i = 0; i < index; i++)
                        {
                            if (student[i].getStudentId() == searchId)
                            {
                                for (int j = i; j < index - 1; j++)
                                {
                                    student[j] = student[j + 1];
                                }
                                student[i].IdAfterDelete(0);
                                isTrue = true;
                                index--;
                            }
                        }
                        if (!isTrue)
                        {
                            cout << "Student With ID \" " << searchId << " \" Not Found .....!" << endl;
                        }
                        else
                        {
                            cout << "\nDelete Student Successfully......! " << endl;
                        }
                        isTrue = false;
                        option = 3;
                        break;
                    case 2:
                        Dindex = 0;
                        cout << " ================ || Delete By Class Name || ================" << endl;
                        cout << "Enter Class Name : ";
                        cin >> searchName;
                    deleteClassName:
                        for (int i = 0; i < index; i++)
                        {
                            // cout << "value of i"<<i<<endl;
                            // cout << student[i].getClassName() << "  searchName : " << searchName << endl;
                            // cout << "className// " << student[i].getClassName() << endl;
                            // student[i].output();
                            if (student[i].getClassName() == searchName)
                            {
                                isTrue = true;
                                for (int j = i; j < index; j++)
                                {
                                    student[j] = student[j + 1];
                                    // cout << "index: " << index << endl;
                                    // cout << "Dindex: " << Dindex << endl;
                                }
                                student[i].IdAfterDelete(0);
                                // DeleteNum++;
                                index--;
                                Dindex++;
                                goto deleteClassName;
                            }
                        }
                        // index=index-DeleteNum;
                        // DeleteNum=0;
                        if (!isTrue)
                        {
                            cout << "Class Name \" " << searchName << " \" Not Found .....!" << endl;
                        }
                        else
                        {
                            cout << "\n"
                                 << Dindex << " Student In Class \" " << searchName << " \" Has Been Delete Successfully......! " << endl;
                        }
                        isTrue = false;
                        option = 3;
                    case 3:
                        cout << "Bye bye .......!" << endl
                             << endl;
                        break;
                    default:
                        cout << "\nWrong Option Please Choose Again......!" << endl
                             << endl;
                    }
                }
            } while (option != 3);
            break;
        case 5:
            system("cls");
            if (index <= 0)
            {
                cout << "\nDon't have student in system ......!! Please Check Again!!.......\n"
                     << endl;
                enter();
            }
            else
            {
                cout << "\n====================|| Display all the Student Information ||====================\n"
                     << endl;
                if (index == 1)
                {
                    student[0].output();
                    cout << "\n\nIn system have only 1 student \n"
                         << endl;
                    enter();
                }
                else
                {
                    do
                    {

                        cout << "\n1.Sorting By Student ID " << endl;
                        cout << "2.Show all students by their average in descending order " << endl;
                        cout << "3.Show Top student of the Selected number( top 3, top 5, or more)" << endl;
                        cout << "4.Exit Show Option ....!!" << endl;
                        cout << "Choose a option (1-4) : ";
                        cin >> option;
                        switch (option)
                        {
                        case 1:
                            do
                            {
                                cout << "\n=========================|| Shorting By Student ID ||=========================\n"
                                     << endl;
                                cout << "1.Display By Ascending Order" << endl;
                                cout << "2.Display By Descending Order " << endl;
                                cout << "3.Exit......!!" << endl;
                                cout << " Choose a option (1-3) : ";
                                cin >> option;
                                switch (option)
                                {
                                case 1:
                                    cout << "\n===================|| Display By Ascending Order ||===================\n"
                                         << endl;
                                    ascending(student, index);
                                    enter();
                                    break;
                                case 2:
                                    cout << "\n===================|| Display By Descending Order ||===================\n"
                                         << endl;
                                    descending(student, index);
                                    enter();
                                    break;
                                case 3:
                                    cout << " Bye Bye......!!!! \n"
                                         << endl;
                                    break;
                                default:
                                    cout << " Wrong Option ......!!  Please Choose Again  !!......." << endl;
                                }
                            } while (option != 3);
                            break;
                        case 2:
                            cout << "\n============|| Show all student average score in descending order ||==========\n"
                                 << endl;
                            averageDescending(student, index);
                            for (int i = 0; i < index; i++)
                            {
                                cout << endl
                                     << endl;
                                student[i].output();
                            }
                            cout << endl;
                            enter();
                            break;
                        case 3:
                            cout << "\n===============||Show Top students of the Selected number||===============\n"
                                 << endl;
                            do
                            {
                                cout << "Enter Number To Show Top Students : ";
                                cin >> topScore;
                                if (topScore > index)
                                {
                                    cout << "\n=====>>There are have only " << index << " Students In System \n"
                                         << endl;
                                }
                            } while (topScore > index);
                            averageDescending(student, index);
                            for (int i = 0; i < topScore; i++)
                            {
                                cout << endl
                                     << endl;
                                student[i].output();
                            }
                            cout << endl;
                            enter();
                            break;
                        case 4:
                            cout << " Bye Bye......!!" << endl;
                            break;
                        default:
                            cout << " Wrong Option ......!!! Please Choose Again !!! ........" << endl;
                        }
                    } while (option != 4);
                }
            }
            break;
        case 6:
            system("cls");
            cout << "\nBye Bye .... See you latter !!" << endl;
            break;
        default:
            cout << "\nWrong Option Please Choose Again......!" << endl
                 << endl;
        }

    } while (option != 6);

    return 0;
}

void enter()
{
    cout << "\n_________________________||Press Enter To Continue||_____________________________" << endl;
    cin.get();
    cin.get();
}

void ascending(Student student[], int index)
{
    for (int i = 0; i < index; i++)
    {
        for (int j = 0; j < index - 1; j++)
        {
            if (student[j].getStudentId() > student[j + 1].getStudentId())
            {
                Student temp = student[j + 1];
                student[j + 1] = student[j];
                student[j] = temp;
            }
        }
    }
    for (int i = 0; i < index; i++)
    {
        cout << endl
             << endl;
        student[i].output();
    }
}

void descending(Student student[], int index)
{
    for (int i = 0; i < index; i++)
    {
        for (int j = 0; j < index - 1; j++)
        {
            if (student[j].getStudentId() < student[j + 1].getStudentId())
            {
                Student temp = student[j + 1];
                student[j + 1] = student[j];
                student[j] = temp;
            }
        }
    }
    for (int i = 0; i < index; i++)
    {
        cout << endl
             << endl;
        student[i].output();
    }
}

void averageDescending(Student student[], int index)
{
    for (int i = 0; i < index; i++)
    {
        for (int j = 0; j < index - 1; j++)
        {
            if (student[j].findAverage() < student[j + 1].findAverage())
            {
                Student temp = student[j + 1];
                student[j + 1] = student[j];
                student[j] = temp;
            }
        }
    }
}