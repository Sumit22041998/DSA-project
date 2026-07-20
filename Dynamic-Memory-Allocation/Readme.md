# Dynamic Memory Allocation using Linked List

## Overview

This project demonstrates Dynamic Memory Allocation using a Singly Linked List in C++. The program performs basic CRUD operations using classes, constructors, objects, and methods.

## Features

- Append a Node
- Insert at Beginning
- Display Linked List
- Search an Element
- Delete a Node
- Reverse the Linked List

## Concepts Used

- C++
- Class and Object
- Constructor
- Dynamic Memory Allocation
- Pointer
- Singly Linked List

## Methods

### 1. append(int value)

Creates a new node and inserts it at the end of the linked list.

### 2. insert_at_beginning(int value)

Creates a new node and inserts it at the beginning of the linked list.

### 3. display()

Displays all nodes of the linked list from the head to the last node.

### 4. Search(int key)

Searches for a value in the linked list.
If the value is found, it displays **"Element Found"**.
Otherwise, it displays **"Element Not Found"**.

### 5. Delete_node(int key)

Deletes the node that contains the given value.
If the value is not found, it displays **"Element Not Found"**.

### 6. reverse()

Reverses the linked list by changing the links between the nodes.

## How the Program Works

1. Create an empty linked list.
2. Display the menu.
3. User selects an operation.
4. The selected method is executed.
5. A success message is displayed.
6. The menu repeats until the user selects Exit.

## Sample Output

```
========== Linked List Menu ==========
1. Append Node
2. Display Linked List
3. Insert at Beginning
4. Search Element
5. Delete Node
6. Reverse Linked List
0. Exit

Enter Your Choice : 1
Enter Value : 10

Node Added Successfully.

Enter Your Choice : 2

Linked List : 10 -> NULL
```

## Conclusion

This project helps in understanding Dynamic Memory Allocation using Linked List. It demonstrates how to create, insert, search, delete, display, and reverse nodes dynamically using C++.
