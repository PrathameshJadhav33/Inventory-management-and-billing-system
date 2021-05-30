#include "billing.hpp"
#include <iostream>
using namespace std;

void bil_header()
{
    cout << "\n\t\t\t---------------------------------------------------------";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t|\t\t\tBill Generation\t\t\t|";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t---------------------------------------------------------";
}
void billing()
{
    int choice;
    do
    {
        system("cls");
        bil_header();
        cout << "\n\n\t\t\t\t1. Generate new";
        cout << "\n\t\t\t\t2. View Bills";
        cout << "\n\t\t\t\t3. Return to employee page";
        cout << "\n\t\t\t\t4. Exit";
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
            break;
        case 4:
            exit(0);
        default:
            cout << "wrong choice!!";
        }
    } while (choice != 3);
}