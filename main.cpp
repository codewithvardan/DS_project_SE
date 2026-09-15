#include <iostream>
using namespace std;

#include "crop.cpp"
#include "equipment.cpp"
#include "finance.cpp"
#include "farmer.cpp"
#include "production.cpp"

// Forward declarations for menus
void cropMenu();
void equipmentMenu();
void farmerMenu();
void financeMenu();
void productionMenu();

int main() {
    while (true) {
        cout << "\n=== Farm Crop & Equipment Management System ===\n";
        cout << "1. Crops\n";
        cout << "2. Equipment\n";
        cout << "3. Farmers\n";
        cout << "4. Finance\n";
        cout << "5. Crop Production Records\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        int ch;
        cin >> ch;

        if (ch == 1)
            cropMenu();
        else if (ch == 2)
            equipmentMenu();
        else if (ch == 3)
            farmerMenu();
        else if (ch == 4)
            financeMenu();
        else if (ch == 5)
            productionMenu();
        else if (ch == 6)
            break;
        else
            cout << "Invalid choice.\n";
    }

    cout << "Exited.\n";
    return 0;
}

// ---------- Sub-menus ----------

void cropMenu() {
    while (true) {
        cout << "\n--- Crop Menu ---\n";
        cout << "1. Add Crop\n";
        cout << "2. List Crops\n";
        cout << "3. Update Crop\n";
        cout << "4. Delete Crop\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";

        int ch;
        cin >> ch;

        if (ch == 1)
            Crop::addCrop();
        else if (ch == 2)
            Crop::listCrops();
        else if (ch == 3)
            Crop::updateCrop();
        else if (ch == 4)
            Crop::deleteCrop();
        else if (ch == 5)
            break;
        else
            cout << "Invalid choice.\n";
    }
}

void equipmentMenu() {
    while (true) {
        cout << "\n--- Equipment Menu ---\n";
        cout << "1. Add Equipment\n";
        cout << "2. List Equipment\n";
        cout << "3. Update Equipment\n";
        cout << "4. Delete Equipment\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";

        int ch;
        cin >> ch;

        if (ch == 1)
            Equipment::addEquipment();
        else if (ch == 2)
            Equipment::listEquipment();
        else if (ch == 3)
            Equipment::updateEquipment();
        else if (ch == 4)
            Equipment::deleteEquipment();
        else if (ch == 5)
            break;
        else
            cout << "Invalid choice.\n";
    }
}

void farmerMenu() {
    while (true) {
        cout << "\n--- Farmer Menu ---\n";
        cout << "1. Add Farmer\n";
        cout << "2. List Farmers\n";
        cout << "3. Update Farmer\n";
        cout << "4. Delete Farmer\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";

        int ch;
        cin >> ch;

        if (ch == 1)
            Farmer::addFarmer();
        else if (ch == 2)
            Farmer::listFarmers();
        else if (ch == 3)
            Farmer::updateFarmer();
        else if (ch == 4)
            Farmer::deleteFarmer();
        else if (ch == 5)
            break;
        else
            cout << "Invalid choice.\n";
    }
}

void financeMenu() {
    while (true) {
        cout << "\n--- Finance Menu ---\n";
        cout << "1. Add Transaction\n";
        cout << "2. List Transactions\n";
        cout << "3. Delete Transaction\n";
        cout << "4. Show Summary (Income/Expense/Profit)\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";

        int ch;
        cin >> ch;

        if (ch == 1)
            Finance::addTransaction();
        else if (ch == 2)
            Finance::listTransactions();
        else if (ch == 3)
            Finance::deleteTransaction();
        else if (ch == 4)
            Finance::showSummary();
        else if (ch == 5)
            break;
        else
            cout << "Invalid choice.\n";
    }
}

void productionMenu() {
    while (true) {
        cout << "\n--- Crop Production Menu ---\n";
        cout << "1. Add Production Record\n";
        cout << "2. List Production Records\n";
        cout << "3. Crop-wise Summary\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";

        int ch;
        cin >> ch;

        if (ch == 1)
            Production::addRecord();
        else if (ch == 2)
            Production::listRecords();
        else if (ch == 3)
            Production::showCropWiseSummary();
        else if (ch == 4)
            break;
        else
            cout << "Invalid choice.\n";
    }
}