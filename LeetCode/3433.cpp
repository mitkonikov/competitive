#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            if (stoi(a[1]) == stoi(b[1])) return a[0] != "MESSAGE";
            return stoi(a[1]) < stoi(b[1]);
        });
        vector<int> ans(numberOfUsers);
        int all = 0;
        const int N = events.size();
        auto split = [](string s) {
            vector<int> result;
            string cur = "";
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ' ') {
                    result.push_back(stoi(cur.substr(2)));
                    cur = "";
                } else {
                    cur += s[i];
                }
            }
            if (!cur.empty()) {
                result.push_back(stoi(cur.substr(2)));
            }
            return result;
        };
        set<int> online;
        for (int i = 0; i < numberOfUsers; i++) online.insert(i);
        map<int, vector<int>> offline;
        for (int i = 0; i < N; i++) {
            int time = stoi(events[i][1]);
            while (!offline.empty() && offline.begin()->first <= time) {
                for (auto& el : offline.begin()->second) {
                    online.insert(el);
                }
                offline.erase(offline.begin());
            }
            if (events[i][0] == "MESSAGE") {
                if (events[i][2] == "ALL") {
                    all++;
                } else if (events[i][2] == "HERE") {
                    for (auto el : online) {
                        ans[el]++;
                    }
                } else {
                    auto ids = split(events[i][2]);
                    for (auto el : ids) {
                        ans[el]++;
                    }
                }
            } else {
                online.erase(stoi(events[i][2]));
                offline[stoi(events[i][1]) + 60].push_back(stoi(events[i][2]));
            }
        }
        for (auto& el : ans) el += all;
        return ans;
    }
};