#ifndef COMBAT_SYS_HPP
#define COMBAT_SYS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "../DataTypes.hpp"
#include "SemesterSys.hpp" 
#include "../UI.hpp"       

// Hàm cập nhật thông tin sau khi đánh boss
void syncSemesterFile() {
    if (currentSemesterName.empty()) return;
    std::string folderPath = "app/data/" + currentSemesterName;
    std::ofstream file(folderPath + "/dungeons.txt", std::ios::trunc); 
    
    if (!file.is_open()) return;

    PriorityQueue<Dungeon> tempPQ = semesterPQ;
    while (!isEmpty(tempPQ)) {
        Dungeon d = top(tempPQ);
        int bossCount = size(d.bossQueue);
        file << d.courseID << " " << d.priority << " " << d.playerHP << " " << bossCount << "\n";
        
        QueueNode<Boss>* current = d.bossQueue.front;
        while (current != nullptr) {
            file << current->data.name << " " << current->data.weight << "\n";
            current = current->next;
        }
        pop(tempPQ);
    }
    file.close();
}

// Flow chiến các dungeons
void enterDungeon(Player& hero) {
    if (currentSemesterName.empty() || isEmpty(semesterPQ)) {
        std::cout << "[!] Vung dat yen binh. Khong co Dungeon nao dang mo trong hoc ky nay!\n";
        return;
    }

    // In ra các dungeon để chọn
    Dungeon tempList[50]; 
    int count = 0;

    // Rút tuần tự 
    while (!isEmpty(semesterPQ) && count < 50) {
        tempList[count] = top(semesterPQ);
        pop(semesterPQ);
        count++;
    }

    // UI chọn Dungeon
    std::cout << "=== BAN DO CHIEN TRUONG HOC KY: " << currentSemesterName << " ===\n";
    std::cout << "(Danh sach sap xep theo Muc do uu tien ban thiet lap)\n\n";
    for (int i = 0; i < count; i++) {
        std::cout << i + 1 << ". Vung dat: " << tempList[i].courseID 
                  << " | Do uu tien: " << tempList[i].priority 
                  << " | HP hien tai: " << tempList[i].playerHP << "\n";
        
        // In nhanh các con boss đang xếp hàng của môn đó
        QueueNode<Boss>* bNode = tempList[i].bossQueue.front;
        std::cout << "   -> Quai vat con lai: ";
        if (bNode == nullptr) std::cout << "Trong.";
        while (bNode != nullptr) {
            std::cout << "[" << bNode->data.name << "] ";
            bNode = bNode->next;
        }
        std::cout << "\n--------------------------------------------------\n";
    }

    int choice;
    std::cout << "-> Nhap so thu tu Dungeon ban muon tien vao thach thuc: ";
    std::cin >> choice;
    std::cin.ignore();

    // Safe check
    if (choice < 1 || choice > count) {
        std::cout << "[!] Lua chon sai lam! Ban bi lac duong, quay ve Menu chinh.\n";
        // Trả lại vào Piority Queue
        for (int i = 0; i < count; i++) {
            push(semesterPQ, tempList[i]);
        }
        return;
    }

    // Tách riêng Dungeon được chọn ra để xử lý giao tranh
    int chosenIndex = choice - 1;
    Dungeon currentDungeon = tempList[chosenIndex];

    // Logic chiến đấu
    clearScreen();
    Boss targetBoss = front(currentDungeon.bossQueue);

    drawStandbyImage(hero.name, targetBoss.name);

    std::cout << "=== TIEN VAO DUNGEON: " << currentDungeon.courseID << " ===\n";
    std::cout << "[!] Quai vat [" << targetBoss.name << "] (Sat thuong/He so: " << targetBoss.weight * 100 << "%) lao ra chan duong!\n";

    float score;
    std::cout << "\n>>> Nhap diem so tran chien cua ban (0 - 10): ";

    if (!(std::cin >> score) || score < 0 || score > 10) { // check safe nếu ko phải chữ và không nằm trong khoảng từ 0 - 10
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        score = -1; // Coi như chọn quay lại
    } else {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (score == -1) {
        std::cout << "\n[Rut lui] Ki si chu dong thu kiem, quay xe ve thanh tri an toan!\n";
                for (int i = 0; i < count; i++) {
            if (i == chosenIndex) {
                push(semesterPQ, currentDungeon); // Nhét lại môn hiện tại (Boss vẫn còn nguyên)
            } else {
                push(semesterPQ, tempList[i]);    // Nhét lại các môn kia
            }
        }
        syncSemesterFile(); 
        return; // Thoát hẳn hàm enterDungeon để về menu chính
    }
    drawAttackAnimation();

    if (score >= 5.0f) {
        std::cout << "\n>>> [WIN ANIMATION: CHIEN THANG AP DAO!] <<<\n";
        std::cout << "Ban da vuot qua bai kiem tra " << targetBoss.name << " voi diem so " << score << "!\n";
        hero.exp += 10; 
    } else {
        std::cout << "\n>>> [LOSE ANIMATION: BAN BI TRUNG DON!] <<<\n";
        std::cout << "Diem so " << score << " khong dat! Ban mat 1 HP trong vung dat nay!\n";
        currentDungeon.playerHP--;
    }

    // Hủy boss ở Queue bất kể thắng thua
    dequeue(currentDungeon.bossQueue); 

    // Trả lại các môn ko dc chọn vào Piority Queue
    for (int i = 0; i < count; i++) {
        if (i == chosenIndex) continue;
        push(semesterPQ, tempList[i]);
    }

    // Đối với môn được chọn thì quyết định logicđậu hhay rớt
    if (currentDungeon.playerHP <= 0) {
        std::cout << "\n[GAME OVER] Kị si da kiet suc tai Dungeon [" << currentDungeon.courseID << "].\n";
        std::cout << "Ban da rot mon! Dungeon nay dong cua vinh vien vao ky nay.\n";
    } 
    else if (isEmpty(currentDungeon.bossQueue)) {
        std::cout << "\n[CLEAR!] Chuc mung ban da quet sach quai vat, HOAN THANH mon [" << currentDungeon.courseID << "]!\n";
        hero.exp += 50; 
    } 
    else {
        std::cout << "\n[Rut lui] Tran chien ket thuc. Ban rut lui an toan khoi [" << currentDungeon.courseID << "].\n";
        // Còn boss thì đẩy vào Piority Queue tiếp
        push(semesterPQ, currentDungeon);
    }

    // ghi đè lại file xử lí
    syncSemesterFile();
}

#endif 