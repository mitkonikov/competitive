#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // (sum across i of pass[i] / total[i]) / # of classes
        struct Base {
            int pass, total;
            bool operator>(const Base& other) const {
                // ((pass+1)/(total+1)) - (pass/total) > ...
                const double changeMe = (double)(pass + 1) / (total + 1) - ((double)pass / total);
                const double changeHim = (double)(other.pass + 1) / (other.total + 1) - ((double)other.pass / other.total);
                return changeMe < changeHim;
            }
        };
        priority_queue<Base, vector<Base>, greater<Base>> pq;
        for (auto& cl : classes) {
            pq.push({ cl[0], cl[1] });
        }
        for (int i = 0; i < extraStudents; i++) {
            auto top = pq.top();
            pq.pop();
            top.pass++;
            top.total++;
            pq.push(top);
        }
        double ans = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ans += (double)top.pass / top.total;
        }
        return ans / (int)classes.size();
    }
};