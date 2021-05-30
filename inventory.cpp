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
        cout << "\n\t\t\t\t4. in-purchase product";
        cout << "\n\t\t\t\t5. Pending orders";
        cout << "\n\t\t\t\t6. Order Charts";
        cout << "\n\t\t\t\t7. Purchase history";
        cout << "\n\t\t\t\t8. Return to employee page";
        cout << "\n\t\t\t\t9. Exit";
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
            cout << "case 1";
            break;
        case 8:
            break;
        case 9:
            exit(0);
        default:
            cout << "wrong choice!!";
        }
    } while (choice != 8);
}