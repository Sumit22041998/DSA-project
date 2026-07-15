#include <iostream>
#include <vector>
using namespace std;

// Class Template
template <class T>
class MemoryCalculate
{
private:
    T id;
    string name;

public:
    // Constructor
    MemoryCalculate(T i, string n)
    {
        id = i;
        name = n;
    }

    // Getter
    T getId()
    {
        return id;
    }

    // Display Function
    void display()
    {
        cout << "ID   : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    vector<MemoryCalculate<int>> students;

    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n   STUDENT MANAGEMENT SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Remove Student by ID";
        cout << "\n4. Search Student by ID";
        cout << "\n5. Exit";
        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            int id;
            string name;

            cout << "\nEnter Student ID : ";
            cin >> id;

            cin.ignore();

            cout << "Enter Student Name : ";
            getline(cin, name);

            students.push_back(MemoryCalculate<int>(id, name));

            cout << "\nStudent Added Successfully.";
            break;
        }

        case 2:
        {
            if(students.empty())
            {
                cout << "\nNo Students Found.";
            }
            else
            {
                cout << "\nStudent List\n";
                cout << "------------------------\n";

                for(auto student : students)
                {
                    student.display();
                }
            }
            break;
        }

        case 3:
        {
            int id;
            bool found = false;

            cout << "\nEnter Student ID to Remove : ";
            cin >> id;

            for(auto it = students.begin(); it != students.end(); it++)
            {
                if(it->getId() == id)
                {
                    students.erase(it);
                    found = true;
                    cout << "\nStudent Removed Successfully.";
                    break;
                }
            }

            if(!found)
            {
                cout << "\nStudent Not Found.";
            }

            break;
        }

        case 4:
        {
            int id;
            bool found = false;

            cout << "\nEnter Student ID to Search : ";
            cin >> id;

            for(auto student : students)
            {
                if(student.getId() == id)
                {
                    cout << "\nStudent Found\n";
                    cout << "------------------------\n";
                    student.display();
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "\nStudent Not Found.";
            }

            break;
        }

        case 5:
        {
            cout << "\nThank You...";
            break;
        }

        default:
            cout << "\nInvalid Choice.";
        }

    } while(choice != 5);

    return 0;
}