#ifndef SEMESTER_SYS_HPP
#define SEMESTER_SYS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <iomanip>
#include <sstream>
#include "../DataTypes.hpp"
#include "../../lib/PriorityQueue.hpp" 
#include "../../lib/Queue.hpp"        
#include "../UI.hpp"

inline std::string currentSemesterName = "";
inline PriorityQueue<Dungeon> semesterPQ; 


// Hàm lưu file
void saveDungeonToFile(const Dungeon& dungeon) {
    std::string folderPath = "app/data/" + currentSemesterName;
    std::ofstream file(folderPath + "/dungeons.txt", std::ios::app);
    
    if (!file.is_open()) {
        std::cout << "  [Loi] Khong the ghi du lieu vao thu muc hoc ky!\n";
        return;
    }

    
    int bossCount = size(dungeon.bossQueue);
    
    file << dungeon.courseID << " " << dungeon.priority << " " << dungeon.playerHP << " " << bossCount << "\n";
    
    // Dùng con trỏ duyệt qua QueueNode
    QueueNode<Boss>* current = dungeon.bossQueue.front;
    while (current != nullptr) {
        Boss b = current->data;
        file << b.name << " " << b.weight << "\n";
        current = current->next; 
    }

    file.close();
}

// Hàm khởi tạo/Chọn học kỳ
void selectOrCreateSemester() {
    clearScreen();
    drawHeader("THIET LAP HOC KY MAO HIEM");
    std::cout << "  => Nhap ten Hoc ky muon lam viec (VD: HK1, HK2, HK251): ";
    std::getline(std::cin, currentSemesterName);

    if (currentSemesterName.empty()) {
        currentSemesterName = "HocKyMacDinh";
    }

    std::string folderPath = "app/data/" + currentSemesterName;
    std::filesystem::create_directories(folderPath); // Tạo cái thư mục học kỳ mới đó

    init(semesterPQ); 

    // Viết vào file dungeons.txt
    std::ifstream file(folderPath + "/dungeons.txt");
    if (file.is_open()) {
        std::string courseID;
        int priority, playerHP, bossCount;

        while (file >> courseID >> priority >> playerHP >> bossCount) {
            Dungeon d;
            d.courseID = courseID;
            d.priority = priority;
            d.playerHP = playerHP;
            init(d.bossQueue);

            for (int i = 0; i < bossCount; i++) {
                Boss b;
                file >> b.name >> b.weight;
                enqueue(d.bossQueue, b); 
            }
            push(semesterPQ, d); 
        }
        file.close();
        std::cout << "\n  [He thong] Da nhan dien thu muc [" << currentSemesterName << "] va nap cac Dungeon cu!\n";
    } else {
        std::cout << "\n  [He thong] Da tao moi thu muc hoc ky rong [" << currentSemesterName << "]. San sang thiet lap!\n";
    }
}

// Hàm thêm Dungeon mới
void addDungeonAndBosses() {
    // Safe check
    if (currentSemesterName.empty()) {
        std::cout << "\n  [!] Ban chua chon Hoc ky. Vui long thiet lap hoc ky truoc!\n";
        return;
    }

    clearScreen();
    drawHeader("TAO DUNGEON MOI CHO HOC KY [" + currentSemesterName + "]");

    Dungeon newDungeon;
    std::cout << "  => Nhap ma mon hoc (Dungeon ID): ";
    std::getline(std::cin, newDungeon.courseID);

    std::cout << "  => Nhap do uu tien (So cang lon, dungeon hien thi cang dau): ";
    std::cin >> newDungeon.priority;

    std::cout << "  => Nhap luong mau (HP) cua Ki si khi vao dungeon nay: ";
    std::cin >> newDungeon.playerHP;

    int totalBosses;
    std::cout << "  => Dungeon nay co bao nhieu quai vat (Bai kiem tra)? ";
    std::cin >> totalBosses;
    std::cin.ignore(); // Bỏ kí tự xuống dòng (làm bug cả tiếng!!!)

    init(newDungeon.bossQueue);

    float totalWeight = 0.0f;
    for (int i = 1; i <= totalBosses; i++) {
        Boss b;
        std::cout << "\n    -> Nhap ten Quai vat #" << i << " (Khong khoang trang, VD: Giua_ki): ";
        std::getline(std::cin, b.name);
        std::cout << "    -> Nhap he so diem / ti trong (VD: Giua ki chiem 30% thi nhap 0.3): ";
        std::cin >> b.weight;
        std::cin.ignore();

        totalWeight += b.weight;
        enqueue(newDungeon.bossQueue, b); 
    }

    if (totalWeight != 1.0f) {
        std::cout << "\n  [Canh bao] Tong ti trong cac quai vat dang la " << totalWeight << " (khac 1.0), hay chu y!\n";
    }

    push(semesterPQ, newDungeon); 
    saveDungeonToFile(newDungeon);

    std::cout << "\n  [Thanh cong] Da thiet lap xong Dungeon [" << newDungeon.courseID << "] va dua vao lich trinh!\n";
}

// Hàm xem lịch trình fix
void viewSemesterSchedule() {
    clearScreen();
    if (currentSemesterName.empty()) {
        std::cout << "\n  [!] Ban chua chon Hoc ky!\n";
        return;
    }

    if (isEmpty(semesterPQ)) {
        std::cout << "\n  [!] Hoc ky [" << currentSemesterName << "] dang binh yen, chua co Dungeon nao duoc setup!\n";
        return;
    }

    drawHeader("LICH TRINH TIEP CAN DUNGEON (HK: " + currentSemesterName + ")");

    Dungeon tempList[50]; 
    int count = 0;

    while (!isEmpty(semesterPQ) && count < 50) {
        tempList[count] = top(semesterPQ);
        pop(semesterPQ); 
        count++;
    }

    for (int i = 0; i < count; i++) {
        std::ostringstream ossDungeon;
        ossDungeon << "   " << i + 1 << ". Vung dat: " << tempList[i].courseID 
                   << " | Uu tien: " << tempList[i].priority 
                   << " | HP Cap: " << tempList[i].playerHP;
        
        std::cout << "  |" << std::setw(61) << std::left << ossDungeon.str() << "|\n";
        
        std::ostringstream ossBoss;
        ossBoss << "      -> Danh sach quai vat: ";
        
        QueueNode<Boss>* current = tempList[i].bossQueue.front;
        
        if (current == nullptr) {
            ossBoss << "Khong co.";
        } else {
            while (current != nullptr) {
                ossBoss << "[" << current->data.name << " (" << current->data.weight << ")]";
                current = current->next;
                if (current != nullptr) ossBoss << " -> ";
            }
        }
        
        std::string bossStr = ossBoss.str();
        if (bossStr.length() > 61) {
            std::cout << "  |" << std::setw(61) << std::left << bossStr.substr(0, 61) << "|\n";
            std::cout << "  |" << std::setw(61) << std::left << ("                   " + bossStr.substr(61)) << "|\n";
        } else {
            std::cout << "  |" << std::setw(61) << std::left << bossStr << "|\n";
        }
        
        if (i < count - 1) {
            std::cout << "  |                                                             |\n";
        }
    }
    
    drawDivider();

    for (int i = 0; i < count; i++) {
        push(semesterPQ, tempList[i]);
    }
}
#endif