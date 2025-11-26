//
// Created by arsen on 26.11.2025.
//
#include <cstddef>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        ListNode* turtle = head;
        ListNode* hare = head->next;
        while (hare && hare->next) {
            turtle = turtle->next;
            hare = hare->next->next;
            if (turtle == hare) {
                return true;
            }
        }
        return false;
    }
};