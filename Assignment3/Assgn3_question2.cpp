#include<bits/stdc++.h>

using namespace std;

class Time{
    int h;
    int m;
    int s;

public:
    //parameterless constructor
    Time(){

    }

    //parameterised constructor
    Time(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }

    //mutators 
    void setHours(int h){
        this->h = h;
    }

    void setMins(int m){
        this->m = m;
    }

    void setSeconds(int s){
        this->s=s;
    }

    //inspectors 
    int getHours(){
        return h;
    }

    int getMins(){
        return m;
    }

    int getSeconds(){
        return s;
    }


    void PrintTime(){
        cout<<"Time is - "<<h<<":"<<m<<":"<<s<<endl;
    }

};

int main(){
    //dynamically allocating the array of class Time pointers
    Time **ptr =new Time*[3];

    ptr[0]= new Time(1,2,3);   //declaring the object using parameterised constructor dynamically
    ptr[1]= new Time();        // using the parameterless constructor
    ptr[3]= new Time(5,3,4);

    ptr[0]->PrintTime();

    //to initialise the values at ptr[1] using mutators , as it was created using parameterless ctor
    ptr[1]->setHours(10);
    ptr[1]->setMins(5);
    ptr[1]->setSeconds(2);


    //inspectors to fetch the values 
    ptr[1]->getHours();
    ptr[1]->getMins();
    ptr[1]->getSeconds();

    //display the Time using print function
    ptr[1]->PrintTime();

    return 0;
}