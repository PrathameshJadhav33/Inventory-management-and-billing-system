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
    char opt;

    sqlite3_stmt* stmt;
public:
    void open_db()
    {
        data="\n\t callback invoked";
        zErrMsg =0;
        stay=0;
        //open database or create if does not exist
        rc = sqlite3_open("/D:/KIT/Semester 4/mini project/inventory.db", &db1);

        //check for errors in creation or opening
        if (rc)
        {
            cout << "\n\tUnable to open database";
            cout << "\n\tError:" << sqlite3_errmsg(db1);
        }
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
    }

    void add_product(){
        system("cls");
        inv_display();
        open_db();
        cout << "\n\n\t\t\t\t1. Product id:\t";
        cin >> id;
        cout << "\n\t\t\t\t2. Product Name:\t";
        cin.get();
        getline(cin,name);
        cout << "\n\t\t\t\t3. Product Category:\t";
        cin.get();
        getline(cin,category);
        cout << "\n\t\t\t\t4. Product Price(1 unit):\t";
        cin >> price;
        cout << "\n\t\t\t\t5. Total Quantity:\t";
        cin >> qty;
        cout << "\n\n\t\t\t\t Add product to database?(y/n):\t";
        cin >> opt;

            if(opt=='y'){

                sql2 = "INSERT INTO STOCK VALUES (?,?,?,?,?);";
                rc=sqlite3_prepare_v2(db1,sql2.c_str(),sql2.length(),&stmt, NULL);
                sqlite3_bind_int(stmt,1,id);
                sqlite3_bind_text(stmt,2,name.c_str(),name.length(),NULL);
                sqlite3_bind_text(stmt,3,category.c_str(),category.length(),NULL);
                sqlite3_bind_int(stmt,4,price);
                sqlite3_bind_int(stmt,5,qty);

                sqlite3_step(stmt);
                sqlite3_finalize(stmt);

                    if (rc != SQLITE_OK)
                    {
                        cout << "\n\t\t\t\tunable to INSERT RECORD";
                        cout << "\n\t\t\t\tError:" << zErrMsg;
                        sqlite3_free(zErrMsg);
                    }
                    else
                    {
                        cout << "\n\t\t\t\tProduct added to database successfully";
                    }
            }

        cout<<"\n\t\t\t\tEnter 1 to exit : ";
            while(stay!=1){
                 cin >> stay;
            }
        sqlite3_close(db1);
    }

    void update_product(){

        system("cls");
        inv_display();
        select();
        open_db();

        cout << "\n\n\t\t\t\tEnter product id:";
        cin >> id;

        cout << "\n\t\t\t\tEnter product new Quantity:";
        cin >> qty;

        cout << "\n\n\t\t\t\tUpdate product?(y/n):\t";
        cin >> opt;

        if(opt=='y'){

            sql2 = "UPDATE STOCK set QTY = ? where ID = ?; SELECT * from STOCK";
            rc=sqlite3_prepare_v2(db1,sql2.c_str(),sql2.length(),&stmt, NULL);
            sqlite3_bind_int(stmt,1,qty);
            sqlite3_bind_int(stmt,2,id);

            sqlite3_step(stmt);
            sqlite3_finalize(stmt);

                    if (rc != SQLITE_OK)
                    {
                        cout << "\n\t\t\t\tunable to Update product";
                        cout << "\n\t\t\t\tError:" << zErrMsg;
                        sqlite3_free(zErrMsg);
                    }
                    else
                    {
                        cout << "\n\t\t\t\tProduct updated successfully";
                    }
        }

        cout<<"\n\t\t\t\tEnter 1 to exit : ";
        while(stay!=1){
             cin >> stay;
        }
        sqlite3_close(db1);
    }

    void del_product(){
        system("cls");
        inv_display();
        open_db();

        cout << "\n\n\t\t\t\tEnter product id:";
        cin >> id;

        cout << "\n\n\t\t\t\tUpdate product?(y/n):\t";
        cin >> opt;

        if(opt=='y'){

        sql2 = "DELETE from STOCK where ID = ?; SELECT * from STOCK";
        rc=sqlite3_prepare_v2(db1,sql2.c_str(),sql2.length(),&stmt, NULL);
        sqlite3_bind_int(stmt,1,id);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

            if (rc != SQLITE_OK)
            {
                cout << "\n\t\t\t\tunable to delete product";
                cout << "\n\t\t\t\tError:" << zErrMsg;
                sqlite3_free(zErrMsg);
            }
            else
            {
                cout << "\n\t\t\t\tProduct deleted successfully";
            }

        }

        cout<<"\n\t\t\t\tEnter 1 to exit : ";
        while(stay!=1){
             cin >> stay;
        }
        sqlite3_close(db1);

    }

    void search(){
        open_db();
        do{
            system("cls");
            inv_display();
            cout << "\n\t\t\t\t1.Search By id";
            cout << "\n\t\t\t\t2.Search By Name";
            cout << "\n\t\t\t\t3.Exit";
            cout << "\n\t\t\t\tYour choice:";
            cin >> stay;
            switch(stay){
            case 1:
                sql = "SELECT * FROM STOCK where ID = ?";
                cout <<"\n";
                cout <<"\n\n\t\tID\t\tName\t\tCategory\tPrice\t\tQuantity";

                rc = sqlite3_exec(db1, sql, callback, (void *)data, &zErrMsg);
                    if (rc != SQLITE_OK)
                    {
                        cout << "\n\t\t\t\tunable to FETCH RECORD";
                        cout << "\n\t\t\t\tError:" << zErrMsg;
                        sqlite3_free(zErrMsg);
                    }
                break;
            case 2:
                sql = "SELECT * FROM STOCK ORDER BY NAME ASC";
                cout <<"\n";
                cout <<"\n\n\t\tID\t\tName\t\tCategory\tPrice\t\tQuantity";

                rc = sqlite3_exec(db1, sql, callback, (void *)data, &zErrMsg);
                    if (rc != SQLITE_OK)
                    {
                        cout << "\n\t\t\t\tunable to FETCH RECORD";
                        cout << "\n\t\t\t\tError:" << zErrMsg;
                        sqlite3_free(zErrMsg);
                    }
                break;
            case 3:
                sql = "SELECT * FROM STOCK ORDER BY NAME ASC";
                cout <<"\n";
                cout <<"\n\n\t\tID\t\tName\t\tCategory\tPrice\t\tQuantity";

                rc = sqlite3_exec(db1, sql, callback, (void *)data, &zErrMsg);
                    if (rc != SQLITE_OK)
                    {
                        cout << "\n\t\t\t\tunable to FETCH RECORD";
                        cout << "\n\t\t\t\tError:" << zErrMsg;
                        sqlite3_free(zErrMsg);
                    }
                break;
            }
        }while(stay!=3)
        sqlite3_close(db1);
    }
     void select()
    {
        system("cls");
        inv_display();

        open_db();

        sql = "SELECT * FROM STOCK ORDER BY NAME ASC";
        cout <<"\n";
        cout <<"\n\n\t\tID\t\tName\t\tCategory\tPrice\t\tQuantity";

        rc = sqlite3_exec(db1, sql, callback, (void *)data, &zErrMsg);
            if (rc != SQLITE_OK)
            {
                cout << "\n\t\t\t\tunable to FETCH RECORD";
                cout << "\n\t\t\t\tError:" << zErrMsg;
                sqlite3_free(zErrMsg);
            }
        cout<<"\n\t\t\t\tEnter 1 to exit : ";
            while(stay!=1){
                 cin >> stay;
            }
            sqlite3_close(db1);
    }

    void ruuning_out_of_stock(){

        system("cls");
        inv_display();

        open_db();

        sql = "SELECT * FROM STOCK where QTY BETWEEN 1 AND 20 ORDER BY NAME ASC";
        cout <<"\n";
        cout <<"\n\n\t\tID\t\tName\t\tCategory\tPrice\t\tQuantity";

        rc = sqlite3_exec(db1, sql, callback, (void *)data, &zErrMsg);
            if (rc != SQLITE_OK)
            {
                cout << "\n\t\t\t\tunable to FETCH RECORD";
                cout << "\n\t\t\t\tError:" << zErrMsg;
                sqlite3_free(zErrMsg);
            }
        cout<<"\n\t\t\t\tEnter 1 to exit : ";
            while(stay!=1){
                 cin >> stay;
            }
            sqlite3_close(db1);


    }

    void out_of_stock(){

        system("cls");
        inv_display();

        open_db();

        sql = "SELECT * FROM STOCK where QTY == 0 ORDER BY NAME ASC";
        cout <<"\n";
        cout <<"\n\n\t\tID\t\tName\t\tCategory\tPrice\t\tQuantity";

        rc = sqlite3_exec(db1, sql, callback, (void *)data, &zErrMsg);
            if (rc != SQLITE_OK)
            {
                cout << "\n\t\t\t\tunable to FETCH RECORD";
                cout << "\n\t\t\t\tError:" << zErrMsg;
                sqlite3_free(zErrMsg);
            }
        cout<<"\n\t\t\t\tEnter 1 to exit : ";
            while(stay!=1){
                 cin >> stay;
            }
            sqlite3_close(db1);


    }


    //this function display the records row by row
     static int callback(void *data, int col_in_row, char **fields_in_row, char **Col_names)
    {
        cout <<"\n";

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
        cout << "\n\t\t\t\t4. Search product"
        cout << "\n\t\t\t\t5. Available Stock";
        cout << "\n\t\t\t\t6. Running-out of stock";
        cout << "\n\t\t\t\t7. Out-of-stock products";
        cout << "\n\t\t\t\t8. Return to employee page";
        cout << "\n\t\t\t\t9. Exit";
        cout << "\n\n\t\t\t\tYour Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.add_product();
            break;
        case 2:
            obj.update_product();
            break;
        case 3:
            obj.del_product();
            break;
        case 4:
            break;
        case 5:
            obj.select();
            break;
        case 6:
            obj.ruuning_out_of_stock();
            break;
        case 7:
            obj.out_of_stock();
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
