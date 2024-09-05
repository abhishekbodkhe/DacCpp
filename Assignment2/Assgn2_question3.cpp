// Write a class Address with data members (string building, string street, string city ,int pin) 
//  Implement constructors, getters, setters, accept(), and display() methods. 
// Test the class functunalities by creating the object of class and calling all the functions.

#include<iostream>

using namespace std;

class Adress
{
    string building;
    string street;
    string city;
    int pin;

public:
    //parameterless ctor
    Adress(){
        //initialising the default values
        building = " ";
        street = " ";
        city = " ";
        pin = 0;
    }

    //parameterised ctor
    Adress(string building , string street , string city,int pin){
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }

    void accept(){
        cout<<"enter building : " ;
        cin>>building;

        cout<< "enter street : ";
        cin>> street;

        cout<<"enter city : " ;
        cin>> city;

        cout<<"enter pin" ;
        cin>> pin;

    }

    void display(){
        cout<<" building : "<< building  <<endl;
        cout<<" street : "<< street <<endl;
        cout<<" city : "<< city<<endl;
        cout<<" pin : "<< pin<<endl;
    }

    //mutators 
    void setBuilding(string building){
        this->building = building ;
    }

    void setStreet(string street){
        this->street = street;
    }

    void setCity(string city){
        this->city = city;
    }

    void setPin(int pin){
        this->pin = pin;
    }

    //inspectors 

    string getBuilding(){
        return building;
    }

    string getStreet(){
        return street;
    }

    string getCity(){
        return city;
    }

    int getPin(){
        return pin;
    }

};

int main(){

    Adress a1;//initialised with default values

    Adress a2("Skyline","Dp Road","city pune",1122); //parameterised ctor gets called

    cout<<"intial values : "<<endl;
    a2.display();

    //using the inspectors to fetch data members
    a2.getBuilding();
    a2.getCity();
    a2.getPin();
    
    //using mutators to modify the data members
    a2.setBuilding("Urban Skyline");
    a2.setPin(2222);

    cout<<"modified values : "<<endl;
    //display after modifications
    a2.display();

    
    return 0 ;
}