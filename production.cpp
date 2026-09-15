#include <iostream>
#include <string>
using namespace std;

/* ====================== PRODUCTION MODULE (DOUBLY LINKED LIST) ====================== */

class Production {
private:
    int cropId;
    int harvestDate;       // YYYYMMDD
    float yieldAmount;     // quintals
    float sellingPrice;    // per quintal
    float totalRevenue;

    // Doubly linked list pointers
    Production* prev;
    Production* next;

    static Production* head;

public:
    Production() {
        cropId = 0;
        harvestDate = 0;
        yieldAmount = 0;
        sellingPrice = 0;
        totalRevenue = 0;
        prev = nullptr;
        next = nullptr;
    }

    void input() {
        cout << "Enter Crop ID: ";
        cin >> cropId;

        cout << "Enter Harvest Date (YYYYMMDD): ";
        cin >> harvestDate;

        cout << "Enter Yield Amount (quintals): ";
        cin >> yieldAmount;

        cout << "Enter Selling Price per Quintal: ";
        cin >> sellingPrice;

        totalRevenue = yieldAmount * sellingPrice;
    }

    void display() const {
        cout << "Crop ID: " << cropId
             << " | Date: " << harvestDate
             << " | Yield: " << yieldAmount
             << " | Price/Qt: " << sellingPrice
             << " | Revenue: " << totalRevenue << "\n";
    }

    // Add new production record at the end
    static void addRecord() {
        Production* temp = new Production();
        temp->input();

        if (!head) {
            head = temp;
        } else {
            Production* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = temp;
            temp->prev = curr;
        }

        cout << "Production record added.\n";
    }

    static void listRecords() {
        if (!head) {
            cout << "No production records.\n";
            return;
        }

        Production* curr = head;
        while (curr) {
            curr->display();
            curr = curr->next;
        }
    }

    // For now, just show all records (you can extend later)
    static void showCropWiseSummary() {
        if (!head) {
            cout << "No production records.\n";
            return;
        }

        cout << "All production records (group by Crop ID manually):\n";
        listRecords();
    }
};

// Define static members for Production
Production* Production::head = nullptr;