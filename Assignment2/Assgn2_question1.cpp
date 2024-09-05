// Q1. Write a menu driven program to calculate volume of the box(length * width * height). 
// Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor. 
// Create the local objects in respective case and call the function to caluclate area. 
// Menu options ->  
// 1. Calculate Volume with default values 
// 2. Calculate Volume with length,breadth and height with same value 
// 3. Calculate Volume with different length,breadth and height values. 

#include<iostream>

using namespace std;

class Box
{
    int length;
    int width;
    int height;

public:
    //Parameterless constructor , intialises the values to 1
    Box(){
        length = 1;
        width = 1;
        height = 1;
    }

    //parameterised ctor with single parameter
    
    Box(int val):Box(val,val,val){} //constructor delegation 

    //parameteised ctor with 3 parameters
    Box(int length, int width, int height){
        this->length = length ;
        this->width = width ;
        this->height = height;
    }
    
    void calculateVolume(){
        cout<<"Volume of the box is : " <<length * width * height << endl;
    }


};

int menuList (){
        int choice;
        cout<<"\n ------------------  Choose the Menu-------------------------";
        cout<<" \n0.Exit \n1.Calculate Volume with default values   \n2.Calculate Volume with length,breadth and height with same value  \n3.Calculate Volume with different length,breadth and height values.  " ;

        cout<<"\n Enter Your Choice : ";
        cin>>choice;
        return choice;
    }

int main(){
    int choice;
    
    Box b1;
    Box b2(2);
    Box b3(2,3,4);

    do
    {
       
    
    switch (choice)
    {
    case 0:
        cout<<"thnak you !!";
        break;
    case 1:
        b1.calculateVolume();
        break;
    case 2:
        b2.calculateVolume();
        break;
    case 3:
        b3.calculateVolume();
        break;
    
    default:
        cout<<"enter valid choice!!";
        break;
    }

    } while (choice=menuList()!=0);
    
    

    
    return 0;
}