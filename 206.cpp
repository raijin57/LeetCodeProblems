//
// Created by arsen on 18.10.2025.
//

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;
        for (ListNode* cur = head; cur;) {
            ListNode* tmp = cur->next;
            cur->next = node;
            node = cur;
            cur = tmp;
        }
        return node;
    }
};