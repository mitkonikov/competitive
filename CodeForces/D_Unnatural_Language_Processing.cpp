#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string T;
    cin >> T;
    vector<char> C = { 'b', 'c', 'd' };
    vector<char> V = { 'a', 'e' };
    vector<bool> dp(N + 10);
    vector<int> parents(N + 10);
    dp[0] = 1;
    parents[0] = -1;
    auto isC = [&](char c) {
        for (auto el: C) if (c == el) return true;
        return false;
    };
    auto isV = [&](char c) {
        for (auto el: V) if (c == el) return true;
        return false;
    };
    for (int i = 0; i < N; i++) {
        if (!dp[i]) continue;
        string S = "";
        for (int j = 0; j < 3; j++) {
            if (i + j < N) {
                if (isC(T[i+j])) {
                    S += "C";
                } else {
                    S += "V";
                }
            }
        }

        if (S.size() >= 2 && S.substr(0, 2) == "CV") {
            dp[i + 2] = true;
            parents[i + 2] = i;
        }
            
        if (S.size() >= 3 && S.substr(0, 3) == "CVC") {
            dp[i + 3] = true;
            parents[i + 3] = i;
        }
    }

    assert(dp[N]);

    int start = N;
    vector<int> dots;
    while (start > 0) {
        start = parents[start];
        dots.push_back(start);
    }

    int p = 0;
    reverse(dots.begin(), dots.end());
    for (int i = 0; i < N; i++) {
        if (p < dots.size() && dots[p] == i) {
            p++;
            if (i) cout << ".";
        }
        cout << T[i];
    }
    cout << endl;
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