#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    int cur = 1;
    int N = S.size();
    for (int i = 1; i < N; i++) {
        if (S[i] == S[i-1]) {
            cur++;
        } else {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    cout << max(ans, cur) << endl;
    return 0;
}