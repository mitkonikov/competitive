#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> visited(n);
        const int M = meetings.size();
        struct room {
            long long ends, id;
            bool operator>(const room& other) const {
                if (ends == other.ends) return id > other.id;
                return ends > other.ends;
            }
        };
        priority_queue<room, vector<room>, greater<room>> pq;
        set<int> free_rooms;
        for (int i = 0; i < n; i++) {
            free_rooms.insert(i);
        }
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });
        for (int i = 0; i < M; i++) {
            while (pq.size() && pq.top().ends <= meetings[i][0]) {
                free_rooms.insert(pq.top().id);
                pq.pop();
            }

            if (free_rooms.size()) {
                auto it = free_rooms.begin();
                int id = *it;
                free_rooms.erase(it);
                pq.push({ meetings[i][1], id });
                visited[id]++;
            } else {
                auto t = pq.top();
                pq.pop();
                long long new_end = t.ends + meetings[i][1] - meetings[i][0];
                visited[t.id]++;
                t.ends = new_end;
                pq.push(t);
            }
        }
        int mx = *max_element(visited.begin(), visited.end());
        for (int i = 0; i < n; i++) {
            if (visited[i] == mx) return i;
        }
        return 0;
    }
};