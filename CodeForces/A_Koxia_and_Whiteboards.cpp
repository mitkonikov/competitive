#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(a[i]);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        pq.pop();
        pq.push(x);
    }
    ll sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}