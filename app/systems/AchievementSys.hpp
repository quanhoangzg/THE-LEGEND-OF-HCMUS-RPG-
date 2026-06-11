#ifndef ACHIEVEMENT_SYS_HPP
#define ACHIEVEMENT_SYS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "../DataTypes.hpp"
#include "../../lib/LinkedList.hpp" 
#include "../../lib/AVL.hpp"        
#include "../../lib/Algorithms.hpp" 

inline SinglyLinkedList<LogEntry> combatHistory = {nullptr, nullptr, 0}; 
inline AVLTree<Relic> achievementTree = {nullptr};


void loadRecords() { // Nạp dữ liệu từ file khi mở game
    std::filesystem::create_directories("app/data/records");

    std::ifstream hFile("app/data/records/history.txt");
    if (hFile.is_open()) {
        std::string cID, bName;
        float sc;
        while (hFile >> cID >> bName >> sc) {
            LogEntry entry = {cID, bName, sc};
            insertAtFront(combatHistory, entry);
        }
        hFile.close();
    }

    std::ifstream aFile("app/data/records/achievements.txt");
    if (aFile.is_open()) {
        std::string cID;
        float totalSc;
        while (aFile >> cID >> totalSc) {
            Relic r = {cID, totalSc};
            insert(achievementTree, r);
        }
        aFile.close();
    }
}

void logCombatHistory(const std::string& courseID, const std::string& bossName, float score) {
    LogEntry entry = {courseID, bossName, score};
    insertAtFront(combatHistory, entry); 

    std::filesystem::create_directories("app/data/records");

    std::ofstream file("app/data/records/history.txt", std::ios::app);
    if (file.is_open()) {
        file << courseID << " " << bossName << " " << score << "\n";
        file.close();
    } else {
        std::cout << "[Loi] Khong the ghi file history.txt!\n"; // Thêm log để bắt lỗi nếu có
    }
}

void viewCombatHistory() {
    std::cout << "=== NHAT KY MAO HIEM (Lich su gan nhat hien len dau) ===\n";
    if (isEmpty(combatHistory)) {
        std::cout << "[!] Ki si chua tung tham gia tran chien nao.\n";
        return;
    }

    SLLNode<LogEntry>* current = combatHistory.head; 
    int count = 1;
    while (current != nullptr) {
        std::cout << count++ << ". Vung dat: [" << current->data.courseID 
                  << "] | Doi dau: [" << current->data.bossName 
                  << "] | Diem so: " << current->data.score << "\n";
        current = current->next;
    }
}

// Lưu Achievement 
void saveAchievement(const std::string& courseID, float totalScore) {
    Relic r = {courseID, totalScore};
    insert(achievementTree, r); 
    
    std::filesystem::create_directories("app/data/records");

    std::ofstream file("app/data/records/achievements.txt", std::ios::app);
    if (file.is_open()) {
        file << courseID << " " << totalScore << "\n";
        file.close();
    } else {
        std::cout << "[Loi] Khong the ghi file achievements.txt!\n";
    }
}

void extractAVLToArray(AVLNode<Relic>* node, Relic arr[], int& index) {
    if (node == nullptr) return;
    extractAVLToArray(node->left, arr, index);
    arr[index++] = node->data;
    extractAVLToArray(node->right, arr, index);
}


// Bảng vàng vương miện (quicksort)
struct CompareRelicDescending {
    bool operator()(const Relic& a, const Relic& b) const {
        return a.totalScore > b.totalScore; 
    }
};

void viewLeaderboard() {
    std::cout << "=== BANG VANG THANH TUU (LEADERBOARD) ===\n";
    
    Relic arr[100]; 
    int count = 0;
    
    // Rút dữ liệu từ Cây AVL ra mảng
    extractAVLToArray(achievementTree.root, arr, count);
    
    if (count == 0) {
        std::cout << "[!] Chua co mon hoc nao duoc pha dao trong lich su!\n";
        return;
    }

    quickSort(arr, count, CompareRelicDescending());

    for (int i = 0; i < count; i++) {
        if (i == 0) {
            std::cout << " [W] (Vuong mien) "; 
        } else {
            std::cout << " [V] (Hoan thanh) ";
        }
        std::cout << arr[i].courseID << " | Tong diem (GPA): " << arr[i].totalScore << "\n";
    }
}

#endif 