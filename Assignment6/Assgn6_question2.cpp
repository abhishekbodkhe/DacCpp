#include<iostream>

using namespace std;

//function to calculate the factorial of given number n
int factorial(int n){

    int fact=1;
    for (int i = n; i > 0; i--)
        fact*=i;
    
    return fact;
}


int main(){
    int num, fact;

    try{
    
        cout<<"enter the number : ";
        cin>>num;

        //exception for a negative number
        if(num<0)
            throw 1;

        fact = factorial(num);

        cout<<"factorial of "<<num << " is : " <<fact<<endl;

    }
    catch(int error){
        cout<<"Please enter a positive value !! \n";
    }
    
    return 0;
}