#include "report.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void report_header()
{
    cout << "\n\t\t\t---------------------------------------------------------";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t|\t\t\t\tReport\t\t\t|";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t---------------------------------------------------------";
}
void report()
{
    int choice;
    do
    {
        system("cls");
        report_header();
        cout << "\n\n\t\t\t\t1. Stock Sales Chart";
        cout << "\n\t\t\t\t2. Today's sales";
        cout << "\n\t\t\t\t3. Customers Favourite";
        cout << "\n\t\t\t\t4. Return to employee page";
        cout << "\n\t\t\t\t5. Exit";
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
            cout << "case 3";
            break;
        case 4:
            break;
        case 5:
            exit(0);
        default:
            cout << "wrong choice!!";
        }
    } while (choice != 4);
}
