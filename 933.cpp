//
// Created by arsen on 19.10.2025.
//
#include <map>
class RecentCounter {
    std::map<int, int> map;
    int last_key = 0;
public:
    RecentCounter() {
        map.clear();
    }

    int ping(int t) {
        last_key = t;
        map.insert({t, t - 3000});
        for (auto key : map) {
            if (key.first < map[last_key]) {
                map.erase(key.first);
            } else {
                break;
            }
        }
        return map.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    RecentCounter recentCounter = RecentCounter();
    recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
    recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
    recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
    recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
}