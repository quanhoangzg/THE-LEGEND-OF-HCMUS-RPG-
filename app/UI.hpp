#ifndef UI_HPP
#define UI_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include "DataTypes.hpp"

inline void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

inline void pauseScreen() {
    std::cout << "\n(Nhan Enter de tiep tuc...)\n";
    std::cin.get();
}

inline void drawTitle() {
    // Chiều rộng ép lại vừa khít 65 ký tự, chữ nằm gọn gàng chính giữa
    std::cout << "  +=============================================================+\n";
    std::cout << "  |                     THE LEGEND OF HCMUS                     |\n";
    std::cout << "  +=============================================================+\n";
}

inline void drawMainMenu(const Player& hero, const std::string& currentSemester) {
    drawTitle();
    
    // THANH TRẠNG THÁI
    std::cout << "  | KI SI: " << hero.name 
              << " | LVL: " << hero.level 
              << " | EXP: " << hero.exp << " |";
              
    if (!currentSemester.empty()) {
        std::cout << " HOC KY: " << currentSemester << " |";
    }
    std::cout << "\n";
    std::cout << "  +-------------------------------------------------------------+\n\n";

    // KHUNG CỔNG HẦM NGỤC (Ép chặt lại, chữ cách cột đuốc đúng ~9 khoảng trắng)
    std::cout << "  /--------------------------------------------------------------\\\n";
    std::cout << " |                                                                |\n";
    std::cout << " |    ( (                                                ) )      |\n";
    std::cout << " |     ) )         1. Cuon sach Dungeon Index           ( (       |\n";
    std::cout << " |    ['']         2. Quan ly Hoc ky                    ['']      |\n";
    std::cout << " |     ||          3. TIEN VAO DUNGEON (COMBAT)          ||       |\n";
    std::cout << " |     ||          4. Nhat ky Mao hiem                   ||       |\n";
    std::cout << " |     ||          5. Kho Thanh tuu (Bang Vang)          ||       |\n";
    std::cout << " |     ||          0. Dang xuat (Thoat game)             ||       |\n";
    std::cout << " |   _||||_                                            _||||_     |\n";
    std::cout << " |  /______\\-----------------------------------------/______\\   |\n";
    std::cout << "  \\-------------------------------------------------------------/\n";

    std::cout << "\n => Lua chon cua ban: ";
}

// Hàm tự động canh giữa tiêu đề cho vừa khung 65 ký tự
inline void drawHeader(const std::string& title) {
    std::cout << "\n  +=============================================================+\n";
    
    int totalWidth = 61; // 65 - 4 (cho 2 viền "  | " và " |")
    int padding = (totalWidth - title.length()) / 2;
    int extra = (totalWidth - title.length()) % 2;
    
    std::cout << "  | ";
    for(int i = 0; i < padding; i++) std::cout << " ";
    std::cout << title;
    for(int i = 0; i < padding + extra; i++) std::cout << " ";
    std::cout << " |\n";
    
    std::cout << "  +=============================================================+\n\n";
}

// Hàm kẻ vạch phân cách
inline void drawDivider() {
    std::cout << "  ---------------------------------------------------------------\n";
}

// Vẽ Menu Phụ: Dungeon Index 
inline void drawDungeonIndexMenu() {
    clearScreen();
    drawHeader("CUON SACH DUNGEON INDEX");
    std::cout << "  |" << std::setw(61) << std::left << "" << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << "         1. Tra cuu ma mon hoc (Dungeon)" << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << "         2. Them Dungeon Index moi" << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << "         0. Quay lai Menu chinh" << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << "" << "|\n";
    drawDivider();
    std::cout << "\n => Lua chon cua ban: ";
}

// Vẽ Menu Phụ: Quản lý Học kỳ
inline void drawSemesterMenu(const std::string& currentSemester) {
    clearScreen();
    drawHeader("HE THONG QUAN LY HOC KY MAO HIEM");
    
    // Gộp trạng thái học kỳ thành 1 chuỗi để tự động canh viền
    std::string semInfo = "      [*] Hoc ky dang chon: [" + (currentSemester.empty() ? "Trong" : currentSemester) + "]";
    
    std::cout << "  |" << std::setw(61) << std::left << "" << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << semInfo << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << "" << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << "         1. Khoi tao / Chon Hoc ky" << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << "         2. Them Dungeon & Sinh san Quai vat (Boss)" << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << "         3. Xem lich trinh tiep can Dungeon" << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << "         0. Quay lai Menu chinh" << "|\n";
    std::cout << "  |" << std::setw(61) << std::left << "" << "|\n";
    drawDivider();
    std::cout << "\n => Lua chon cua ban: ";
}

// Các hoạt ảnh In game
inline void drawStandbyImage(const std::string& heroName, const std::string& bossName, int hp) {
    drawHeader("CHIEN TRUONG AP GIAO");

    // Logic tạo thanh máu dạng thanh trượt slider (Mỗi HP = 1 '#', tối đa 10 vạch)
    std::string hpStr = "HP: [";
    for (int i = 0; i < 10; i++) {
        if (i < hp) hpStr += "#";
        else hpStr += "-";
    }
    hpStr += "] (" + std::to_string(hp) + ")";

    // In thanh trạng thái 2 bên đối đầu (căn lề bằng setw)
    std::cout << "  | " << std::setw(28) << std::left << ("KI SI: " + heroName) 
              << " | " << std::setw(30) << std::right << ("BOSS: " + bossName) << " |\n";
    
    std::cout << "  | " << std::setw(28) << std::left << hpStr
              << " | " << std::setw(30) << std::right << "HP: [??????????] ( ? )" << " |\n";
    
    std::cout << "  +-------------------------------------------------------------+\n";

    std::cout << "  |                                                             |\n";
    std::cout << "  |           _O_                              /)  (\\           |\n";
    std::cout << "  |         // | \\===>                      .-/o \\/ o\\-.        |\n";
    std::cout << "  |            |                           (   _  _   )         |\n";
    std::cout << "  |           / \\                           `\\  \\/  /'          |\n";
    std::cout << "  |                                                             |\n";
    
    drawDivider();
}

inline void drawAttackAnimation() {
    std::cout << "\n";
    std::cout << "  +-------------------------------------------------------------+\n";
    std::cout << "  |                                                             |\n";
    std::cout << "  |           _O_                              /)  (\\           |\n";
    std::cout << "  |         // | \\========================> .-/x \\/ x\\-.        |\n";
    std::cout << "  |            |          <<< CHEM >>>      (  >_  _<  )         |\n";
    std::cout << "  |           / \\                           `\\  \\/  /'          |\n";
    std::cout << "  |                                                             |\n";
    drawDivider();
}

#endif // UI_HPP