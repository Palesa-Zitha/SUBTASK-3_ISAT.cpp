#include <iostream>
#include <string>
using namespace std:

int main() {
    const int SIZE = 50;
    int orderID[SIZE];
    string customerName[SIZE];
    int numberOfMagwinyas[SIZE];
    double totalAmount[SIZE];

    int orderCount = 0;
    int choice;

    do {
        cout << "\n=== Magwinya Magic Order System ===\n";
        cout << "1. Add a New Order\n";
        cout << "2. Display All Orders\n";
        cout << "3. Find Order by Order ID\n";
        cout << "4. Calculate Total Revenue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (orderCount < SIZE) {
                    cout << "\nEnter Order ID: ";
                    cin >> orderID[orderCount];
                    cin.ignore(); // Clear newline
                    cout << "Enter Customer Name: ";
                    getline(cin, customerName[orderCount]);
                    cout << "Enter Number of Magwinyas Ordered: ";
                    cin >> numberOfMagwinyas[orderCount];
                    cout << "Enter Total Cost: ";
                    cin >> totalAmount[orderCount];
                    orderCount++;
                    cout << "Order added successfully!\n";
                } else {
                    cout << "Cannot add more orders (limit reached).\n";
                }
                break;

            case 2:
    if (orderCount == 0) {
        cout << "No orders to display!\n";
    } else {
        cout << "\n--- All Orders ---\n";
        for (int i = 0; i < orderCount; i++) {
            cout << "Order ID: " << orderID[i]
                 << ", Customer: " << customerName[i]
                 << ", Number of Magwinyas: " << numberOfMagwinyas[i]
                 << ", Total: " << totalAmount[i] << endl;
        }
    }
    break;


            case 3: {
                if (orderCount == 0) {
                    cout << "No orders available!\n";
                } else {
                    int searchID;
                    cout << "Enter Order ID to find: ";
                    cin >> searchID;
                    bool found = false;
                    for (int i = 0; i < orderCount; i++) {
                        if (orderID[i] == searchID) {
                            cout << "\nOrder Found:\n";
                            cout << "ID: " << orderID[i] << "\n"
                                 << "Customer: " << customerName[i] << "\n"
                                 << "NumMagwinyas: " << numberOfMagwinyas[i] << "\n"
                                 << "Total: " << totalAmount[i] << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Order ID not found!\n";
                    }
                }
                break;
            }

            case 4: {
                double totalRevenue = 0;
                for (int i = 0; i < orderCount; i++) {
                    totalRevenue += totalAmount[i];
                }
                cout << "Total Revenue: " << totalRevenue << endl;
                break;
            }

            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
