#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:
    vector<int> n1, n2;
    map<int, int> frq;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int i = 0; i < n2.size(); i++) frq[n2[i]]++;
    }
    
    void add(int index, int val) {
        frq[n2[index]]--;
        n2[index] += val;
        frq[n2[index]]++;
    }
    
    int count(int tot) {
        int count = 0;
        for (int i = 0; i < n1.size(); i++) {
            count += frq[tot - n1[i]];
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */