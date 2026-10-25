
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include <string>
using namespace std;

// Linked List ka ek node
class Equipment {
public:
    int id;
    string name;
    bool booked;

    // Next node ka address store karega
    Equipment* next;

    // Constructor
    Equipment(int i, string n) {
        id = i;
        name = n;
        booked = false; // Starting mein equipment available hai
        next = NULL;    // Abhi next node nahi hai
    }
};

class EquipmentManagement {
private:
    // Head first node ka address store karta hai
    Equipment* head;

public:
    EquipmentManagement() {
        head = NULL; // Starting mein linked list empty hai
    }

    // Naya equipment add karna
    void addEquipment() {
        int id;
        string name;

        cout << "Enter Equipment ID: ";
        cin >> id;

        // Pehle duplicate ID check karenge
        Equipment* temp = head;

        while (temp != NULL) {
            if (temp->id == id) {
                cout << "ID already exists!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Enter Equipment Name: ";
        cin >> name;

        // new keyword memory mein naya node banata hai
        Equipment* node = new Equipment(id, name);

        // Agar list empty hai toh new node head banega
        if (head == NULL) {
            head = node;
        }
        else {
            temp = head;

            // Last node tak jayenge
            while (temp->next != NULL) {
                temp = temp->next;
            }

            // Last node ko new node se connect karenge
            temp->next = node;
        }

        cout << "Equipment added!\n";
    }

    // Saare equipment display karna
    void displayEquipment() {
        Equipment* temp = head;

        if (temp == NULL) {
            cout << "No equipment available.\n";
            return;
        }

        // Head se last node tak traverse karenge
        while (temp != NULL) {

            cout << "ID: " << temp->id
                 << " Name: " << temp->name
                 << " Status: "
                 << (temp->booked ? "Booked" : "Available")
                 << endl;

            // Next node par move karenge
            temp = temp->next;
        }
    }

    // ID ke through node search karna
    Equipment* search(int id) {
        Equipment* temp = head;

        while (temp != NULL) {

            if (temp->id == id) {
                return temp; // Matching node ka address return
            }

            temp = temp->next;
        }

        return NULL; // Equipment nahi mila
    }

    void searchEquipment() {
        int id;

        cout << "Enter Equipment ID: ";
        cin >> id;

        Equipment* temp = search(id);

        if (temp == NULL) {
            cout << "Equipment not found!\n";
        }
        else {
            cout << "Name: " << temp->name << endl;

            cout << "Status: "
                 << (temp->booked ? "Booked" : "Available")
                 << endl;
        }
    }

    // Equipment book karna
    void bookEquipment() {
        int id;

        cout << "Enter Equipment ID: ";
        cin >> id;

        Equipment* temp = search(id);

        if (temp == NULL) {
            cout << "Equipment not found!\n";
        }
        else if (temp->booked) {
            cout << "Already booked!\n";
        }
        else {
            // false ko true karenge
            temp->booked = true;

            cout << "Equipment booked successfully!\n";
        }
    }

    // Booked equipment return karna
    void returnEquipment() {
        int id;

        cout << "Enter Equipment ID: ";
        cin >> id;

        Equipment* temp = search(id);

        if (temp == NULL) {
            cout << "Equipment not found!\n";
        }
        else if (!temp->booked) {
            cout << "Equipment is not booked!\n";
        }
        else {
            // true ko false karenge
            temp->booked = false;

            cout << "Equipment returned!\n";
        }
    }

    // Linked list se equipment delete karna
    void deleteEquipment() {
        int id;

        cout << "Enter Equipment ID: ";
        cin >> id;

        Equipment* temp = head;

        // prev previous node ka address rakhega
        Equipment* prev = NULL;

        // Delete karne wala node search karenge
        while (temp != NULL && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Equipment not found!\n";
            return;
        }

        if (temp->booked) {
            cout << "Return equipment before deleting!\n";
            return;
        }

        // Agar first node delete karna hai
        if (prev == NULL) {
            head = temp->next;
        }
        else {
            // Previous node ko next node se connect karenge
            prev->next = temp->next;
        }

        // Node ki allocated memory free karenge
        delete temp;

        cout << "Equipment deleted!\n";
    }

    // Destructor: Program end hone par memory free karega
    ~EquipmentManagement() {

        while (head != NULL) {
            Equipment* temp = head;

            // Head ko next node par move karenge
            head = head->next;

            // Purana node delete karenge
            delete temp;
        }
    }

    void menu() {
        int choice;

        do {
            cout << "\n===== EQUIPMENT MANAGEMENT =====\n";
            cout << "1. Add Equipment\n";
            cout << "2. Display Equipment\n";
            cout << "3. Search Equipment\n";
            cout << "4. Book Equipment\n";
            cout << "5. Return Equipment\n";
            cout << "6. Delete Equipment\n";
            cout << "0. Back\n";

            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addEquipment(); break;
                case 2: displayEquipment(); break;
                case 3: searchEquipment(); break;
                case 4: bookEquipment(); break;
                case 5: returnEquipment(); break;
                case 6: deleteEquipment(); break;
                case 0: break;
                default: cout << "Invalid choice!\n";
            }

        } while (choice != 0);
    }
};

#endif
