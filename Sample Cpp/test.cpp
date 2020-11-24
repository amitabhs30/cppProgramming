#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Student
{
public:
    string name;
    string roll;
    double gpa;
    Student(string aname, string aroll, double agpa)
    {
        name = aname;
        roll = aroll;
        gpa = agpa;
    }
    bool isScolar()
    {
        if (gpa >= 3.5)
            return true;
        else
            return false;
    }
};

int main()
{
    Student A("Avnish", "B17A", 3.4);
    Student B("Akash", "B19A", 3.7);

    bool result;
    result= B.isScolar();
    cout<<result;

    return 0;
}
