//
// Created by arsen on 19.10.2025.
//
#include <vector>
class Solution {
public:
    int maxDistToClosest(std::vector<int>& seats) {
        int n = seats.size();
        int prev = -1;
        int next = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                prev = i;
            } else {
                while (next < n && seats[next] == 0 || next < i) {
                    ++next;
                }
                int left = prev == -1 ? n : i - prev;
                int right = next == n ? n : next - i;
                ans = std::max(ans, std::min(left, right));
            }
        }
        return ans;
    }
};