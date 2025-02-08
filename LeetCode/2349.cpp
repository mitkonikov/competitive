#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
public:
    map<int, int> mp;
    map<int, set<int>> idx;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        auto it = mp.find(index);
        if (it != mp.end()) {
            idx[it->second].erase(index);
        }
        mp[index] = number;
        idx[number].insert(index);
    }
    
    int find(int number) {
        if (idx[number].size() == 0) return -1;
        return *idx[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */