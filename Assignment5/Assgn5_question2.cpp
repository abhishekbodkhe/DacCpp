// A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class 
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books. 
// Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program 
// should be menu driven and should not cause memory leakage.

#include <iostream>

using namespace std;

class Product {
    int id;
    string title;
    double price;

public :
    Product(){
        id=0;
        title=" ";
        price = 0;
    }

    //partially incomplete functions of Base class
    virtual void addDetails(){
        cout<<"enter id : " ;
        cin>> id;

        cout<<"enter title : ";
        cin>> title;

        cout<<"enter price : ";
        cin>> price;
    }

    virtual void displayDetails(){

        cout<<"id : "<< id <<endl;
        cout<<"title : "<<title <<endl;
        cout<<"price : " <<price <<endl;
    }

    double getPrice(){
        return price ;
    }

    
};

class Book:public Product{
    
    string author;
    

public:
    Book(){

        author = " ";
        }

    
    void addDetails(){

        Product::addDetails();
        cout<<"enter author : ";
        cin>>author;
     
        }

    void displayDetails(){
        Product::displayDetails();
        cout<<"author : " << author <<endl;

    }

};


class Tape:public Product{
    
    string artist;    

public:
    Tape(){
        
        artist = " ";
    }

    void addDetails(){

        Product::addDetails();

        cout<<"enter artist : ";
        cin>>artist;

    }

    void displayDetails(){
        
        Product::displayDetails();
        cout<<"Artist : " << artist <<endl;

    }

};

int menuList (){
        int choice;
        cout<<"\n ------------------  Choose the Menu-------------------------";
        cout<<" \n0.Exit \n1.Add Book  \n2.Add Tape \n3.Calculate Bill " ;

        cout<<"\n Enter Your Choice : ";
        cin>>choice;
        return choice;
    }


int main(){

    double bill=0;
    int count = 0 ;
    int choice=menuList();

    //declaring the array of Product class pointers 
    Product *arr[3]; 

    do
    {    
        switch (choice)
        {
        case 0:
            cout<<"thank you for ur response !!";
            break;
        case 1:
            //adding a book
            if(count <3)
            {     
            arr[count] = new Book();
            arr[count]->addDetails();

            count++;
            }
            else{
            cout<<"objects are full " ;
            }

            break;

        case 2:
            //adding a Tape 
            if(count <3){
                    
            arr[count] = new Tape();
            arr[count]->addDetails();
            count++;
            
        }
        else{
            cout<<"objects are full " ;  
            }

        break;

        case 3:
            //calculating the bill of the customer
            for (int i = 0; i < 3; i++)
            {   
                double price = 0;
                //Calculating the price of the book based on the discount  of 10% on books
                if (typeid(*arr[i]).name() == typeid(Book).name())
                {   
                    price=arr[i]->getPrice();
                    price -= 0.1 * price ;
                }

                //calculating the price of the Tapes on the discount of 5% on Tapes
                else if (typeid(*arr[i]).name() == typeid(Tape).name())
                {
                    price=arr[i]->getPrice();
                    price -= 0.05 * price ;
                }

                bill+= price;
            }

            cout<<"\n The bill amount is : "<< bill;
            break;
           
        default:
            cout<<"enter valid choice \n";
            break;
        }

    }while((choice=menuList()) !=0);

    //deallocating the memory 
    delete arr[0];
    arr[0]= NULL;
    delete arr[1];
    arr[1]= NULL;
    delete arr[2];
    arr[2]= NULL;


    return 0;
}