#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n == 1) {
        cout << (a == b) << endl;
        cout << a << ":" << b << endl;
        return 0;
    }
    
    vector<pair<int, int>> ans(n);
    int L = 0, R = n - 1;
    int A = a;
    int B = b;
    for (L = 0; L < min(n, a); L++) {
        if (L == R) {
            if (b == 0) {
                ans[L].first++;
                A--;
            } else {
                break;
            }
        } else {
            ans[L].first++;
            A--;
        }
    }
    if (ans[L].first == 0) L--;
    for (int r = 0; r < min(n, b); r++) {
        if (L == R) {
            if (a == 0) {
                ans[R].second++;
                B--;
            } else {
                break;
            }
        } else {
            ans[R].second++;
            B--;
        }
        R--;
    }
    ans[0].first += A;
    ans.back().second += B;

    int draws = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i].first == ans[i].second) {
            draws++;
        }
    }
    
    cout << draws << endl;
    for (auto el: ans) {
        cout << el.first << ":" << el.second << endl;
    }

    return 0;
}