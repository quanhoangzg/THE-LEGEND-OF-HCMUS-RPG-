#ifndef PLAYER_SYS_HPP
#define PLAYER_SYS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "../DataTypes.hpp"
#include "../UI.hpp"

// Hàm lưu trạng thái nhân vật 
void savePlayer(const Player& hero) {
    std::filesystem::create_directories("app/data");
    std::ofstream file("app/data/player.txt");
    
    if (file.is_open()) {
        file << hero.name << "\n";
        file << hero.level << " " << hero.exp << "\n";
        file.close();
    }
}

// Hàm nạp hoặc khởi tạo nhân vật mới
void loadOrCreatePlayer(Player& hero) {
    std::filesystem::create_directories("app/data");
    std::ifstream file("app/data/player.txt");

    bool loadSuccess = false;

    if (file.is_open()) {
        if (std::getline(file, hero.name) && (file >> hero.level >> hero.exp)) {
            if (!hero.name.empty()) {
                loadSuccess = true;
            }
        }
        file.close();
    }

    // Nếu nạp file save dc
    if (loadSuccess) {
        std::cout << "[He thong] Chao mung Ki si [" << hero.name << "] tro lai dai lo hoc thuat HCMUS!\n";
    } else {
        // Nếu chưa có file save thì tạo nhân vật mới
        clearScreen();
        std::cout << "==================================================\n";
        std::cout << "       KHOI TAO DIEN MAO - KHAC TEN KI SI         \n";
        std::cout << "==================================================\n";
        std::cout << "Chao mung ban den với mien dat THE LEGEND OF HCMUS!\n";
        std::cout << "Truoc khi nhan kiem vao vung dat du, hay ghi ten minh vao Bang phong than.\n\n";
        std::cout << "-> Nhap ten Ki si cua ban: ";
        std::getline(std::cin, hero.name);

        // Safe check nếu người chơi bấm Enter bỏ trống tên
        if (hero.name.empty()) {
            hero.name = "Ki si vo danh";
        }

        // Khởi tạo chỉ số tân thủ
        hero.level = 1;
        hero.exp = 0;

        // Lưu file ngay lập tức để tạo slot save
        savePlayer(hero);
        std::cout << "\n[Thanh cong] Ki si [" << hero.name << "] da nhan an phong (Level 1). San sang len duong!\n";
    }
}

#endif