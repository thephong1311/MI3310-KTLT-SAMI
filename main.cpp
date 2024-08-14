#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include "function.h"
#include<fstream>

using namespace std;

#define UP    72
#define DOWN  80
#define ENTER 13
#define ESC 27

int n, k, precision;
double **A, **G, **G_col;
double *b, *c;
double epsilon, frac;

int main()
{
    setting_console();
    string Menu[7] = {"1. Nhập ma trận A và vector b.",
    "2. Kiểm tra tính chéo trội của ma trận A. Kiểm tra sự hội tụ.",
    "3. Tính chuẩn của ma trận A.",
    "4. Tính nghiệm gần đúng với k lần lặp.",
    "5. Tính nghiệm gần đúng với sai số e.",
    "6. Tính nghiệm gần đúng thỏa mãn điều kiện ||x(k)-x(k-1)|| <= e.",
    "7. Thoát chương trình." };
    int pointer = 0;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);

    while(true) {
        system("cls");

        border(100);
        cout << "\t\t =====MAIN MENU NGUYEN THE PHONG 20216868 =====\t\t\n";
        border(100);
        for (int i = 0; i < 7; ++i) {
            if (i == pointer) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 121);
                cout << "\t\t";
                cout << Menu[i] << endl;
            }
            else {
                cout << "\t\t";
				cout << Menu[i] << endl;;
			}
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
        }

        while(true)
        {
            char key;
            key = getch();
            if (key ==  UP) {
                pointer = pointer - 1;
                if (pointer == -1) pointer = 6;
                break;
            }
            else if (key ==  DOWN) {
                pointer = pointer + 1;
                if (pointer == 7) pointer = 0;
                break;
            }
            else if (key == ENTER) {
                switch (pointer) {
                    case 0:
                        system("cls");
                        fflush(stdin);
                        submenu_input();
                        break;
                    case 1:
                        system("cls");
                        border(33);
                        cout << "\t\t\t== Kết quả ==\t\t\n";
                        border(33);
                        if(row_diag_dom(A))
                            cout << "\t\tMa trận A chéo trội hàng." << endl;
                        else
                            cout << "\t\tMa trận A không chéo trội hàng." << endl;
                        if(col_diag_dom(A))
                            cout << "\t\tMa trận A chéo trội cột." << endl;
                        else
                            cout << "\t\tMa tran A không chéo trội cột." << endl;
                        if(row_diag_dom(A) || col_diag_dom(A))
                            cout << "\t\tPhương pháp hội tụ." << endl;
                        else
                            cout << "\t\tPhương pháp không hội tụ." << endl;
                        border(33);
                        note();
                        break;
                    case 2:
                        system("cls");
                        border(33);
                        cout << "\t\t\t== Kết quả ==\t\t\n";
                        border(33);
                        cout << "\t\tChuẩn hàng ma trận A: " << matrix_norm_row(A) << endl;
                        cout << "\t\tChuẩn cột ma trận A: " << matrix_norm_col(A) << endl;
                        border(33);
                        note();
                        break;
                    case 3:
                        system("cls");
                        border(40);
                        cout << "\t\t\t== Nhập các tham số ==\t\t\n";
                        border(40);
                        cout << "\t\tNhập số lần lặp k: ";
                        cin >> k;
                        cout << "\t\tNhập số chữ số thập phân trong kết quả: ";
                        cin >> precision;
                        Sleep(3000);
                        solve(1);
                        break;
                    case 4:
                        system("cls");
                        border(40);
                        cout << "\t\t\t== Nhập các tham số ==\t\t\n";
                        border(40);
                        cout << "\t\tNhập sai số e: ";
                        cin >> epsilon;
                        cout << "\t\tNhập số chữ số thập phân trong kết quả: ";
                        cin >> precision;
                        Sleep(3000);
                        solve(2);
                        break;
                    case 5:
                        system("cls");
                        border(40);
                        cout << "\t\t\t== Nhập các tham số ==\t\t\n";
                        border(40);
                        cout << "\t\tNhập sai số e: ";
                        cin >> epsilon;
                        cout << "\t\tNhập số chữ số thập phân trong kết quả: ";
                        cin >> precision;
                        Sleep(3000);
                        solve(3);
                        break;
                    case 6:
                        system("cls");
                        border(40);
                        cout << "\t\t\t== Thông báo ==\t\t\n";
                        border(40);
                        cout << "\t\tChào tạm biệt và hẹn gặp lại.\n";
                        exit(0);
                }
                break;
            }
        }

        Sleep(150);
    }


return 0;
}

/*
3
6 1 2
1 5 2
1 5 10
6
7
8
0.00001

4
5.1 1.1 1.2 1
1.1 6.1 1 1.1
1.2 1 7.1 1
1 1.1 1 5.1
6.3
2.1
8.3
2
0.0001
25

3
6 4 5
1 9 2
3 4 8
6 7 8

*/
