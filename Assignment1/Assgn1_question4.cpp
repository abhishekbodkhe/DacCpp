#include<bits/stdc++.h>

using namespace std;

namespace NStudent{

class Student
{
    int roll_no ;
    string name;
    int marks ;
    
    public:
    void initStudent(){

    }
    void acceptStudentFromConsole(){
        cout<<"Enter name of the student : ";
        cin>>name;

        cout<<"Enter Roll no : ";
        cin>> roll_no;

        cout<<"Enter marks : " ;
        cin>> marks;

    }
    void printStudentOnConsole(){
        cout<<"Student details "<<endl ;
        cout<<"name of the student : "<<name <<endl ;
        cout<<"roll no : " <<roll_no <<endl ;
        cout<<"marks : "<<marks<<endl;
        
    }

};

}

using namespace NStudent;

int main(){
    Student s1;

    s1.acceptStudentFromConsole();
    s1.printStudentOnConsole();
              
    return 0;
}