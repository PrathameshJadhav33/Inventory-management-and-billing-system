#include "inventory.hpp"
#include <iostream>
using namespace std;

void inv_display()
{
    cout << "\n\t\t\t---------------------------------------------------------";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t|\t\t\tInventory\t\t\t|";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t---------------------------------------------------------";
}
void inventory()
{
    int choice;
    do
    {
        system("cls");
        inv_display();
        cout << "\n\t\t\t\t1. Add product";
        cout << "\n\t\t\t\t2. Update product";
        cout << "\n\t\t\t\t3. Delete product";
        cout << "\n\t\t\t\t4. Available Stock";
        cout << "\n\t\t\t\t5. Running-out of stock";
        cout << "\n\t\t\t\t6. Out-of-stock products";
        cout << "\n\t\t\t\t7. Return to employee page";
        cout << "\n\t\t\t\t8. Exit";
        cout << "\n\n\t\t\t\tYour Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "case 1";
            break;
        case 2:
            cout << "case 2";
            break;
        case 3:
            cout << "case 1";
            break;
        case 4:
            cout << "case 2";
            break;
        case 5:
            cout << "case 1";
            break;
        case 6:
            cout << "case 2";
            break;
        case 7:
            break;
        case 8:
            exit(0);
        default:
            cout << "wrong choice!!";
        }
    } while (choice != 8);
}