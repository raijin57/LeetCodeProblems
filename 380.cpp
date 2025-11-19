//
// Created by arsen on 19.11.2025.
//
#include <cstdlib>
#include <vector>
#include <unordered_map>
class RandomizedSet {
    std::vector<int> vectorData_;
    std::unordered_map<int, int> mapData_;
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mapData_.find(val) != mapData_.end()) {
            return false;
        }
        vectorData_.push_back(val);
        mapData_.emplace(val, vectorData_.size() - 1);
        return true;
    }

    bool remove(int val) {
        if (!mapData_.count(val)) {
            return false;
        }
        vectorData_[mapData_[val]] = vectorData_.back();
        mapData_[vectorData_.back()] = mapData_[val];
        mapData_.erase(val);
        vectorData_.pop_back();
        return true;
    }

    int getRandom() {
        return vectorData_[rand() % mapData_.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */