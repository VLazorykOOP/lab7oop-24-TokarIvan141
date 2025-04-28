#include <iostream>
#include <cstring>
#include "Array.h"
#include "DoublyLinkedList.h"

using namespace std;

template <typename T>
int lastIndexOf(T arr[], int size, T key) {
    int lastIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

template <>
int lastIndexOf<char*>(char* arr[], int size, char* key) {
    int lastIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (strcmp(arr[i], key) == 0) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

void task1()
{
    cout << "\n=========Task 1=========\n";

    int arrInt[] = {4, 2, 7, 3, 2, 9, 2};
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);
    int keyInt = 2;
    int resultInt = lastIndexOf(arrInt, sizeInt, keyInt);
    cout << "Last index of " << keyInt << ": " << resultInt << endl;

    char* arrStr[] = {"apple", "banana", "orange", "apple", "kiwi"};
    int sizeStr = sizeof(arrStr) / sizeof(arrStr[0]);
    char* keyStr = (char*)"apple";
    int resultStr = lastIndexOf(arrStr, sizeStr, keyStr);
    cout << "Last index of \"" << keyStr << "\": " << resultStr << endl;
}

template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template <>
void insertionSort<char*>(char* arr[], int size) {
    for (int i = 1; i < size; ++i) {
        char* key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void showArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;
}

void showArray(char* arr[], int size) {
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;
}

void task2()
{
    cout << "\n=========Task 2=========\n";

    int arrInt[] = {4, 2, 7, 3, 2, 9, 2};
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);

    char* arrStr[] = {"apple", "banana", "orange", "apple", "kiwi"};
    int sizeStr = sizeof(arrStr) / sizeof(arrStr[0]);

    cout << "\nSorting int array:\nBefore: ";
    showArray(arrInt, sizeInt);
    insertionSort(arrInt, sizeInt);
    cout << "After: ";
    showArray(arrInt, sizeInt);

    cout << "\nSorting char* array:\nBefore: ";
    showArray(arrStr, sizeStr);
    insertionSort(arrStr, sizeStr);
    cout << "After: ";
    showArray(arrStr, sizeStr);
}

void task3()
{
    cout << "\n=========Task 3=========\n";

    int size = 5;
    Array<int> a(size);
    Array<int> b(size);

    for (int i = 0; i < size; ++i) {
        a[i] = i + 1;
        b[i] = (i + 1) * 10;
    }

    cout << "Array a: "; a.print();
    cout << "Array b: "; b.print();

    Array<int> c = a + b;
    cout << "a + b: "; c.print();

    a += b;
    cout << "a += b: "; a.print();

    Array<int> d = a - b;
    cout << "a - b: "; d.print();

    d -= b;
    cout << "d -= b: "; d.print();
}

void task4()
{
    cout << "\n=========Task 4=========\n";

    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(22);
    list.push_back(36);
    list.push_back(48);

    cout << "List forward (method): ";
    list.print();

    cout << "List reverse (method): ";
    list.print_reverse();

    cout << "List forward (iterator): ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(nullptr));

    int choice;
    do
    {
        cout << "\n============ Main Menu ============" << endl;
        cout << "1 - Task 1" << endl;
        cout << "2 - Task 2" << endl;
        cout << "3 - Task 3" << endl;
        cout << "4 - Task 4" << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again\n";
        }
    } while (choice != 0);

    return 0;
}