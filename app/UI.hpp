#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <string>
#include "DataTypes.hpp"

// Vẽ tiêu đề game
void drawTitle() {
    std::cout << "\n=========================================\n";
    std::cout << "        THE LEGEND OF HCMUS (RPG)        \n";
    std::cout << "=========================================\n";
}

// Vẽ Menu Chính
void drawMainMenu(const Player& hero, const std::string& currentSemester) {
    drawTitle();
    std::string semStatus = currentSemester.empty() ? "Chua chon" : currentSemester;
    
    std::cout << "Ki si " << hero.name << " | LVL: " << hero.level 
              << " | EXP: " << hero.exp << " | Hoc ky: " << semStatus << "\n";
    std::cout << "1. Cuon sach Dungeon Index (Tra cuu / Them mon)\n";
    std::cout << "2. Quan ly Hoc ky\n";
    std::cout << "3. Tien vao Dungeon (Giao tranh Boss)\n";
    std::cout << "4. Trang bi kien thuc (Skill Tree)\n";
    std::cout << "5. Nhat ky Mao hiem (Lich su)\n";
    std::cout << "6. Kho Thanh tuu \n";
    std::cout << "0. Dang xuat (Thoat game)\n";
    std::cout << "-> Lua chon cua ban: ";
}

// Vẽ Menu Phụ: Dungeon Index (Giai đoạn 2)
void drawDungeonIndexMenu() {
    std::cout << "--- CUON SACH DUNGEON INDEX ---\n";
    std::cout << "1. Tra cuu ma mon hoc (Dungeon)\n";
    std::cout << "2. Them dungeon index moi\n";
    std::cout << "0. Quay lai menu chinh\n";
    std::cout << "-> Lua chon: ";
}

// Vẽ Menu Phụ: Quản lý Học kỳ (Giai đoạn 3)
void drawSemesterMenu(const std::string& currentSemester) {
    std::cout << "--- HE THONG QUAN LY HOC KY MAO HIEM ---\n";
    std::cout << "Hoc ky dang chon: [" << (currentSemester.empty() ? "Trong" : currentSemester) << "]\n\n";
    std::cout << "1. Khoi tao / Chon Hoc ky\n";
    std::cout << "2. Them Dungeon & Sinh san Quai vat (Boss)\n";
    std::cout << "3. Xem lich trinh tiep can Dungeon\n";
    std::cout << "0. Quay lai menu chinh\n";
    std::cout << "-> Lua chon: ";
}

// Các hoạt ảnh giữ nguyên
void drawAttackAnimation() {
    std::cout << ">>> [HOAT ANH: Kị sĩ 25CTT4 vung kiếm chém Boss!] <<<\n";
}

#endif // UI_HPP