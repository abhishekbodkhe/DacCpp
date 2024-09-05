#include <iostream>
using namespace std;

class Student
{
private:
    string name;       
    string gender;
    int rollNumber;    
    static int rollNoGenerate; 
    int marks[3];      

public:
    // Default constructor initializes name, gender, marks to 0 and auto-generates roll number
    Student()
    {
        this->name = "";
        this->gender = "";
        marks[0] = 0;
        marks[1] = 0;
        marks[2] = 0;
        this->rollNumber = ++rollNoGenerate; // Auto-generate roll number
    }

    // Function to get the roll number of the student
    int getRollNo()
    {
        return this->rollNumber;
    }

    // Function to accept student details from the user
    void acceptStudent()
    {
        cout << "Enter name: ";
        cin >> this->name;
        cout << "Enter gender: ";
        cin >> this->gender; 
        cout << "Enter marks of first subject: ";
        cin >> marks[0]; 
        cout << "Enter marks of second subject: ";
        cin >> marks[1]; 
        cout << "Enter marks of third subject: ";
        cin >> marks[2]; 
    }

    // Function to display student details
    void displayStudent() const
    {
        cout << "Roll No: " << this->rollNumber << endl; 
        cout << "Name: " << this->name << endl; 
        cout << "Gender: " << this->gender << endl; 
        cout << "Marks: " << marks[0] << " " << marks[1] << " " << marks[2] << endl; 
    }
};

// Initialize static variable for roll number generation
int Student::rollNoGenerate = 1000;

// Function to search for a student by roll number in the array
int searchStudent(int roll, Student arr[], int index)
{
    for (int i = 0; i < index; i++)
    {
        if (roll == arr[i].getRollNo())
        {
            return i; // Return index if student found
        }
    }
    return -1; // Return -1 if student not found
}

// Function to sort student records by roll number in descending order
void sortRecords(Student arr[], int index)
{
    for (int i = 0; i < index - 1; i++)
    {
        int ind = i; // Assume the current position is the highest
        for (int j = i + 1; j < index; j++)
        {
            if (arr[j].getRollNo() > arr[ind].getRollNo())
            {
                ind = j; 
            }
        }

        if (ind != i)
        {
            // Swap students if needed
            Student temp = arr[i];
            arr[i] = arr[ind];
            arr[ind] = temp;
        }
    }
}

int main()
{
    int choice; 
    int index = 0; 
    int stdCount = 5; 
    Student *s = new Student[stdCount]; 

    do
    {
        // Display menu options
        cout << "\n--- Student Management Menu ---" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all student" << endl;
        cout << "3. Search student by RollNo " << endl;
        cout << "4. Sort students by RollNo" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice :";
        cin >> choice; // Read user's choice

        switch (choice)
        {
        case 1:
            if (index < stdCount)
            {
                s[index].acceptStudent(); // Accept student details
                cout << "Student added at index: " << index << endl;
                index++;
            }
            else
            {
                cout << "Max student limit reached!" << endl;
            }
            break;

        case 2:
            for (int i = 0; i < index; i++)
            {
                s[i].displayStudent(); // Display all students
            }
            break;

        case 3:
            {
                int roll;
                cout << "Enter Roll Number to search: ";
                cin >> roll; // Read roll number to search

                int result = searchStudent(roll, s, index); // Search for the student
                if (result != -1)
                {
                    cout << "Student found at index: " << result << endl;
                }
                else
                {
                    cout << "Student not found" << endl;
                }
            }
            break;

        case 4:
            sortRecords(s, index); // Sort students by roll number
            cout << "Students sorted by RollNo in descending order." << endl;

            for (int i = 0; i < index; i++)
            {
                s[i].displayStudent(); // Display sorted students
            }
            break;

        case 0:
            break;

        default:
            cout << "Wrong choice" << endl;
            break;
        }
    } while (choice != 0);

    delete[] s; // Deallocate memory for student array
    return 0;
}