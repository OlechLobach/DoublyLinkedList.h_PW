#include "linkedlist.h"

using namespace std;

int main() {
    Array<int> myArray;
    int choice;

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Print Array" << endl;
        cout << "2. Add Element" << endl;
        cout << "3. Insert Element" << endl;
        cout << "4. Remove Element" << endl;
        cout << "5. Set Size" << endl;
        cout << "6. Get Upper Bound" << endl;
        cout << "7. Is Empty?" << endl;
        cout << "8. Free Extra" << endl;
        cout << "9. Remove All" << endl;
        cout << "10. Get At" << endl;
        cout << "11. Set At" << endl;
        cout << "12. Operator []" << endl;
        cout << "13. Add (Append)" << endl;
        cout << "14. Append" << endl;
        cout << "15. Operator =" << endl;
        cout << "16. Get Data" << endl;
        cout << "17. Insert At" << endl;
        cout << "18. Remove At" << endl;
        cout << "19. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            myArray.PrintArray();
            break;
        case 2: {
            int value;
            cout << "Enter the value to add: ";
            cin >> value;
            myArray.Add(value);
            break;
        }
        case 3: {
            int index, value;
            cout << "Enter the index to insert at: ";
            cin >> index;
            cout << "Enter the value to insert: ";
            cin >> value;
            try {
                myArray.InsertAt(index, value);
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 4: {
            int index;
            cout << "Enter the index to remove: ";
            cin >> index;
            try {
                myArray.RemoveAt(index);
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 5: {
            int newSize, newGrow;
            cout << "Enter the new size: ";
            cin >> newSize;
            cout << "Enter the growth factor: ";
            cin >> newGrow;
            myArray.SetSize(newSize, newGrow);
            break;
        }
        case 6:
            cout << "Upper Bound: " << myArray.GetUpperBound() << endl;
            break;
        case 7:
            cout << (myArray.IsEmpty() ? "Array is empty" : "Array is not empty") << endl;
            break;
        case 8:
            myArray.FreeExtra();
            break;
        case 9:
            myArray.RemoveAll();
            break;
        case 10: {
            int index;
            cout << "Enter the index to get element: ";
            cin >> index;
            try {
                cout << "Element at index " << index << ": " << myArray.GetAt(index) << endl;
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 11: {
            int index, value;
            cout << "Enter the index to set element: ";
            cin >> index;
            cout << "Enter the value to set: ";
            cin >> value;
            try {
                myArray.SetAt(index, value);
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 12: {
            int index;
            cout << "Enter the index for operator []: ";
            cin >> index;
            try {
                cout << "Value at index " << index << " (using operator []): " << myArray[index] << endl;
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 13: {
            int value;
            cout << "Enter the value to add (using Add): ";
            cin >> value;
            myArray.Add(value);
            break;
        }
        case 14: {
            Array<int> anotherArray;
            anotherArray.Add(5);
            anotherArray.Add(6);
            myArray.Append(anotherArray);
            cout << "Array after appending anotherArray: ";
            myArray.PrintArray();
            break;
        }
        case 15: {
            Array<int> newArray;
            newArray.Add(99);
            newArray.Add(100);
            myArray = newArray;
            cout << "Array after using operator = with newArray: ";
            myArray.PrintArray();
            break;
        }
        case 16: {
            int* data = myArray.GetData();
            cout << "Array data: ";
            for (int i = 0; i < myArray.GetSize(); ++i) {
                cout << data[i] << " ";
            }
            cout << endl;
            delete[] data;
            break;
        }
        case 17: {
            int index, value;
            cout << "Enter the index to insert at: ";
            cin >> index;
            cout << "Enter the value to insert: ";
            cin >> value;
            try {
                myArray.InsertAt(index, value);
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 18: {
            int index;
            cout << "Enter the index to remove: ";
            cin >> index;
            try {
                myArray.RemoveAt(index);
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 19:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 19);

    return 0;
}