// Task: https://mendo.mk/Task.do?id=37

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int my = 0;

    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < n; i++) {
        if (i == 0) cin >> my;
        else {
            int x;
            cin >> x;

            pq.push(x);
        }
    }

    int cost = 0;
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        
        if (top < my) continue;

        top--;
        pq.push(top);
        my++;
        cost++;
    }

    cout << cost << endl;

    return 0;
}