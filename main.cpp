
#include <iostream>
using namespace std;

// Saare module ki header files include karenge
#include "Crop.h"
#include "Equipment.h"
#include "Farmer.h"
#include "Finance.h"
#include "Production.h"

int main() {

    // Har module ka ek object banayenge
    // Object se us module ke functions access kar sakte hain

    CropManagement crop;
    EquipmentManagement equipment;
    FarmerManagement farmer;
    InventoryManagement inventory;
    FinanceManagement finance;
    ProductionManagement production;

    int choice;

    // do-while loop menu ko baar-baar display karega
    do {
        cout << "\n================================\n";
        cout << "       KRISHI SAHAYAK\n";
        cout << " Farm Crop & Equipment System\n";
        cout << "================================\n";

        cout << "1. Crop Management\n";
        cout << "2. Equipment Management\n";
        cout << "3. Farmer Management\n";
        cout << "4. Inventory Management\n";
        cout << "5. Finance Management\n";
        cout << "6. Production Management\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        // User ki choice ke according module open hoga
        switch (choice) {

            case 1:
                crop.menu(); // Crop module ka menu
                break;

            case 2:
                equipment.menu(); // Equipment module
                break;

            case 3:
                farmer.menu(); // Farmer module
                break;

            case 4:
                inventory.menu(); // Inventory module
                break;

            case 5:
                finance.menu(); // Finance module
                break;

            case 6:
                production.menu(); // Production module
                break;

            case 0:
                // User 0 enter karega toh program close
                cout << "\nThank you for using Krishi Sahayak!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0; // Program successfully terminate
}
