#include<bits/stdc++.h>
using namespace std;

class Account 
{
    int accno;
    string type;
    enum EAccounType{
        SAVINGS,
        CURRENT,
        DMAT
    };

    double balance;

public:
    Account(){

    }

    //parameterised ctor 
    Account(int accno,EAccounType AccntType,double balance){
        this->accno = accno;
        this->balance = balance;
        this->type = AccntType;
    }

    //to create an account
    void accept(){
        cout<<"enter the accno : ";
        cin>>accno;
        cout<<"enter balamce : ";
        cin>>balance;
        cout<<"accnt type : ";
        cin>>type;
    }

    //to display account details
    void display(){
        cout<<"accno : "<<accno ;
        cout<<"balance  : "<<balance;
        cout<<"accnt type : "<<type;
    }

    //withdraw amount
    void withdraw(double amount){
        if( amount>balance)
            throw 1;        //exception generation
        this->balance -= amount; 
    }

    void deposit(double amount){
        this->balance += amount;
    }

    //inspectors
    int getAccno(){
        return accno;
    }

    double getBalance(){
        return balance;
    }

    //mutators
    void setBalance(double balance){
        this->balance += balance;
    }
        
};

//Exception handling class
class InsufficientBalance{
    int accno;
    double currentBalance;
    double withdrawAmount;

public:
    InsufficientBalance(int accno, double currentBalance, double withdrawAmount)
    { 
        this->accno = accno;
        this->currentBalance = currentBalance;
        this->withdrawAmount = withdrawAmount;
        
    }
    void display(){
        // cout<<"insufficient balance !!!!! \n";
        cout<<"---------------------------- \n";
        cout<<"CHALA JAA BHOSDIKE !!!!! \n";
        cout<<"your accnt balance is : "<<currentBalance<<endl;
    }


};

int main(){
    vector <Account > accounts;
    Account a1;
    int choice,accNo,amount,temp;
    do{

        cout<<"Menu "<<endl;

        cout<<"1.Create Accnt "<<endl;
        cout<<"2.Show Balamce "<<endl;
        cout<<"3.Withdrawl "<<endl;
        cout<<"4.Deposit \n";
        cout<<"5.Exit \n";

        cout<<"enter your choice : ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            //Create account
            a1.accept();
            accounts.push_back(a1);
            break;
        case 2:
            //Show Blance
            cout<<"enter accnt no : ";
            cin>>accNo;
            for(int i=0 ;i<accounts.size(); i++)
                if(accounts[i].getAccno()==accNo)
                    cout<<"balance : "<<accounts[i].getBalance()<<endl;
            break;
        
        case 3:
            //Withdraw amount
            try{ 
            
            cout<<"enter accnt no : ";
            cin>>accNo;
            cout<<"enter amount to be withdrawned : ";
            cin>>amount;

            for (int i = 0; i < accounts.size(); i++)
                if(accounts[i].getAccno()==accNo)
                    {
                        temp=i; // to store the current accounts index 
                        accounts[i].withdraw(amount);
                    }
            }
            //catch block to catch the error while withdrawned amount exceeds balance
            catch(int error){
                double balance = accounts[temp].getBalance(); //fetching the current balance

                InsufficientBalance b(accNo,balance,amount);//creating a object of insufficient balance class

                b.display(); //to display the exception details
            }
            break;
        case 4:
            //Deposite amount
            cout<<"enter accnt no : ";
            cin>>accNo;
            cout<<"enter amount to be deposited : ";
            cin>>amount;
            for(int i=0 ;i<accounts.size(); i++)
                if(accounts[i].getAccno()==accNo)
                    accounts[i].setBalance(amount);
            
            break;
        case 5:
            cout<<"Thank you for using our bank!!!!";
            break;
        default:
            cout<<"select Valid choice !!!! \n";
            break;
        }

    }while(choice !=0);
return 0;
}