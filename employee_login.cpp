#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include<windows.h>

#include "billing.hpp"
#include "report.hpp"
using namespace std;
#define password "ok"
#define username "emp1"
void emp_display()
{
    cout << "\n\t\t\t---------------------------------------------------------";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t|\t\tInventory and Billing System\t\t|";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t|\t\t\tEmployee Page\t\t\t|";
    cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
    cout << "\n\t\t\t---------------------------------------------------------";
}
bool emp_login(bool flag)
{
    string pass, user;
    int tries = 0;
    do
    {
        system("cls");
        emp_display();
        cout << "\n\n\t\t\t\t Enter Username:";
        cin >> user;
        if (user == username)
        {
            cout << "\n\t\t\t\t Enter password:";
            cin >> pass;
            if (pass == password)
            {
                flag = true;
            }
            else
            {
                cout << "\n\t\t\t\t \033[1;31m Wrong Password!!\033[0m";
                tries++;
            }
        }
        else
        {
            cout << "\n\t\t\t\t\033[1;31m Wrong username!!\033[0m";
            tries++;
        }

        if (tries == 3)
        {
            cout << "\n\t\t\t\t\033[1;31m Authentication Failed\033[0m";
        }
        Sleep(1000);
    } while (flag == false && tries < 3);
    return flag;
}
void emp()
{
    bool flag = false;
    int choice;
    flag = emp_login(flag);
    if (flag)
    {
        do
        {
            system("cls");
            emp_display();
            cout << "\n\n\t\t\t\t1. Billing";
            cout << "\n\t\t\t\t2. Report";
            cout << "\n\t\t\t\t3. Return to main login";
            cout << "\n\n\t\t\t\tYour Choice:";
            cin >> choice;
            switch (choice)
            {
            case 1:
                billing();
                break;
            case 2:
                report();
                break;
            case 3:
                break;
            default:
                cout << "wrong choice!!";
            }
        } while (choice != 3);
    }
}
