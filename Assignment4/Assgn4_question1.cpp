#include<iostream>

using namespace std;

class Date{
    int day;
    int month;
    int year;
public:
    Date(){
        day=1;
        month=1;
        year=2000;
    }

    Date(int day,int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void displayDate(){
        cout<<"Date is : " <<day<<"/" <<month <<"/" <<year<<endl;
    }

    void insertDate(){
        cout<<"enter the day : ";
        cin>>day;
        cout<<"enter the month : ";
        cin>>month;
        cout<<"enter the year : ";
        cin>>year;
    }

 
};

class Person{
    string name;
    string address;
    Date* dob;

public:
    Person(){
        this-> name= " ";
        this-> address = " ";
        this->dob = new Date();  //will allocate the date object dynamically
    }

    Person(string name, string address,Date *dob){
        this->name = name ;
        this->address = address ;
        this-> dob = new Date() ; // allocating the date object dynamically 
    }

    void displayPerson(){
        cout<<"name : " << name<<endl;
        cout<<"address : "<< address<<endl;
        //dob being a pointer of class Date , we need to access the member functions by arrow operator
        dob->displayDate();

    }

    void insertPerson(){
        cout<<"enter name : " ;
        cin>>name;

        cout<<"enter adress : ";
        cin>>address;

        cout<<"enter the date of birth \n";
        //inserting the date of birth using object of class Date
        dob->insertDate();

    }

};


int main(){
    
    
    // Date d1;
    // d1.displayDate(); //will display the initialised values from constructor

    // d1.insertDate(); 


    Person p1;   //will initialise the values as per constructor , value of date will be initialised in the D()

    p1.displayPerson();

    p1.insertPerson();

    p1.displayPerson();
    

    //calling the parameterised constructor for person 
    //date is passed using Date class ka parameterised constructor
    Person p2("abhi","pune",new Date(1,2,2000));
    
    p2.displayPerson();
    

    return 0;
}