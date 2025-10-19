//
// Created by arsen on 19.10.2025.
//
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return divide(lists, 0, lists.size() - 1);
    }
    ListNode* divide(std::vector<ListNode*> lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        ListNode* leftlist = divide(lists, left, mid);
        ListNode* rightlist = divide(lists, mid + 1, right);
        return mergeTwo(leftlist, rightlist);
    }
    ListNode* mergeTwo(ListNode* first, ListNode* second) {
        if (!first) {
            return second;
        }
        if (!second) {
            return first;
        }
        if (first->val < second->val) {
            first->next = mergeTwo(first->next, second);
            return first;
        }
        second->next = mergeTwo(first, second->next);
        return second;
    }
};