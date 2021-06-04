#include <iostream>
#include "sqlite3.h"

using namespace std;

class database
{
private:
    sqlite3 *db1;
    char *zErrMsg = 0;
    int rc;
    char const *sql;
    char const *data = "\n\t callback invoked";

public:
    void open_db()
    {
        //open database or create if does not exist
        rc = sqlite3_open("stock_1.db", &db1);

        //check for errors in creation or opening
        if (rc)
        {
            cout << "\n\tcant open database";
            cout << "\n\tError:" << sqlite3_errmsg(db1);
        }
        else
        {
            cout << "\n\t database opened successfully";
        }
    }
    void create()
    {
        //sql query to create
        sql = "CREATE TABLE STOCK("
              "QR     INT PRIMARY KEY NOT NULL,"
              "NAME   TEXT            NOT NULL,"
              "CATEGORY TEXT          NOT NULL,"
              "PRICE  REAL            NOT NULL,"
              "QTY    INT             NOT NULL,"
              "GST    REAL            NOT NULL);";

        //executes sql query to create STOCK table
        rc = sqlite3_exec(db1, sql, callback, 0, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            cout << "\n\tunable to create table";
            cout << "\n\tError:" << zErrMsg;
            sqlite3_free(zErrMsg);
        }
        else
        {
            cout << "\n\t Table created successfully";
        }
    }
    void insert()
    {
        //sql insert query
        sql = "INSERT INTO STOCK (QR,NAME,CATEGORY,PRICE,QTY,GST)"
              "VALUES (235,'cheese','FMCG',50.00,10,2.3);";
        rc = sqlite3_exec(db1, sql, callback, (void *)data, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            cout << "\n\tunable to INSERT RECORD";
            cout << "\n\tError:" << zErrMsg;
            sqlite3_free(zErrMsg);
        }
        else
        {
            cout << "\n\t RECORD created successfully";
        }
    }
    void select()
    {
        //sql select query
        sql = "SELECT * FROM STOCK";
        rc = sqlite3_exec(db1, sql, callback, (void *)data, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            cout << "\n\tunable to FETCH RECORD";
            cout << "\n\tError:" << zErrMsg;
            sqlite3_free(zErrMsg);
        }
        else
        {
            cout << "\n\t RECORDS fetched successfully";
        }
    }
    void dlt()
    {
        cout << "demo, nothing implemented";
    }

    void exit()
    {
        sqlite3_close(db1);
    }

    //callback function displays the records
    static int callback(void *data, int col_in_row, char **fields_in_row, char **Col_names)
    {
        cout << (const char *)data;
        for (int i = 0; i < col_in_row; i++)
        {
            cout << "\n\t " << Col_names[i] << ":" << fields_in_row[i];
        }
        cout << "\n";
        return 0;
    }
};

void db_test()
{
    int choice;
    database obj;
    obj.open_db();
    obj.create();
    obj.insert();
    obj.select();
    cin >>choice;
    cout<<choice;
    /*    do{
        cout<<"\n\tYour choice:";
        cin>>choice;
        switch(choice){
            case 1:
            obj.create();


        }
    }while(choice!=5);*/
    //close connection to database
}
