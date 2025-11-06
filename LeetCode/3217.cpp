#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for (auto& el : nums) st.insert(el);
        ListNode* cur = head;
        while (cur->next != nullptr) {
            if (st.count(cur->next->val)) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return (st.count(head->val) ? head->next : head);
    }
};