#include <windows.h>

#include <iostream>
#include "sqlite3.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MessageBox(NULL, "Goodbye,cruel world!", "Note", MB_OK);

    return 0;
}

int main(int argc, char **argv)
{
    sqlite3 *DB;
    int exit = 0;
    exit = sqlite3_open("example.db", &DB);

    if (exit)
    {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;
    sqlite3_close(DB);
    return (0);
}