#include<iostream>

using namespace std;

class Tollbooth{
    unsigned int Tcars;
    double Tmoney;

public:
    Tollbooth(){
        Tcars = 0;
        Tmoney = 0;
    }

    void payingCar(){
        Tcars += 1;
        Tmoney +=0.5;
    }

    void nopayCar(){
        Tcars+=1;
    }

    void printOnConsole(){
        cout<<"Total no of paying cars : " << Tmoney*2 <<endl;
        cout<<"Total no of non paying cars : " <<Tcars - (Tmoney*2);
        
    }

};

//menu to display
int menuList (){
        int choice;
        cout<<"\n ------------------  Choose the Menu-------------------------";
        cout<<" \n0.Exit \n1.Insert Paying car  \n2.Insert non paying car \n3.Display Total cars " ;

        cout<<"\n Enter Your Choice : ";
        cin>>choice;
        return choice;
    }

int main(){

    Tollbooth t1;
    int choice;

//menu driven loop
    do
    {
       switch (choice)
       {
       case 0:
        cout<<"thank you for using tollbooth!!" ;
        break;

        //insert paying car
       case 1:
        t1.payingCar();
        break;

        //insert non paying car
       case 2:
        t1.nopayCar();
        break;

        //Print the total cars on console
       case 3:
        t1.printOnConsole();
        break;   

       default:
        cout<<"enter valid choice !!"<<endl;
        break;
       }
    } while ((choice=menuList())!=0);
    
    return 0;
}