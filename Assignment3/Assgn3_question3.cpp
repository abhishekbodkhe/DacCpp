#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;  
    int count; 
    int size;  

public:
    // Default constructor initializes stack with size 5
    Stack()
    {
        size = 5;
        arr = new int[size]; 
        count = -1;          
    }

    // Parameterized constructor initializes stack with given size
    Stack(int size)
    {
        this->size = size;
        arr = new int[size]; 
        count = -1;          
    }

    // Destructor to release allocated memory
    ~Stack()
    {
        delete[] arr; // Deallocate memory used by stack
    }

    // Pushes an element onto the stack
    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl; // Stack is full, cannot push
        }
        else
        {
            arr[++count] = data; // Increment top index and add data to stack
        }
    }

    // Pops an element from the stack and returns it
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl; // Stack is empty, cannot pop
            return -1;                          
        }
        else
        {
            return arr[count--]; // Return top element and decrement top index
        }
    }

    // Returns the top element of the stack without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl; // Stack is empty, no element to peek
            return -1;                         
        }
        else
        {
            return arr[count]; // Return the top element
        }
    }

    // Checks if the stack is empty
    bool isEmpty()
    {
        return count == -1; // True if no elements are in the stack
    }

    // Checks if the stack is full
    bool isFull()
    {
        return count == size - 1; // True if stack has reached its capacity
    }

    // Prints all elements in the stack
    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl; // Stack is empty, nothing to print
        }
        else
        {
            for (int i = 0; i <= count; i++)
            {
                cout << arr[i] << " "; // Print each element in the stack
            }
            cout << endl;
        }
    }
};

// Displays menu and returns the user's choice
int menu()
{
    int choice;
    cout << "\n--- Stack Menu ---" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Is Empty" << endl;
    cout << "5. Is Full" << endl;
    cout << "6. Print Stack" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main()
{
    int stackSize;
    cout << "Enter Size of Stack: ";
    cin >> stackSize; 

    Stack s1(stackSize); // Create stack with specified size
    int choice;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            int val;
            cout << "Enter value to push: ";
            cin >> val;   
            s1.push(val); // Push value onto the stack
            break;
        }
        case 2:
        {
            int poppedValue = s1.pop(); // Pop value from stack
            if (poppedValue != -1)
            {
                cout << "Popped value: " << poppedValue << endl; // Display popped value
            }
            break;
        }
        case 3:
        {
            int topValue = s1.peek(); // Get top value of the stack
            if (topValue != -1)
            {
                cout << "Top value: " << topValue << endl; // Display top value
            }
            break;
        }
        case 4:
        {
            if (s1.isEmpty())
            {
                cout << "Stack is empty" << endl; // Display if stack is empty
            }
            else
            {
                cout << "Stack is not empty" << endl; // Display if stack is not empty
            }
            break;
        }
        case 5:
        {
            if (s1.isFull())
            {
                cout << "Stack is full" << endl; // Display if stack is full
            }
            else
            {
                cout << "Stack is not full" << endl; // Display if stack is not full
            }
            break;
        }
        case 6:
        {
            cout << "Stack data: ";
            s1.print(); // Print stack contents
            break;
        }
        default:
        {
            cout << "Invalid choice! Please try again." << endl; // Handle invalid choices
            break;
        }
        }
    }

    return 0;
}