#include <iostream>
#include <cstring>
using namespace std;

/* ====================== EQUIPMENT MODULE (DOUBLY LINKED LIST) ====================== */

class Equipment {
private:
    int id;
    char name[50];
    char status[20];       // "Available", "In Use", "Maintenance"
    float rentPerHour;

    // Pointers for doubly linked list
    Equipment* prev;
    Equipment* next;

    // Head of the list (first node)
    static Equipment* head;

public:
    // Constructor
    Equipment() {
        id = 0;
        name[0] = '\0';
        status[0] = '\0';
        rentPerHour = 0;
        prev = nullptr;
        next = nullptr;
    }

    // Take equipment details from user
    void input() {
        cout << "Enter Equipment ID: ";
        cin >> id;

        cout << "Enter Equipment Name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter Status (Available/In Use/Maintenance): ";
        cin.getline(status, 20);

        cout << "Enter Rent Per Hour: ";
        cin >> rentPerHour;
    }

    // Display one equipment's details
    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Status: " << status
             << " | Rent/Hr: " << rentPerHour << "\n";
    }

    // Find equipment node by ID
    static Equipment* searchById(int id) {
        Equipment* curr = head;
        while (curr) {
            if (curr->id == id) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;  // not found
    }

    // Add new equipment at the beginning of the list
    static void addEquipment() {
        Equipment* temp = new Equipment();  // create new node
        temp->input();                      // take input

        // If list is empty
        if (!head) {
            head = temp;
        } else {
            // Insert at beginning
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        cout << "Equipment added.\n";
    }

    // Show all equipment from head to end
    static void listEquipment() {
        if (!head) {
            cout << "No equipment available.\n";
            return;
        }

        Equipment* curr = head;
        while (curr) {
            curr->display();
            curr = curr->next;  // move to next node
        }
    }

    // Update equipment details by ID
    static void updateEquipment() {
        int id;
        cout << "Enter Equipment ID to update: ";
        cin >> id;

        Equipment* node = searchById(id);
        if (!node) {
            cout << "Equipment not found.\n";
            return;
        }

        cout << "Enter new details for this equipment:\n";
        node->input();

        cout << "Equipment updated.\n";
    }

    // Delete equipment by ID
    static void deleteEquipment() {
        int id;
        cout << "Enter Equipment ID to delete: ";
        cin >> id;

        Equipment* node = searchById(id);
        if (!node) {
            cout << "Equipment not found.\n";
            return;
        }

        // If node to delete is head
        if (node == head) {
            head = node->next;
            if (head) {
                head->prev = nullptr;
            }
        } else {
            // Adjust links of previous node
            if (node->prev) {
                node->prev->next = node->next;
            }
            // Adjust links of next node
            if (node->next) {
                node->next->prev = node->prev;
            }
        }

        delete node;  // free memory
        cout << "Equipment deleted.\n";
    }
};

// Initialize static head pointer
Equipment* Equipment::head = nullptr;