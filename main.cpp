#include"linkedlist.h"

int main() {
    DoublyLinkedList<int> myList;

    char cont;
    do {
        cout << "1. Add to Head\n"
            << "2. Add to Tail\n"
            << "3. Delete from Head\n"
            << "4. Delete from Tail\n"
            << "5. Delete All\n"
            << "6. Show\n"
            << "7. Insert at Position\n"
            << "8. Delete at Position\n"
            << "9. Find Element\n"
            << "10. Replace Element\n"
            << "11. Reverse List\n"
            << "Enter your choice: ";

        int choice;
        cin >> choice;

        int value, position;
        int replaced;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            myList.addToHead(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            myList.addToTail(value);
            break;

        case 3:
            myList.deleteFromHead();
            break;

        case 4:
            myList.deleteFromTail();
            break;

        case 5:
            myList.deleteAll();
            break;

        case 6:
            myList.show();
            break;

        case 7:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            myList.insertAtPosition(value, position);
            break;

        case 8:
            cout << "Enter position: ";
            cin >> position;
            myList.deleteAtPosition(position);
            break;

        case 9:
            cout << "Enter value to find: ";
            cin >> value;
            if (myList.findElement(value)) {
                cout << "Element found.\n";
            }
            else {
                cout << "Element not found.\n";
            }
            break;

        case 10:
            cout << "Enter old value to replace: ";
            cin >> value;
            cout << "Enter new value: ";
            cin >> position;
            replaced = myList.replaceElement(value, position);
            if (replaced > 0) {
                cout << "Replaced " << replaced << " occurrences.\n";
            }
            else {
                cout << "Element not found.\n";
            }
            break;

        case 11:
            myList.reverseList();
            cout << "List reversed.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    return 0;
}