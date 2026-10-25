
#ifndef FARMER_H
#define FARMER_H

#include <iostream>
#include <string>
using namespace std;

// Ek farmer ki details store karne wali class
class Farmer {
public:
    int id;
    string name;
    int days;
    float dailyWage;

    // Farmer ki details input lena
    void input() {
        cout << "Enter Farmer ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Working Days: ";
        cin >> days;

        cout << "Enter Daily Wage: ";
        cin >> dailyWage;
    }

    void display() {
        // Total wage = working days * daily wage
        cout << id << "\t" << name << "\t"
             << days << "\t" << dailyWage
             << "\t" << days * dailyWage << endl;
    }
};

class FarmerManagement {
private:
    Farmer farmers[100]; // Farmer objects ka array
    int count;

public:
    FarmerManagement() {
        count = 0;
    }

    // ID se farmer ki array position find karna
    int findFarmer(int id) {
        for (int i = 0; i < count; i++) {
            if (farmers[i].id == id)
                return i;
        }

        return -1; // Farmer nahi mila
    }

    void addFarmer() {
        if (count == 100) {
            cout << "Storage full!\n";
            return;
        }

        // Next empty position par input lenge
        farmers[count].input();

        // Same ID dobara add nahi hone denge
        if (findFarmer(farmers[count].id) != -1) {
            cout << "Farmer ID already exists!\n";
            return;
        }

        if (farmers[count].days < 0 ||
            farmers[count].dailyWage < 0) {
            cout << "Invalid days or wage!\n";
            return;
        }

        count++;
        cout << "Farmer added!\n";
    }

    void displayFarmers() {
        if (count == 0) {
            cout << "No farmers found!\n";
            return;
        }

        cout << "ID\tName\tDays\tWage\tTotal\n";

        // Array traverse karke saare farmers print
        for (int i = 0; i < count; i++) {
            farmers[i].display();
        }
    }

    void searchFarmer() {
        int id;
        cout << "Enter Farmer ID: ";
        cin >> id;

        int pos = findFarmer(id);

        if (pos == -1)
            cout << "Farmer not found!\n";
        else
            farmers[pos].display();
    }

    void updateFarmer() {
        int id;
        cout << "Enter Farmer ID: ";
        cin >> id;

        int pos = findFarmer(id);

        if (pos == -1) {
            cout << "Farmer not found!\n";
            return;
        }

        // ID same rahega, baaki details change hongi
        cout << "Enter New Name: ";
        cin >> farmers[pos].name;

        cout << "Enter Working Days: ";
        cin >> farmers[pos].days;

        cout << "Enter Daily Wage: ";
        cin >> farmers[pos].dailyWage;

        cout << "Farmer updated!\n";
    }

    void deleteFarmer() {
        int id;
        cout << "Enter Farmer ID: ";
        cin >> id;

        int pos = findFarmer(id);

        if (pos == -1) {
            cout << "Farmer not found!\n";
            return;
        }

        // Delete hone ke baad remaining elements left shift
        for (int i = pos; i < count - 1; i++) {
            farmers[i] = farmers[i + 1];
        }

        count--;
        cout << "Farmer deleted!\n";
    }

    void totalWages() {
        float total = 0;

        // Har farmer ki wage calculate karke add karenge
        for (int i = 0; i < count; i++) {
            total += farmers[i].days * farmers[i].dailyWage;
        }

        cout << "Total Farmer Wages: Rs. "
             << total << endl;
    }

    void menu() {
        int choice;

        do {
            cout << "\n===== FARMER MANAGEMENT =====\n";
            cout << "1. Add Farmer\n";
            cout << "2. Display Farmers\n";
            cout << "3. Search Farmer\n";
            cout << "4. Update Farmer\n";
            cout << "5. Delete Farmer\n";
            cout << "6. Calculate Total Wages\n";
            cout << "0. Back\n";

            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addFarmer(); break;
                case 2: displayFarmers(); break;
                case 3: searchFarmer(); break;
                case 4: updateFarmer(); break;
                case 5: deleteFarmer(); break;
                case 6: totalWages(); break;
                case 0: break;
                default: cout << "Invalid choice!\n";
            }

        } while (choice != 0);
    }
};

#endif
