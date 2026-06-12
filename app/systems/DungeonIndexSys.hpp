#ifndef DUNGEON_INDEX_SYS_HPP
#define DUNGEON_INDEX_SYS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include "../DataTypes.hpp"        
#include "../../lib/HashTable.hpp"
#include "../UI.hpp"

// ==== lOGIC CHO DUNGEON INDEX ====

// Hàm để hash chuỗi dungeon (môn học)
struct HashString {
    int operator() (const std::string &key) const {
        int hashVal = 0;
        for (char c : key) {
            hashVal = (hashVal * 31) + c;
        }
        return hashVal < 0 ? -hashVal : hashVal;
    }
};

// Khai báo bảng băm HashTable 
/*
    Hướng design sẽ là key là string còn value là
    CourseInfo của thư viện DataTypes
*/

inline HashTable<std::string, CourseInfo> dungeonIndex;
inline HashString stringHasher;

// Hàm load dữ liệu từ file courses.txt khi mở game
void loadDungeonIndex() {
    init(dungeonIndex);

    std::ifstream file("app/data/courses.txt");
    if (!file.is_open()) {
        std::cout << "  [He thong] Khong tim thay file du lieu. Khoi tao Dungeon Index rong.\n";
        return;
    }

    std::string id, creditsStr, tips;
    while (std::getline(file, id)) {
        if (id.empty()) continue;
        std::getline(file, creditsStr);
        std::getline(file, tips);
        
        CourseInfo info;

        info.courseID = id;
        info.credits = std::stoi(creditsStr);
        info.tips = tips;

        insert(dungeonIndex, id, info, stringHasher);
    }
    file.close();
    std::cout << "  [He thong] Da nap thanh cong Dungeon Index tu file!\n";
}


// Hàm thêm dungeon mới vào game
void addDungeonToIndex() {
    clearScreen();
    drawHeader("THEM DUNGEON INDEX MOI");

    std::string id, tips;
    int credits;

    std::cout << "  => Nhap ma mon hoc (VD: CSC10005): ";
    std::getline(std::cin, id);

    std::cout << "  => Nhap so tin chi: ";
    std::cin >> credits;
    std::cin.ignore();

    std::cout << "  => Nhap meo pha dao dungeon nay: ";
    std::getline(std::cin, tips);

    CourseInfo newCourse = {id, credits, tips};

    insert(dungeonIndex, id, newCourse, stringHasher);

    std::ofstream file("app/data/courses.txt", std::ios::app);

    if (file.is_open()) {
        file << id << "\n" << credits << "\n" << tips << "\n";
        file.close();
        std::cout << "\n  [Thanh cong] Da ghi du lieu dungeon Index thanh cong!\n";
    } else {
        std::cout << "\n  [Loi] Khong the ghi vao file du lieu!\n";
    }
}

// Hàm tra cứu dungeon trả về thông tin của học phần đó
void searchDungeonIndex() {
    clearScreen();
    drawHeader("TRA CUU DUNGEON INDEX");

    std::string queryID;
    std::cout << "  => Nhap ma mon muon tra cuu (VD: CSC10004): ";
    std::getline(std::cin, queryID);
    auto resultNode = find(dungeonIndex, queryID, stringHasher);

    std::cout << "\n";
    if (resultNode != nullptr) {
        CourseInfo foundCourse = resultNode->data.value;
        std::cout << "  |" << std::setw(61) << std::left << ("   MA DUNGEON  : " + foundCourse.courseID) << "|\n";
        std::cout << "  |" << std::setw(61) << std::left << ("   SO TIN CHI  : " + std::to_string(foundCourse.credits)) << "|\n";
        
        std::string tipFormat = "   MEO PHA DAO : " + foundCourse.tips;
        if (tipFormat.length() > 61) {
            std::cout << "  |" << std::setw(61) << std::left << tipFormat.substr(0, 61) << "|\n";
            std::cout << "  |" << std::setw(61) << std::left << ("                 " + tipFormat.substr(61)) << "|\n";
        } else {
            std::cout << "  |" << std::setw(61) << std::left << tipFormat << "|\n";
        }
        drawDivider();
    } else {
        std::cout << "  |" << std::setw(61) << std::left << "   [!] Vung dat nay chua duoc kham pha! Hay them index truoc." << "|\n";
        drawDivider();
    }
}

#endif