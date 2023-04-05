#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    bool ok = 1;
    for (int i = 1; i < N; i++) {
        if (S[i] == S[i-1]) ok = 0;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}