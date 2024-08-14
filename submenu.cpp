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

void setcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    return;
}

void setting_console() {
    // Gõ tiếng Việt
    SetConsoleOutputCP(65001);
    // Title của console
    SetConsoleTitle("NGUYEN THE PHONG 20216868");
}

void note() {
    setcolor(124);
    cout << "\t\tChú ý: " << endl;
    setcolor(240);
    cout << "\t\tẤn Enter để quay lại.\n";
    cout << "\t\tẤn ESC thoát chương trình.\n";

    while(1) {
        char key;
        key = getch();
        if(key == ENTER)
            return;
        else if(key == ESC)
            exit(0);
    }
}

void border(int w) {
    cout << "\t\t";
    for(int i = 0;i < w;i++)
        cout << '=';
    cout << endl;
}

void submenu_se(int mode) {
    string submenu[2] = { "1. Lặp đơn.", "2. Lặp Seidel."};
    int choice = 0;

    while(true) {
        system("cls");
        setcolor(240);
        border(43);
        cout << "\t\t\t== Chọn phương pháp giải ==\t\t\n";
        border(43);

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
         //   print(key);
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

                setcolor(240);
                border(30);
                cout << "\t\t\t== Kết quả ==\t\t\n";
                border(30);
                switch (choice) {

                    case 0:
                        cout << "\n\n";
                        if(row_diag_dom(A))
                            for(int type = 1;type <= 2;type++) {
                                if(mode == 1)
                                    solve_iterative_method_row_fi(G, c, k, type);
                                else if(mode == 2)
                                    solve_iterative_method_row_se(G, c, epsilon, type);
                                else if(mode == 3) {
                                    solve_iterative_method_row_th(G, c, epsilon);
                                    cout << endl;
                                    break;
                                }
                                cout << endl;
                            }
                        else
                            for(int type = 1;type <= 2;type++) {
                                if(mode == 1)
                                    solve_iterative_method_col_fi(G, c, G_col, frac, k, type);
                                else if(mode == 2)
                                    solve_iterative_method_col_se(G, c, G_col, epsilon, frac, type);
                                else if(mode == 3) {
                                    solve_iterative_method_col_th(G, c, epsilon);
                                    cout << endl;
                                    break;
                                }
                                cout << endl;
                            }

                        break;
                    case 1:
                        cout << "\n\n";
                        if(row_diag_dom(A))
                            for(int type = 1;type <= 2;type++) {
                                if(mode == 1)
                                    solve_iterative_seidel_method_row_fi(G, c, k, type);
                                else if(mode == 2)
                                    solve_iterative_seidel_method_row_se(G, c, epsilon, type);
                                else if(mode == 3) {
                                    solve_iterative_seidel_method_row_th(G, c, epsilon);
                                    cout << endl;
                                    break;
                                }
                                cout << endl;
                            }
                        else
                            for(int type = 1;type <= 2;type++) {
                                if(mode == 1)
                                    solve_iterative_seidel_method_col_fi(G, c, G_col, k, type);
                                else if(mode == 2)
                                    solve_iterative_seidel_method_col_se(G, c, G_col, epsilon, type);
                                else if(mode == 3) {
                                    solve_iterative_seidel_method_col_th(G, c, epsilon);
                                    cout << endl;
                                    break;
                                }
                                cout << endl;
                            }
                        break;
                }
                border(26);
                setcolor(124);
                cout << "\t\tChú ý: ";
                setcolor(240);
                cout << "\n\t\tẤn Enter để quay lại.\n";
                cout << "\t\tẤn ESC thoát chương trình.\n";

                while(1) {
                 //   print(key);
                    key = getch();
                    if(key == ENTER)
                        return;
                    else if(key == ESC)
                        exit(0);
                }
            }

        }
    }
}

void solve(int mode) {
    if(row_diag_dom(A) || col_diag_dom(A)) {
        G = new double *[n+1];
        G_col = new double *[n+1];
        c = new double [n+1];
        for(int i = 0;i < n;i++) {
            G[i] = new double[n+1];
            G_col[i] = new double[n+1];
        }
        getGc(G, c, A, b);
        getG_col(G_col, A, b);
        frac = get_frac(A);
        submenu_se(mode);
    }
    else {
        border(36);
        cout << "\t\tPhương pháp không hội tụ." << endl;
        border(36);
        setcolor(124);
        cout << "\t\tChú ý: ";
        setcolor(240);
        cout << "\n\t\tẤn Enter để quay lại.\n";
        cout << "\t\tẤn ESC thoát chương trình.\n";

        while(1) {
            char key;
            key = getch();
            if(key == ENTER)
                return;
            else if(key == ESC)
                exit(0);
        }

    }
}

