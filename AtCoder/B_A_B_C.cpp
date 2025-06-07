#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    const int N = S.size();
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] != 'A') continue;
        for (int j = i + 1; j < N; j++) {
            if (S[j] != 'B') continue;
            for (int k = j + 1; k < N; k++) {
                if (S[k] != 'C') continue;
                ans += (j - i == k - j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}