#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int N = S.size();
    int M = T.size();
    int matches = 0;
    auto match = [&](int a, int b) {
        if (S[a] == '?' || T[b] == '?' || S[a] == T[b]) return true;
        return false;
    };
    for (int i = 0; i < M; i++) {
        matches += match(N-M+i, i);
    }
    for (int i = 0; i <= M; i++) {
        // add S[i]
        // delete S[N-M-i]
        cout << (matches == M ? "Yes" : "No") << endl;
        matches += match(i, i);
        if (N-M+i < N) matches -= match(N-M+i, i);
    }
    return 0;
}