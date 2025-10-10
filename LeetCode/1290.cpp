#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    int get(ListNode* head, int val) {
        if (head->next == nullptr) return val * 2 + head->val;
        return get(head->next, val * 2 + head->val);
    }

    int getDecimalValue(ListNode* head) {
        return get(head, 0);
    }
};