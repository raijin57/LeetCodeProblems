//
// Created by arsen on 10.07.2025.
//
#include <string>
#include <unordered_map>
#include <vector>
struct CompareByInt {
    bool operator()(std::pair<std::string, int> const& a, std::pair<std::string, int> const& b) const {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};
class TimeMap {
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> data_;

   public:
    TimeMap() {}
    void set(std::string key, std::string value, int timestamp) {
        data_[key].emplace_back(timestamp, value);
    }
    std::string get(std::string key, int timestamp) {
        auto it = data_.find(key);
        if (it == data_.end()) {
            return "";
        }
        auto& vector = it->second;
        int left = 0;
        int right = int(vector.size()) - 1;
        int index = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (vector[mid].first == timestamp) {
                index = mid;
                break;
            }
            if (vector[mid].first > timestamp) {
                right = mid - 1;
            } else {
                index = mid;
                left = mid + 1;
            }
        }
        if (index == -1) {
            return "";
        }
        return vector[index].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */