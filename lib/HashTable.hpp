#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include "AVL.hpp"     // Yêu cầu thư viện AVL ở trên
#include <utility>     // Chứa std::pair

template <typename K, typename V>
struct HashTable {
    AVL<std::pair<K, V>>* table = nullptr; // Mảng các cây AVL
    int capacity = 0;
    int currentSize = 0;
};

// --- Các hàm cốt lõi ---
// Hàm băm phụ trợ (Thành viên A tự cài đặt hash function)
template <typename K, typename V> int hashFunction(const HashTable<K, V>& ht, const K& key);

template <typename K, typename V> void initHashTable(HashTable<K, V>& ht, int cap);
template <typename K, typename V> void insert(HashTable<K, V>& ht, const K& key, const V& value);
template <typename K, typename V> void remove(HashTable<K, V>& ht, const K& key);
template <typename K, typename V> V find(const HashTable<K, V>& ht, const K& key); // Có thể ném ngoại lệ nếu không thấy
template <typename K, typename V> bool contains(const HashTable<K, V>& ht, const K& key);
template <typename K, typename V> int size(const HashTable<K, V>& ht);
template <typename K, typename V> void clear(HashTable<K, V>& ht);

#endif // HASH_TABLE_HPP