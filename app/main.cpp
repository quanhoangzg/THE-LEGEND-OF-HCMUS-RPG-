#include <iostream>
#include "UI.hpp"
#include <limits>
#include "DataTypes.hpp"
#include <cstdlib> 
using namespace std;

void pauseScreen() {
    std::cout << "\n(Nhan Enter de tiep tuc...)";
    std::cin.get(); 
    clearScreen();
}

void clearScreen() {
    #ifdef _WIN32
        system("cls"); // Dành cho Windows
    #else
        system("clear"); // Dành cho Linux và macOS
    #endif
}

int main() {
    Player hero = {"QuanTest", 10, 5};

    bool isRunning = true;
    int choice;

    while (isRunning) {
        drawTitle();
        cout << "Ki si " << hero.name << "| LVL : " << hero.level << " | EXP: " << hero.exp << endl;
        cout << "1. Tra cuu Monster Index (Thong tin mon hoc)\n";
        cout << "2. Tao Hoc ky (Them Dungeon & quai vat)\n";
        cout << "3. Tien vao Dungeon (Giao tranh Boss)\n";
        cout << "4. Trang bi kien thuc (Skill Tree)\n";
        cout << "5. Nhat ky Mao hiem (Lich su)\n";
        cout << "6. Kho Thanh tuu \n";
        cout << "0. Dang xuat (Thoat game)\n";
        cout << "-> Lua chon cua ban: ";

        if (!(cin >> choice)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            choice = -1; // Gán như này để nó đưa về default chạy lại vòng lặp
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        clearScreen();

        switch (choice)
        {
            case 1:
                /* code */
                cout << "TN1\n";
                break;
            case 2:
                /* code */
                cout << "TN2\n";
                break;
            case 3:
                /* code */
                cout << "TN3\n";
                break;
            case 4:
                /* code */
                cout << "TN4\n";
                break;
            case 5:
                cout << "TN5\n";
                /* code */
                break;
            case 6:
                cout << "TN6\n";
                /* code */
                break;
            case 0:
                cout << "\nTam biet Ky si! Hen gap lai o HCMUS.\n";
                isRunning = false;
                break;
            default:
                break;
                cout << "\nLua chon khong hop le, vui long vung kiem lai!\n";
        }

        if (isRunning) {
            pauseScreen();
        }
    }

    return 0;
}