#include <bits/stdc++.h>

using namespace std;

void testCase() {
    int n, a, b;
    cin >> n >> a >> b;
    int A = a;
    int B = b;

    vector<int> v(n);
    bool fail = false;
    int a_ptr = 0;
    int b_ptr = n-1;
    v[a_ptr++] = a;
    v[b_ptr--] = b;

    vector<bool> visited(n, false);
    visited[a] = true;
    visited[b] = true;

    for (int i = b+1; i <= n; i++) {
        if (visited[i]) continue;
        if (a_ptr == n) {
            fail = true;
            break;
        }

        v[a_ptr++] = i;
        visited[i] = true;
    }

    for (int i = 1; i < a; i++) {
        if (visited[i]) continue;
        if (b_ptr == -1) {
            fail = true;
            break;
        }

        v[b_ptr--] = i;
        visited[i] = true;
    }

    for (int i = a+1; i < b; i++) {
        if (visited[i]) continue;
        if (a_ptr == n) {
            fail = true;
            break;
        }

        v[a_ptr++] = i;
        visited[i] = true;
    }

    if (fail) {
        cout << -1 << endl;
        return;
    }

    set<int> s;
    for (auto c: v) {
        if (c < 1) fail = true;
        if (c > n) fail = true;
        s.insert(c);
    }

    int MIN = INT_MAX;
    int MAX = 0;
    for (int i = 0; i < n/2; i++) MIN = min(MIN, v[i]);
    for (int i = n/2; i < n; i++) MAX = max(MAX, v[i]);

    if (fail || MIN != A || MAX != B || s.size() != n) {
        cout << -1 << endl;
        return;
    }

    for (auto c: v) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}