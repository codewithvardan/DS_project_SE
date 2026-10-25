
#ifndef CROP_H
#define CROP_H

#include <iostream>
#include <string>
using namespace std;

// Ye class ek crop ki information store karti hai
class Crop {
private:
    int id;
    string name;
    int quantity;

public:
    // Constructor: Starting mein values initialize karenge
    Crop() {
        id = 0;
        quantity = 0;
    }

    // User se crop ki details lene ke liye
    void input() {
        cout << "Enter Crop ID: ";
        cin >> id;

        cout << "Enter Crop Name: ";
        cin >> name;

        cout << "Enter Quantity (kg): ";
        cin >> quantity;
    }

    // Ek crop ki details display karenge
    void display() {
        cout << id << "\t" << name
             << "\t" << quantity << " kg\n";
    }

    // Crop ka ID return karega
    int getId() {
        return id;
    }
};

// Ye class saare crops ko array mein manage karegi
class CropManagement {
private:
    Crop crops[100]; // Maximum 100 crops store kar sakte hain
    int count;       // Abhi kitne crops store hain

public:
    CropManagement() {
        count = 0; // Starting mein array empty hai
    }

    // Naya crop add karna
    void addCrop() {

        // Check karenge array full toh nahi
        if (count >= 100) {
            cout << "Crop storage full!\n";
            return;
        }

        // Next empty position par details lenge
        crops[count].input();

        // Duplicate ID check karenge
        for (int i = 0; i < count; i++) {
            if (crops[i].getId() == crops[count].getId()) {
                cout << "Crop ID already exists!\n";
                return;
            }
        }

        count++; // Ek crop add hua, isliye count badhayenge

        cout << "Crop added successfully!\n";
    }

    // Saare crops display karna
    void displayCrops() {

        if (count == 0) {
            cout << "No crops available.\n";
            return;
        }

        cout << "ID\tName\tQuantity\n";

        // Loop se array ke saare elements print karenge
        for (int i = 0; i < count; i++) {
            crops[i].display();
        }
    }

    // ID ke through crop search karna
    void searchCrop() {
        int id;

        cout << "Enter Crop ID: ";
        cin >> id;

        // Linear Search use kiya hai
        for (int i = 0; i < count; i++) {

            if (crops[i].getId() == id) {
                crops[i].display();
                return; // Crop mil gaya, function stop
            }
        }

        cout << "Crop not found!\n";
    }

    // Existing crop ki details update karna
    void updateCrop() {
        int id;

        cout << "Enter Crop ID to update: ";
        cin >> id;

        for (int i = 0; i < count; i++) {

            if (crops[i].getId() == id) {

                cout << "Enter new crop details:\n";

                // Purana ID same rakhenge
                // Sirf name aur quantity update karenge
                string newName;
                int newQuantity;

                cout << "Enter New Name: ";
                cin >> newName;

                cout << "Enter New Quantity: ";
                cin >> newQuantity;

                // Crop class ka update function call karenge
                crops[i].update(newName, newQuantity);

                cout << "Crop updated!\n";
                return;
            }
        }

        cout << "Crop not found!\n";
    }

    // Crop delete karna
    void deleteCrop() {
        int id;

        cout << "Enter Crop ID to delete: ";
        cin >> id;

        for (int i = 0; i < count; i++) {

            if (crops[i].getId() == id) {

                // Delete ke baad empty gap nahi chahiye
                // Isliye next elements ko ek position left shift karenge
                for (int j = i; j < count - 1; j++) {
                    crops[j] = crops[j + 1];
                }

                count--; // Total crops ek kam ho gaye

                cout << "Crop deleted!\n";
                return;
            }
        }

        cout << "Crop not found!\n";
    }

    // Crop module ka menu
    void menu() {
        int choice;

        do {
            cout << "\n===== CROP MANAGEMENT =====\n";
            cout << "1. Add Crop\n";
            cout << "2. Display Crops\n";
            cout << "3. Search Crop\n";
            cout << "4. Update Crop\n";
            cout << "5. Delete Crop\n";
            cout << "0. Back\n";

            cout << "Enter choice: ";
            cin >> choice;

            // User ki choice ke according function call hoga
            switch (choice) {
                case 1: addCrop(); break;
                case 2: displayCrops(); break;
                case 3: searchCrop(); break;
                case 4: updateCrop(); break;
                case 5: deleteCrop(); break;
                case 0: break;
                default: cout << "Invalid choice!\n";
            }

        } while (choice != 0); // 0 tak menu repeat hoga
    }
};

#endif
