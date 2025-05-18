#include "file_work.h"
#include <iostream>
using namespace std;

void show_menu() {
    cout << "\n=== Menu ===\n";
    cout << "1. Create new file\n";
    cout << "2. Show file content\n";
    cout << "3. Delete pairs less than specified\n";
    cout << "4. Increase matching pairs\n";
    cout << "5. Insert pairs after position\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

int main() {
    const char* filename = "data.txt";
    int choice;

    do {
        show_menu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int count = make_file(filename);
            cout << "Created file with " << count << " pairs\n";
            break;
        }

        case 2: {
            cout << "\nFile content:\n";
            int count = print_file(filename);
            cout << "Total pairs: " << count << endl;
            break;
        }

        case 3: {
            Pair threshold;
            cout << "Enter threshold pair (int double): ";
            cin >> threshold;
            int deleted = del(filename, threshold);
            cout << "Deleted " << deleted << " pairs\n";
            break;
        }

        case 4: {
            Pair target;
            int L_int;
            double L_double;

            cout << "Enter target pair (int double): ";
            cin >> target;
            cout << "Enter integer increment: ";
            cin >> L_int;
            cout << "Enter double increment: ";
            cin >> L_double;

            int modified = increase(filename, target, L_int, L_double);
            cout << "Modified " << modified << " pairs\n";
            break;
        }

        case 5: 
        {
            int position, K;
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter number of pairs to insert: ";
            cin >> K;

            int inserted = insert_after_position(filename, position, K);
            cout << "Inserted " << inserted << " pairs\n";
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}