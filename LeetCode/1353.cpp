#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<vector<int>> add(1e5 + 10);
        vector<vector<int>> remove(1e5 + 10);
        const int N = events.size();
        vector<bool> visited(N);
        for (int i = 0; i < N; i++) {
            add[events[i][0]].push_back(i);
            remove[events[i][1] + 1].push_back(i);
        }
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 1; i <= 1e5; i++) {
            for (auto& idx: remove[i]) {
                visited[idx] = true;
            }
            for (auto& idx: add[i]) {
                pq.push({ events[idx][1], idx });
            }
            while (pq.size()) {
                auto [ends, idx] = pq.top();
                pq.pop();
                if (!visited[idx]) {
                    visited[idx] = true;
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};