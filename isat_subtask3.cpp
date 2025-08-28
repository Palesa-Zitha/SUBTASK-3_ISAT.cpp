#include <iostream>
#include <string>
using namespace std; // Enables use of standard library features without prefixing with 'std::'

int main() {
    const int SIZE = 50; // Maximum number of orders the system can store

    // Parallel arrays to store order details
    int orderID[SIZE];                 // Stores unique order IDs
    string customerName[SIZE];        // Stores customer names
    int numberOfMagwinyas[SIZE];      // Stores quantity of Magwinyas ordered
    double totalAmount[SIZE];         // Stores total cost for each order

    int orderCount = 0; // Tracks how many orders have been added
    int choice;         // Stores user's menu selection

    // Main menu loop
    do {
        // Display menu options
        cout << "\n=== Magwinya Magic Order System ===\n";
        cout << "1. Add a New Order\n";
        cout << "2. Display All Orders\n";
        cout << "3. Find Order by Order ID\n";
        cout << "4. Calculate Total Revenue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Handle user's choice
        switch (choice) {
            case 1:
                // Add a new order if there's space
                if (orderCount < SIZE) {
                    cout << "\nEnter Order ID: ";
                    cin >> orderID[orderCount];
                    cin.ignore(); // Clears leftover newline character from input buffer

                    cout << "Enter Customer Name: ";
                    getline(cin, customerName[orderCount]); // Reads full name including spaces

                    cout << "Enter Number of Magwinyas Ordered: ";
                    cin >> numberOfMagwinyas[orderCount];

                    cout << "Enter Total Cost: ";
                    cin >> totalAmount[orderCount];

                    orderCount++; // Move to next index for future orders
                    cout << "Order added successfully!\n";
                } else {
                    cout << "Cannot add more orders (limit reached).\n";
                }
                break;

            case 2:
                // Display all stored orders
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
                // Search for an order by its ID
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
                            break; // Exit loop once found
                        }
                    }
                    if (!found) {
                        cout << "Order ID not found!\n";
                    }
                }
                break;
            }

            case 4: {
                // Calculate and display total revenue from all orders
                double totalRevenue = 0;
                for (int i = 0; i < orderCount; i++) {
                    totalRevenue += totalAmount[i];
                }
                cout << "Total Revenue: " << totalRevenue << endl;
                break;
            }

            case 5:
                // Exit the program
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                // Handle invalid menu input
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5); // Repeat until user chooses to exit

    return 0; // End of program
}
