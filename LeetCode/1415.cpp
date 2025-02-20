#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> all;
        queue<string> bfs;
        bfs.push("a");
        bfs.push("b");
        bfs.push("c");
        while (!bfs.empty()) {
            auto t = bfs.front();
            bfs.pop();
            if (t.size() == n) {
                all.push_back(t);
                continue;
            }
            for (char ch : { 'a', 'b', 'c' }) {
                if (ch != t.back()) {
                    bfs.push(t + ch);
                }
            }
        }
        if (k > all.size()) return "";
        sort(all.begin(), all.end());
        return all[k-1];
    }
};