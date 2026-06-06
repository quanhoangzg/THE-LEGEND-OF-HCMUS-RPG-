#ifndef UI_HPP
#define UI_HPP

#include <iostream>

void drawTitle() {
    std::cout << "\n=========================================\n";
    std::cout << "        THE LEGEND OF HCMUS (RPG)        \n";
    std::cout << "=========================================\n";
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