#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, vector<int>> dp;

void printArray(int p[], int n) {
    ll product = 1;
    for (int i = 0; i < n; i++) {
        if (product * p[i] > 1e9) {
            return;
        }
        product *= p[i];
    }

    vector<int> current(n);
    for (int i = 0; i < n; i++) current[i] = p[i];
    sort(current.begin(), current.end());
    
    if (dp[product].empty()) {
        dp[product] = current;
    } else {
        if (dp[product].size() > n) dp[product] = current;
    }
}

void precalc(int n) {
    int p[n];   // An array to store a partition
    int k = 0;  // Index of last element in a partition
    p[k] = n;   // Initialize first partition as number itself
    while (true) {
        printArray(p, k + 1);
        int rem_val = 0;
        while (k >= 0 && p[k] == 1) {
            rem_val += p[k];
            k--;
        }

        if (k < 0) return;
        p[k]--;
        rem_val++;
        while (rem_val > p[k]) {
            p[k + 1] = p[k];
            rem_val = rem_val - p[k];
            k++;
        }
        p[k + 1] = rem_val;
        k++;
    }
}

void testCase() {
    int P;
    cin >> P;
    auto it = dp.find(P);
    if (it == dp.end()) {
        cout << -1 << endl;
        return;
    }
    cout << it->second.size() << " ";
    for (auto el: it->second) {
        cout << el << " ";
    } cout << endl;
}

int main() {
    precalc(41);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        testCase();
    }

    cout << flush;
    return 0;
}