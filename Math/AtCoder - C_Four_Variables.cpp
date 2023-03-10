#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> div(N + 100);
    div[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (j * j == i) div[i]++;
                else div[i] += 2;
            }
        }
    }
    ll ans = 0;
    for (int L = 1; L <= N - 1; L++) {
        int R = N - L;
        ans += (ll)div[L] * div[R];
    }
    cout << ans << endl;
    return 0;
}