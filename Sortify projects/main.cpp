#include <iostream>
#include <climits>
#include <limits>
using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\n      SORTIFY PROJECT";
        cout << "\n==============================";
        cout << "\n1. Find Unique Elements";
        cout << "\n2. Find Largest & Second Largest";
        cout << "\n3. Sort Array (Ascending & Descending)";
        cout << "\n4. Count Positive & Negative Numbers";
        cout << "\n5. Arrange Even Ascending & Odd Descending";
        cout << "\n0. Exit";
        cout << "\n------------------------------";
        cout << "\nEnter your choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cout << "\nInvalid Input! Please enter numbers only.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        if (choice == 0)
            break;

        if (choice < 1 || choice > 5)
        {
            cout << "\nInvalid Choice!\n";
            continue;
        }

        int n;

        cout << "\nEnter size of array: ";
        cin >> n;

        if (cin.fail() || n <= 0)
        {
            cout << "\nInvalid Array Size!\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        int *arr = new int[n];

        cout << "Enter elements:\n";

        bool valid = true;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (cin.fail())
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            cout << "\nInvalid Input! Please enter numbers only.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            delete[] arr;

            continue;
        }

        switch (choice)
        {
        case 1:
        {
            cout << "\nUnique Elements:\n";

            for (int i = 0; i < n; i++)
            {
                bool duplicate = false;

                for (int j = 0; j < i; j++)
                {
                    if (arr[i] == arr[j])
                    {
                        duplicate = true;
                        break;
                    }
                }

                if (!duplicate)
                    cout << arr[i] << " ";
            }

            cout << endl;
            break;
        }

        case 2:
        {
            int largest = INT_MIN;
            int secondLargest = INT_MIN;

            for (int i = 0; i < n; i++)
            {
                if (arr[i] > largest)
                {
                    secondLargest = largest;
                    largest = arr[i];
                }
                else if (arr[i] > secondLargest && arr[i] != largest)
                {
                    secondLargest = arr[i];
                }
            }

            cout << "\nLargest Element = " << largest;

            if (secondLargest == INT_MIN)
                cout << "\nSecond Largest does not exist.";
            else
                cout << "\nSecond Largest = " << secondLargest;

            cout << endl;
            break;
        }

        case 3:
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            cout << "\nAscending Order:\n";

            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";

            cout << "\n\nDescending Order:\n";

            for (int i = n - 1; i >= 0; i--)
                cout << arr[i] << " ";

            cout << endl;
            break;
        }

        case 4:
        {
            int positive = 0, negative = 0;

            for (int i = 0; i < n; i++)
            {
                if (arr[i] > 0)
                    positive++;
                else if (arr[i] < 0)
                    negative++;
            }

            cout << "\nPositive Numbers = " << positive;
            cout << "\nNegative Numbers = " << negative << endl;

            break;
        }

        case 5:
        {
            int *even = new int[n];
            int *odd = new int[n];

            int e = 0, o = 0;

            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 2 == 0)
                    even[e++] = arr[i];
                else
                    odd[o++] = arr[i];
            }

            for (int i = 0; i < e - 1; i++)
            {
                for (int j = 0; j < e - i - 1; j++)
                {
                    if (even[j] > even[j + 1])
                    {
                        int temp = even[j];
                        even[j] = even[j + 1];
                        even[j + 1] = temp;
                    }
                }
            }

            for (int i = 0; i < o - 1; i++)
            {
                for (int j = 0; j < o - i - 1; j++)
                {
                    if (odd[j] < odd[j + 1])
                    {
                        int temp = odd[j];
                        odd[j] = odd[j + 1];
                        odd[j + 1] = temp;
                    }
                }
            }

            cout << "\nFinal Array:\n";

            for (int i = 0; i < e; i++)
                cout << even[i] << " ";

            for (int i = 0; i < o; i++)
                cout << odd[i] << " ";

            cout << endl;

            delete[] even;
            delete[] odd;

            break;
        }
        }

        delete[] arr;

    } while (true);

    cout << "\nThank You!\n";

    return 0;
}

