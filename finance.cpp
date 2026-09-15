#include <iostream>
#include <cstring>
using namespace std;

/* ====================== FINANCE MODULE (DOUBLY LINKED LIST) ====================== */

class Finance {
private:
    int id;
    char type[20];         // "Income" or "Expense"
    char category[30];     // "Crop Sale", "Seeds", "Wages", etc.
    float amount;
    int date;              // YYYYMMDD

    // Doubly linked list pointers
    Finance* prev;
    Finance* next;

    static Finance* head;
    static int nextId;     // to generate unique IDs

public:
    Finance() {
        id = 0;
        type[0] = '\0';
        category[0] = '\0';
        amount = 0;
        date = 0;
        prev = nullptr;
        next = nullptr;
    }

    void input() {
        cout << "Enter Type (Income/Expense): ";
        cin >> type;

        cout << "Enter Category: ";
        cin.ignore();
        cin.getline(category, 30);

        cout << "Enter Amount: ";
        cin >> amount;

        cout << "Enter Date (YYYYMMDD): ";
        cin >> date;

        id = nextId++;  // assign unique ID
    }

    void display() const {
        cout << "ID: " << id
             << " | Type: " << type
             << " | Category: " << category
             << " | Amount: " << amount
             << " | Date: " << date << "\n";
    }

    // Add new transaction at the end of the list
    static void addTransaction() {
        Finance* temp = new Finance();
        temp->input();

        if (!head) {
            // List is empty
            head = temp;
        } else {
            // Go to last node
            Finance* curr = head;
            while (curr->next) {
                curr = curr->next;
            }

            // Link new node at the end
            curr->next = temp;
            temp->prev = curr;
        }

        cout << "Transaction added.\n";
    }

    static void listTransactions() {
        if (!head) {
            cout << "No transactions.\n";
            return;
        }

        Finance* curr = head;
        while (curr) {
            curr->display();
            curr = curr->next;
        }
    }

    static void deleteTransaction() {
        int id;
        cout << "Enter Transaction ID to delete: ";
        cin >> id;

        // Find node
        Finance* curr = head;
        while (curr && curr->id != id) {
            curr = curr->next;
        }

        if (!curr) {
            cout << "Transaction not found.\n";
            return;
        }

        // Adjust links
        if (curr == head) {
            head = curr->next;
            if (head) {
                head->prev = nullptr;
            }
        } else {
            if (curr->prev) {
                curr->prev->next = curr->next;
            }
            if (curr->next) {
                curr->next->prev = curr->prev;
            }
        }

        delete curr;
        cout << "Transaction deleted.\n";
    }

    static void showSummary() {
        float totalIncome = 0, totalExpense = 0;

        Finance* curr = head;
        while (curr) {
            if (strcmp(curr->type, "Income") == 0) {
                totalIncome += curr->amount;
            } else if (strcmp(curr->type, "Expense") == 0) {
                totalExpense += curr->amount;
            }
            curr = curr->next;
        }

        cout << "Total Income: " << totalIncome << "\n";
        cout << "Total Expense: " << totalExpense << "\n";
        cout << "Profit/Loss: " << (totalIncome - totalExpense) << "\n";
    }
};

// Define static members for Finance
Finance* Finance::head = nullptr;
int Finance::nextId = 1;