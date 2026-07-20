#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Append Node
    void append(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "\nNode Added Successfully.\n";
    }

    // Insert at Beginning
    void insert_at_beginning(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << "\nNode Inserted Successfully.\n";
    }

    // Display
    void display()
    {
        if (head == NULL)
        {
            cout << "\nLinked List is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\nLinked List : ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Search
    void Search(int key)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "\nElement Found.\n";
                return;
            }

            temp = temp->next;
        }

        cout << "\nElement Not Found.\n";
    }

    // Delete Node
    void Delete_node(int key)
    {
        if (head == NULL)
        {
            cout << "\nLinked List is Empty.\n";
            return;
        }

        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            cout << "\nNode Deleted Successfully.\n";
            return;
        }

        Node *curr = head;

        while (curr->next != NULL && curr->next->data != key)
        {
            curr = curr->next;
        }

        if (curr->next == NULL)
        {
            cout << "\nElement Not Found.\n";
            return;
        }

        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;

        cout << "\nNode Deleted Successfully.\n";
    }

    // Reverse Linked List
    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        cout << "\nLinked List Reversed Successfully.\n";
    }
};

int main()
{
    LinkedList list;

    int choice, value;

    do
    {
        cout << "\n========== Linked List Menu ==========\n";
        cout << "1. Append Node\n";
        cout << "2. Display Linked List\n";
        cout << "3. Insert at Beginning\n";
        cout << "4. Search Element\n";
        cout << "5. Delete Node\n";
        cout << "6. Reverse Linked List\n";
        cout << "0. Exit\n";

        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value : ";
            cin >> value;
            list.append(value);
            break;

        case 2:
            list.display();
            break;

        case 3:
            cout << "Enter Value : ";
            cin >> value;
            list.insert_at_beginning(value);
            break;

        case 4:
            cout << "Enter Value to Search : ";
            cin >> value;
            list.Search(value);
            break;

        case 5:
            cout << "Enter Value to Delete : ";
            cin >> value;
            list.Delete_node(value);
            break;

        case 6:
            list.reverse();
            break;

        case 0:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 0);

    return 0;
}