#include <iostream>
#include "UI.hpp"
#include <limits>
#include "DataTypes.hpp"
#include "systems/DungeonIndexSys.hpp" // Logic áp dụng HashTable
#include <cstdlib> 
#include "systems/SemesterSys.hpp"     // Logic Hàng đợi
#include "systems/CombatSys.hpp" // Logic dùng Piority Queue
#include "systems/PlayerSys.hpp"
using namespace std;


int main() {
    Player hero = {"", 1, 0};

    // Khởi động hệ thống file
    clearScreen();
    loadDungeonIndex();
    loadOrCreatePlayer(hero);
    loadRecords();
    pauseScreen();

    bool isRunning = true;
    int choice;

    while (isRunning) {
        drawMainMenu(hero, currentSemesterName);

        if (!(cin >> choice)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            choice = -1; // Gán như này để nó đưa về default chạy lại vòng lặp
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        clearScreen();

        switch (choice) {
            case 1: {
                bool inIndexMenu = true;
                int indexChoice;
                while (inIndexMenu) {
                    clearScreen();
                    drawDungeonIndexMenu();
                    
                    if (!(cin >> indexChoice)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        indexChoice = -1;
                    } else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    clearScreen();
                    if (indexChoice == 1) {
                        searchDungeonIndex(); // Đổi tên
                        pauseScreen();
                    } else if (indexChoice == 2) {
                        addDungeonToIndex();  // Đổi tên
                        pauseScreen();
                    } else if (indexChoice == 0) {
                        inIndexMenu = false;
                    } else {
                        cout << "Lua chon khong hop le!\n";
                        pauseScreen();
                    }
                }
                break;
            }
            case 2: {
                bool inSemesterMenu = true;
                int semChoice;
                while (inSemesterMenu) {
                    clearScreen();
                    drawSemesterMenu(currentSemesterName); // In giao diện menu Học kỳ

                    if (!(cin >> semChoice)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        semChoice = -1;
                    } else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    clearScreen();
                    if (semChoice == 1) {
                        selectOrCreateSemester();
                        pauseScreen();
                    } else if (semChoice == 2) {
                        addDungeonAndBosses();
                        pauseScreen();
                    } else if (semChoice == 3) {
                        viewSemesterSchedule();
                        pauseScreen();
                    } else if (semChoice == 0) {
                        inSemesterMenu = false;
                    } else {
                        cout << "Lua chon khong hop le!\n";
                        pauseScreen();
                    }
                }
                break;
            }
            case 3:
                clearScreen();
                enterDungeon(hero);
                // pauseScreen();
                break;
            case 4: // SỐ 4 MỚI: NHẬT KÝ
                clearScreen();
                viewCombatHistory();
                // pauseScreen();
                break;
                
            case 5: // SỐ 5 MỚI: BẢNG VÀNG THÀNH TỰU
                clearScreen();
                viewLeaderboard();
                // pauseScreen();
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