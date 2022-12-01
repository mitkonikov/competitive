// Task: https://mendo.mk/Task.do?id=274

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pq.push({ x, i+1 });
    }
    ll taken = 0;
    while (!pq.empty()) {
        auto t = pq.top();
        auto top = t.first;
        auto id = t.second;
        pq.pop();
        top -= taken;
        if (top == 0) continue;
        
        if (top * (pq.size() + 1) > k) {
            // is it going to be inside or not?
            // (top - 1) * (pq.size() + 1) + top.index
            ll times = k / ((int)pq.size() + 1);
            ll left = k % ((int)pq.size() + 1);
            
            if (times >= (top - 1) && left >= id) {
                cout << pq.size() << endl;
            } else {
                cout << pq.size() + 1 << endl;
            }

            return 0;
        }
        
        k -= top * (pq.size() + 1);
        taken += top;
    }
    cout << 0 << endl;
    return 0;
}