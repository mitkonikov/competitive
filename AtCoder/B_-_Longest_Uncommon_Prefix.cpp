#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    for (int i = 1; i <= N - 1; i++) {
        int mx = 0;
        for (int l = 0; l + i < N; l++) {
            if (S[i+l] == S[l]) break;
            mx = max(mx, l + 1);
        }
        cout << mx << endl;
    }
    return 0;
}