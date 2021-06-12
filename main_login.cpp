#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "admin_login.hpp"
#include "employee_login.hpp"
using namespace std;
#define password "ok"
#define username "admin"
void main_display()
{
    cout << "\n\t\t\t---------------------------------------------------------";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t|\t\tInventory and Billing System\t\t|";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t|\t\t\tLogin Page\t\t\t|";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t---------------------------------------------------------";
}

int main()
{
    int choice;
    do
    {
        system("cls");
        main_display();
        cout << "\n\n\t\t\t\t1. Admin Login";
        cout << "\n\t\t\t\t2. Employee Login";
        cout << "\n\t\t\t\t3. Exit";
        cout << "\n\n\t\t\t\tYour Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            admin();
            break;
        case 2:
            emp();
            break;
        case 3:
            exit(0);
        default:
            cout << "wrong choice!!";
        }
    } while (choice != 3);
cout<<endl;
}
