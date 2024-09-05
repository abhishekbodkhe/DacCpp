#include<iostream>

using namespace std;

class Date{
    int day;
    int month;
    int year;

public:

    Date(){
            day= 1;
            month= 1;
            year = 2000;
        }

    void acceptDate(){
            cout<<"enter day : ";
            cin>> day;
            cout<<"enter month : ";
            cin>> month ;
            cout<<"enter year : ";
            cin>>year;

     }

     void displayDate(){
        cout<<day << "/"<<month <<"/" <<year <<endl;
     }

};

class Person{
    string name;
    string address;
    Date dob;           //association 

public:
    Person(){
            name=" ";
            address = " ";

        }

    //virtual function with partial definition 
    virtual void accept(){
            cout<<"enter name : ";
            cin>> name;

            cout<<"enter adress : ";
            cin>> address ;
        }

    virtual void display(){
        cout<<"----------------------------"<<endl;
        cout<<"name : "<<name <<endl;
        cout<<"address : "<<address<<endl;

    }
};

class Employee:public Person{   //inheritance 

    int empid;
    int sal;
    string dept;
    Date doj;  //association

    public:
        Employee(){
            empid=0;
            sal=0;
            dept= " ";

        }

    void accept(){
            Person::accept();
            cout<<"enter employee id : ";
            cin>>empid;

            cout<<"enter salary : ";
            cin>>sal;

            cout<<"department ";
            cin>>dept;

            cout<<"enter doj \n";
            doj.acceptDate();
        }

    void display(){
            Person::display();
            cout<<"emp id : "<<empid<<endl;
            cout<<"salary :"<<sal<<endl;
            cout<<"department : "<<dept <<endl;
            cout<<"date of joining is : " <<" ";
            doj.displayDate();

        }

};

int main(){

// using virtual function we can achieve function overriding and 
// by using classname :: we can access the partial complete fn from the base class
    Employee e2;

    e2.accept();
    e2.display();


//Dynamically allocating the employee object to the base class pointer 
    Person *ptr = new Employee(); //upcasting 

    ptr->accept();
    ptr->display();

//deallocating the memory 
    delete ptr;
    ptr = nullptr;  

    return 0;
}