//Diamond problem in Hybrid inheritance 

#include<iostream>

using namespace std;

class Employee{
    int id;
    double salary;
public:

    Employee(){

    }

    Employee(int id, double salary){
        this->id =  id;
        this -> salary = salary ;
    }
    //dynamic binding to override the function in derived class
   virtual void accept(){

        cout<<"Id : ";
        cin>>id;

        cout<<"Salary : ";
        cin>>salary;

    }

   virtual void display(){
        cout<<"--------------------------------\n";
        cout<<"Id : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;

    }
    
    //mutators
    void setId(int id){
        this->id = id;
    }

    void setSalary(double salary){
        this->salary = salary;
    }

    //inspectors
    int getId(){
        return id;
    }

    double getSalary(){
        return salary;
    }
   
};

class Manager:virtual public Employee{
    double bonus;

public:
    Manager(){
        bonus = 0;
    }

    Manager(int id, double salary, double bonus){
        //Initialising the values using Mutators
        this->setId(id);
        this->setSalary(salary);
        this->bonus = bonus;
    }

    //used as a mutator for getting bonus value
    void acceptManagerDetails(){
        cout<<"enter bonus : ";
        cin>>bonus;
    }

    void displayManagerDetails(){
        cout<<"Bonus : "<< bonus<<endl;
    }

    //accept complete manager details
    void accept(){
        Employee::accept();
        acceptManagerDetails();

    }

    void display(){
        Employee::display();
        displayManagerDetails();

    }

};


class Salesman:virtual public Employee{
    double comminsion;
public:
    Salesman(){
        this->comminsion = 0;
    }

    Salesman(int id, double salary, double commision){
        this->setId(id);
        this->setSalary(salary);
        this->comminsion = comminsion;
    }

    //used as a mutator for getting commision value
    void acceptSalesmanDetails(){
        cout<<"enter commision : ";
        cin>>comminsion;
    }

    void displaySalesmanDetails(){
        cout<<"Commision : "<< comminsion<<endl;
    }

    virtual void accept(){
        Employee::accept();
        acceptSalesmanDetails();

    }

    virtual void display(){
        Employee::display();
        displaySalesmanDetails();
    }
};

class SalesManager:public Salesman , public Manager{
public:
    SalesManager(){

    }
    //parameterised ctor
    SalesManager(int id, double salary, double bonus, double commision){
        
    }

    //Accepts employee + manager + salesman details at one place 
    void accept(){
        Employee::accept();
        acceptManagerDetails();
        acceptSalesmanDetails();

    }

    void display(){
        Employee::display();
        displayManagerDetails();
        displaySalesmanDetails();
    
    }

};

//Menu driven code 
int menuList (){
        int choice;
        cout<<"\n ------------------  Choose the Menu-------------------------";
        cout<<" \n0.Exit \n1.Accept Manager  \n2.Accept Salesman \n3.Accept SalesManager \n4.Display count wrt designation \n5.Display all Managers \n6.Display all Salesman \n7.Display All SalesManager ";

        cout<<"\n Enter Your Choice : ";
        cin>>choice;
        return choice;
    }


int main(){

    int choice = menuList();
    int count=0;
    
    Employee *arr[5];

    do{
        int Mcount=0;
        int Scount= 0;
        int SMcount =0;

        switch (choice)
        {
            //exit
        case 0:
            cout<<"Thank you for using the application !!!!!";
            break;
        case 1:
            //To insert Manager
            if(count < 5){
                arr[count] = new Manager();
                arr[count]->accept();
                count++;
            }
            else 
                cout<<"the list is Full......";
            break;
        case 2:
            //Insert salesman
            if(count < 5){
                arr[count]= new Salesman();
                arr[count]->accept();
                count++;
            }
            else 
                cout<<"the list is Full......";
            break;
        case 3:
            //Insert SalesManager
            if(count < 5){
                arr[count] = new SalesManager();
                arr[count]->accept();
                count++;
            }
            else 
                cout<<"the list is Full......";
            break;
        case 4:
            //Get designation count
            for (int i = 0; i < count; i++)
            {
                if(typeid(*arr[i]).name()== typeid(Manager).name())
                    Mcount++;
                else if(typeid(*arr[i]).name()== typeid(Salesman).name())
                    Scount++;
                else if(typeid(*arr[i]).name()== typeid(SalesManager).name())
                    SMcount++;
            }

            cout<<"The no. of Managers are : "<< Mcount<<endl;
            cout<<"The no. of Salesman are : "<< Scount<<endl;
            cout<<"The no. of SalesManagers are : "<< SMcount<<endl;            
            break;
        
        case 5:
            //Display all managers
            for (int i = 0; i < count; i++)
            {
                if(typeid(*arr[i]).name() == typeid(Manager).name())
                    arr[i]->display();  
            } 
            break;

        case 6:
            //Display all Salesman
            for (int i = 0; i < count; i++)
            {
                if(typeid(*arr[i]).name()== typeid(Salesman).name())
                    arr[i]->display();  
            } 
            break;

        case 7:
            //Display SalesManager
            for (int i = 0; i < count; i++)
            {
                if(typeid(*arr[i]).name()== typeid(SalesManager).name())
                    arr[i]->display();  
            } 
            break;

        default:
            //Invalid choice
            cout<<"Enter valid choice !"<<endl;
            break;
        }

    }while((choice=menuList())!=0 );
    return 0;
}