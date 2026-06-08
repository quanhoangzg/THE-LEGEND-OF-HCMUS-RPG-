#ifndef UI_HPP
#define UI_HPP

#include <iostream>

void drawTitle() {
    std::cout << "\n=========================================\n";
    std::cout << "        THE LEGEND OF HCMUS (RPG)        \n";
    std::cout << "=========================================\n";
}

void drawDungeonIndexInterface() {
    std::cout << "--- CUON SANG DUNGEON INDEX ---\n";
    std::cout << "1. Tra cuu ma mon hoc (Dungeon)\n";
    std::cout << "2. Them dungeon index moi\n";
    std::cout << "0. Quay lai menu chinh\n";
    std::cout << "-> Lua chon: ";
}

void drawAttackAnimation() {
    std::cout << ">> [HOAT ANH: KI SI CHEM TIEU DIET BOSS] <<\n";
}

void drawWinAnimation() {
    std::cout << ">> [CHUC MUNG BAN DA DANH BAI BOSS {NAME} VOI SO DIEM NGOAN MUC LA {} <<\n";
}

void drawTakeDamage() {
    std::cout << ">> [HOAT ANH: BI BOSS DANH] <<\n";
}

#endif