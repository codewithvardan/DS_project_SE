
#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <iostream>
#include <string>
using namespace std;

// Production record ka ek node
class Production {
public:
    int id;
    string cropName;
    float quantity;
    float price;

    // Next production node ka address
    Production* next;

    // Constructor: Node initialize karenge
    Production(int i, string n, float q, float p) {
        id = i;
        cropName = n;
        quantity = q;
        price = p;
        next = NULL;
    }

    // Ek production record display karna
    void display() {
        cout << id << "\t"
             << cropName << "\t"
             << quantity << "\t"
             << price << "\t"
             << quantity * price << endl;
    }
};

class ProductionManagement {
private:
    Production* head; // First node ka address

public:
    ProductionManagement() {
        head = NULL; // Initially list empty
    }

    // Naya production record add karna
    void addProduction() {
        int id;
        string name;
        float quantity, price;

        cout << "Enter Production ID: ";
        cin >> id;

        // Duplicate ID check
        Production* temp = head;

        while (temp != NULL) {
            if (temp->id == id) {
                cout << "ID already exists!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Enter Crop Name: ";
        cin >> name;

        cout << "Enter Produced Quantity (kg): ";
        cin >> quantity;

        cout << "Enter Price per kg: ";
        cin >> price;

        if (quantity < 0 || price < 0) {
            cout << "Invalid quantity or price!\n";
            return;
        }

        // Dynamic memory allocate karke node banayenge
        Production* node =
            new Production(id, name, quantity, price);

        if (head == NULL) {
            // Empty list mein first node add
            head = node;
        }
        else {
            temp = head;

            // Last node tak traverse karenge
            while (temp->next != NULL) {
                temp = temp->next;
            }

            // Last node ko new node se connect
            temp->next = node;
        }

        cout << "Production record added!\n";
    }

    // Saare production records display
    void displayProduction() {
        if (head == NULL) {
            cout << "No production records!\n";
            return;
        }

        Production* temp = head;

        cout << "ID\tCrop\tQty\tPrice\tValue\n";

        while (temp != NULL) {
            temp->display();

            // Next node par jayenge
            temp = temp->next;
        }
    }

    // Production ID se record search
    void searchProduction() {
        int id;

        cout << "Enter Production ID: ";
        cin >> id;

        Production* temp = head;

        // Linear Search in Linked List
        while (temp != NULL) {
            if (temp->id == id) {
                temp->display();
                return;
            }

            temp = temp->next;
        }

        cout << "Record not found!\n";
    }

    // Production record delete karna
    void deleteProduction() {
        int id;

        cout << "Enter Production ID: ";
        cin >> id;

        Production* temp = head;
        Production* prev = NULL;

        // Required node search karenge
        while (temp != NULL && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Record not found!\n";
            return;
        }

        if (prev == NULL) {
            // Agar first node delete karna hai
            head = temp->next;
        }
        else {
            // Previous node ko next node se connect
            prev->next = temp->next;
        }

        // Selected node ki memory free
        delete temp;

        cout << "Production record deleted!\n";
    }

    // Total production aur uski value calculate karna
    void totalProduction() {
        float totalQty = 0;
        float totalValue = 0;

        Production* temp = head;

        while (temp != NULL) {

            // Sabhi records ki quantity add
            totalQty += temp->quantity;

            // Quantity * Price = Production value
            totalValue += temp->quantity * temp->price;

            temp = temp->next;
        }

        cout << "Total Production: "
             << totalQty << " kg\n";

        cout << "Total Production Value: Rs. "
             << totalValue << endl;
    }

    // Destructor: Memory leak avoid karne ke liye
    ~ProductionManagement() {
        while (head != NULL) {
            Production* temp = head;

            head = head->next;

            delete temp;
        }
    }

    void menu() {
        int choice;

        do {
            cout << "\n===== PRODUCTION MANAGEMENT =====\n";
            cout << "1. Add Production\n";
            cout << "2. Display Production\n";
            cout << "3. Search Production\n";
            cout << "4. Delete Production\n";
            cout << "5. Total Production\n";
            cout << "0. Back\n";

            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addProduction(); break;
                case 2: displayProduction(); break;
                case 3: searchProduction(); break;
                case 4: deleteProduction(); break;
                case 5: totalProduction(); break;
                case 0: break;
                default: cout << "Invalid choice!\n";
            }

        } while (choice != 0);
    }
};

#endif
