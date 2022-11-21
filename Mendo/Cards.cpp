#include <bits/stdc++.h>

using namespace std;

int cost(vector<bool> a, int k, bool goal) {
    int result = 0;

    int n = a.size();
    vector<bool> flip(n, false);
    bool current_flip = false;
    for (int i = 0; i < n; i++) {
        current_flip ^= flip[i];
        a[i] = a[i] ^ current_flip;
        if (a[i] != goal) {
            if (i + k - 1 >= n) return INT_MAX;
            
            flip[i+k] = flip[i+k] ^ true;
            current_flip ^= true;
            result++;
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<bool> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
    }

    int ans = min(cost(a, k, 0), cost(a, k, 1));

    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}