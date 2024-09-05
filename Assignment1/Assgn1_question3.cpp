#include<bits/stdc++.h>

using namespace std;

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

int menu(){
    int choice;
    cout<<" --------MENU--------"<<endl;
    cout<<"0.Exit "<<endl;
    cout<<"1.Enter student details "<<endl;
    cout<<"2.Display student details "<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;

    return choice;
}

int main(){
    Student s1;
    int choice;

    
    while ((choice = menu()) != 0){

        switch(choice){
            case 0:
                break;

            case 1:
                s1.acceptStudentFromConsole();
                break;
            case 2:
                s1.printStudentOnConsole();
                break;
            default:
                cout<<"Enter valid Choice \n";
                break;
        }
    }

    
    return 0;
}