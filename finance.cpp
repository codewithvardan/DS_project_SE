
#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>
#include <string>
using namespace std;

// Linked List ka ek transaction node
class Transaction {
public:
    int id;
    string type;
    string description;
    float amount;

    // Next transaction ka address
    Transaction* next;

    // Constructor: Node ki values set karenge
    Transaction(int i, string t, string d, float a) {
        id = i;
        type = t;
        description = d;
        amount = a;
        next = NULL;
    }
};

class FinanceManagement {
private:
    Transaction* head; // First transaction ka address
    int nextId;         // Automatic transaction ID

public:
    FinanceManagement() {
        head = NULL;
        nextId = 1;
    }

    // Income ya Expense add karne ke liye
    void addTransaction(string type) {
        string description;
        float amount;

        cout << "Enter Description: ";
        cin >> description;

        cout << "Enter Amount: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }

        // Memory mein naya transaction node banega
        Transaction* node =
            new Transaction(nextId, type, description, amount);

        nextId++; // Next transaction ke liye ID badhayenge

        if (head == NULL) {
            // Agar list empty hai toh first node head banega
            head = node;
        }
        else {
            Transaction* temp = head;

            // Linked list ke last node tak jayenge
            while (temp->next != NULL) {
                temp = temp->next;
            }

            // Last node ke baad new node connect
            temp->next = node;
        }

        cout << "Transaction added!\n";
    }

    // Saare income aur expense records display karna
    void displayTransactions() {
        if (head == NULL) {
            cout << "No transactions!\n";
            return;
        }

        Transaction* temp = head;

        cout << "ID\tType\tDescription\tAmount\n";

        // Linked list traverse karenge
        while (temp != NULL) {
            cout << temp->id << "\t"
                 << temp->type << "\t"
                 << temp->description << "\t"
                 << temp->amount << endl;

            // Next transaction par move
            temp = temp->next;
        }
    }

    // Profit aur Loss calculate karna
    void calculateProfitLoss() {
        float income = 0;
        float expense = 0;

        Transaction* temp = head;

        while (temp != NULL) {

            // Income hai toh income variable mein add
            if (temp->type == "Income") {
                income += temp->amount;
            }
            else {
                // Otherwise expense mein add
                expense += temp->amount;
            }

            temp = temp->next;
        }

        cout << "\nTotal Income: Rs. " << income;
        cout << "\nTotal Expense: Rs. " << expense;

        // Formula: Profit/Loss = Income - Expense
        float result = income - expense;

        if (result > 0) {
            cout << "\nProfit: Rs. " << result << endl;
        }
        else if (result < 0) {
            cout << "\nLoss: Rs. " << -result << endl;
        }
        else {
            cout << "\nNo Profit No Loss\n";
        }
    }

    // Destructor: Program end par saare nodes delete
    ~FinanceManagement() {
        while (head != NULL) {
            Transaction* temp = head;
            head = head->next;

            // Dynamically allocated memory free
            delete temp;
        }
    }

    void menu() {
        int choice;

        do {
            cout << "\n===== FINANCE MANAGEMENT =====\n";
            cout << "1. Add Income\n";
            cout << "2. Add Expense\n";
            cout << "3. Display Transactions\n";
            cout << "4. Calculate Profit/Loss\n";
            cout << "0. Back\n";

            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addTransaction("Income"); break;
                case 2: addTransaction("Expense"); break;
                case 3: displayTransactions(); break;
                case 4: calculateProfitLoss(); break;
                case 0: break;
                default: cout << "Invalid choice!\n";
            }

        } while (choice != 0);
    }
};

#endif
