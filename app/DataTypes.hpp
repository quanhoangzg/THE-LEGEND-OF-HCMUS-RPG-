#ifndef DATATYPES_HPP
#define DATATYPES_HPP

#include <string>
#include "../lib/Queue.hpp"

// Data cho monster index (HashTable)
struct CourseInfo {
    std::string courseID;
    int credits;
    std::string tips;
};


/*
Cấu trúc này nhằm biểu diễn điều sau:
Ví dụ boss giữa kì vi tích phân
 name = "Giua ki"
 weight = 0.25 (là môn này chiếm 25% tổng điểm thang 10)
*/
struct Boss {
    std::string name;
    float weight; // Để lưu hệ số điểm
};

// Dữ liệu cho môn học trong học kỳ đó
struct Dungeon {
    std::string courseID;
    int playerHP;
    int priority;
    Queue<Boss> bossQueue;

    bool operator<(const Dungeon& other) const {
        return priority < other.priority; // Môn nào có độ ưu tiên lớn hơn thì lên trước
    }
};

// Dữ liệu cho kị sĩ (Main)
struct Player {
    std::string name;

    int level;
    int exp;
};

struct LogEntry { // Dùng cho Linked List
    std::string courseID;
    std::string bossName;
    float score; // Điểm riêng của bài thi này
};

struct CourseRecord {
    std::string courseID;
    float finalGPA;
    bool isPassed;
};

#endif