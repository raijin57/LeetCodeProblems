//
// Created by arsen on 16.10.2025.
//

//! Undone

#include <iostream>
#include <unordered_map>
class LRUCache {
    std::unordered_map<int, int> data_;
    std::size_t capacity_ = 0;
   public:
    LRUCache(const int capacity) {
        data_.reserve(capacity);
        this->capacity_ = capacity;
    }

    int get(const int key) {
        for (auto k : data_) {
            if (k.first == key) {
                return k.second;
            }
        }
        return -1;
    }

    void put(const int key, const int value) {
        if (this->get(key) != -1) {
            data_[key] = value;
            return;
        }
        if (capacity_ == data_.size()) {
            data_.erase(capacity_ - 1);
            data_[key] = value;
            return;
        }
        data_.insert(std::make_pair(key, value));
    }
};

int main() {
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    lRUCache->get(1);    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache->get(2);    // returns -1 (not found)
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */