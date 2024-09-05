#include<iostream>

using namespace std;

class Cylinder{
    double radius;
    double height;
    static int const pi;

public:
    //parameterless constructor
    Cylinder(){ 
        //initialising the radius and height data members
        radius =0; 
        height =0; 
    }

    //constructor member intialization 
    Cylinder(double radius, double height):radius(radius),height(height) { }

    //mutator
    void setRadius(double radius){
        this->radius = radius;
    }

    void setHeight(double height){
        this->height = height;
    }


    //inspector
    double getRadius(){

        return radius;
    }

    double getHeight(){
        return height;
    }

    void calculateVolume(){
        int vol = pi*radius*radius*height ;
        cout<<"volume of the cylinder is : " <<vol<<endl;
    }
};
//initialising the static variable pi outside the class
int const Cylinder :: pi=3.14;


int main(){

    Cylinder c1;    //parameter less constructor will be called
    
    //using mutators to set the height and radius
    c1.setHeight(10); 
    c1.setRadius(10);
    c1.calculateVolume();

    Cylinder c2(12,10); //Parameterised constructor will be called here
    c2.calculateVolume();

    
    return 0;
}