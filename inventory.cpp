#include "inventory.hpp"
#include "database_testing_1.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>

#include "sqlite3.h"

using namespace std;

class data{
private:
    sqlite3 *db1;
    char *zErrMsg;
    int rc;

    char const *sql;
    string sql2;

    char const *data;

    int id,qty;
    char choice;
    string name,category;
    float price;

    stringstream ss;

    int stay;

    sqlite3_stmt* stmt;
public:
    void open_db()
    {
        data="\n\t callback invoked";
        zErrMsg =0;
        //open database or create if does not exist
        rc = sqlite3_open("/D:/KIT/Semester 4/mini project/inventory.db", &db1);

        //check for errors in creation or opening
        if (rc)
        {
            cout << "\n\tUnable to open database";
            cout << "\n\tError:" << sqlite3_errmsg(db1);
        }
        /*
        else
        {
            cout << "\n\t database opened successfully";
        }
        */
    }


    void create()
    {
        //sql query to create
        sql = "CREATE TABLE STOCK("
              "ID     INT PRIMARY KEY NOT NULL,"
              "NAME   TEXT            NOT NULL,"
              "CATEGORY TEXT          NOT NULL,"
              "PRICE  INT            NOT NULL,"
              "QTY    INT             NOT NULL);";

        //executes sql query to create STOCK table
        rc = sqlite3_exec(db1, sql, NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            cout << "\n\tUnable to create table";
            cout << "\n\tError:" << zErrMsg;
            sqlite3_free(zErrMsg);
        }
        /*
        else
        {
            cout << "\n\t Table created successfully";
        }
        */
    }

    void add_product(){
        system("cls");
        inv_display();
        open_db();
        cout << "\n\t\t\t\t1. Product id:\t";
        cin >> id;
        cout << "\n\t\t\t\t2. Product Name:\t";
        cin >> name;
        cout << "\n\t\t\t\t3. Product Category:\t";
        cin >> category;
        cout << "\n\t\t\t\t4. Product Price(1 unit):\t";
        cin >> price;
        cout << "\n\t\t\t\t5. Total Quantity:\t";
        cin >> qty;
        cout << "\n\n\t\t\t\t Add product to database?(y/n):\t";
        cin >> choice;

        //sql2 = "INSERT INTO STOCK VALUES ("+id1+","+name+","+category+","+price1+","+qty1+");";
        sql2 = "INSERT INTO STOCK VALUES (?,?,?,?,?);";
        sqlite3_prepare_v2(db1,sql2.c_str(),sql2.length(),&stmt, NULL);
        sqlite3_bind_int(stmt,1,id);
        sqlite3_bind_text(stmt,2,name.c_str(),name.length(),NULL);
        sqlite3_bind_text(stmt,3,category.c_str(),category.length(),NULL);
        sqlite3_bind_int(stmt,4,price);
        sqlite3_bind_int(stmt,5,qty);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        //rc = sqlite3_exec(db1, stmt, callback, (void *)data, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            //cout << "\n\tunable to INSERT RECORD";
            cout << "\n\tError:" << zErrMsg;
            sqlite3_free(zErrMsg);
        }
        /*
        else
        {
            cout << "\n\t\t RECORD created successfully";
        }*/

        cin >> stay;
        sqlite3_close(db1);
    }

     void select()
    {
        //sql select query
        open_db();
        sql = "SELECT * FROM STOCK";
        rc = sqlite3_exec(db1, sql, callback, (void *)data, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            //cout << "\n\tunable to FETCH RECORD";
            cout << "\n\tError:" << zErrMsg;
            sqlite3_free(zErrMsg);
        }
        else
        {
            cout << "\n\t\t RECORDS fetched successfully";
        }
        cin >> stay;
        sqlite3_close(db1);
    }

     static int callback(void *data, int col_in_row, char **fields_in_row, char **Col_names)
    {
        //cout << (const char *)data;
        cout <<"\n";
        for (int i = 0; i < col_in_row; i++)
        {
            cout << "\t\t" << Col_names[i];
        }
        cout << "\n";

        for (int i = 0; i < col_in_row; i++)
        {
            cout << "\t\t" << fields_in_row[i];
        }

        cout << "\n";
        return 0;
    }

    void inv_display()
    {
        cout << "\n\t\t\t---------------------------------------------------------";
        cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
        cout << "\n\t\t\t|\t\t\tInventory\t\t\t|";
        cout << "\n\t\t\t|\t\t\t\t\t\t\t|";
        cout << "\n\t\t\t---------------------------------------------------------";
    }

};
void inventory()
{
    int choice;
    data obj;
    do
    {
        system("cls");
        obj.inv_display();
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
            obj.add_product();
            break;
        case 2:
            cout << "case 2";
            db_test();
            break;
        case 3:
            cout << "case 1";
            break;
        case 4:
            cout << "case 2";
            obj.select();
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
    } while (choice != 7);
}
