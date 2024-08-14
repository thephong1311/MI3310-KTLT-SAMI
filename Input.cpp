#include<iostream>
#include<stdio.h>
#include <fstream>
#include<iomanip>
#include<windows.h>
#include<string.h>
#include "function.h"
#include<conio.h>
using namespace std;

#define UP    72
#define DOWN  80
#define ENTER 13
#define ESC 27

void setting_array() {
    A = new double *[n+1];
    b = new double [n+1];
    for(int i = 0;i < n;i++)
        A[i] = new double[n+1];
}

void response_input() {
    cout << "\t\tNhập thành công!" << endl;
    cout << "\t\tMa trận A: " << endl;
    print_matrix(A);
    cout << "\t\tVector b: " << endl;
    print_vector(b);
}

void submenu_input() {
    string submenu[2] = { "1. Nhập từ file.", "2. Nhập từ màn hình."};
    int choice = 0;

    setcolor(240);
    while(true) {
        system("cls");
        string start = "\t\t\t== Chọn cách nhập ==\t\t\n";
        border(36);
        cout << start;
        border(36);
        for (int i = 0; i < 2; ++i) {
            if (i == choice) {
                cout << "\t     -> ";
                setcolor(121);
                cout << submenu[i] << endl;
            }
            else {
                cout << "\t\t";
                cout << submenu[i] << endl;
			}
        setcolor(240);
        }
        while(true)
        {
            char key;
            key = getch();
            if (key == UP) {
                choice = choice - 1;
                if (choice == -1) choice = 1;
                break;
            }
            else if (key == DOWN) {
                choice = choice + 1;
                if (choice == 2) choice = 0;
                break;
            }
            else if (key == ENTER) {
                switch (choice) {
                    case 0:
                    {
                        string file_name;
                        border(36);
                        cout << "\t\t";
                        cout << "Nhập đường dẫn file: " << endl;
                        cout << "\t\t";
                        getline(cin, file_name);
                        fflush(stdin);

                        ifstream my_file;

                        if(!my_file.is_open()) {
                            cout << "\t\t";
                            setcolor(124);
                            cout << "Không mở được file." << endl;
                            setcolor(240);
                            border(36);
                            note();
                            return;
                        }

                        my_file >> n;

                        setting_array();

                        for(int i = 0;i < n;i++)
                            for(int j = 0;j < n;j++)
                                my_file >> A[i][j];
                        for(int i = 0;i < n;i++)
                            my_file >> b[i];

                        border(36);
                        response_input();

                        my_file.close();

                        border(36);
                        fflush(stdin);
                        break;
                    }
                    case 1:
                    {
                        cout << "\t\tNhập cỡ ma trận, vector: ";
                        cin >> n;
                        fflush(stdin);

                        setting_array();

                        cout << "\t\tNhập ma trận A: \n";
                        for(int i = 0;i < n;i++) {
                            cout << "\t\t";
                            for(int j = 0;j < n;j++) {
                                cin >> A[i][j];
                            }
                        }
                        cout << "\t\tNhập vector b: \n";

                        for(int i = 0;i < n;i++) {
                            cout << "\t\t";
                            cin >> b[i];
                        }
                        border(36);
                        response_input();
                        border(36);
                        break;
                    }
                }

                setcolor(124);
                cout << "\t\tChú ý: ";
                setcolor(240);
                cout << "\n\t\tẤn Enter để quay lại.\n";
                cout << "\t\tẤn ESC thoát chương trình.\n";

                while(true) {
                    char key_in;
                    key_in = getch();
                    if(key_in == ENTER)
                        return;
                    else if(key_in == ESC)
                        exit(0);
                }
            }

        }
    }
}

/*
C:/Users/Admin/Desktop/20202/KTLT/Bai tap/Project/KTLT - Nhom 3/input.txt
*/
