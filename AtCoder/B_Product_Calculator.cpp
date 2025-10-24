#include <bits/stdc++.h>
#define ll __int128_t
#define endl '\n'

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ll X;
        long long x;
        cin >> x;
        X = x;
        ans = ans * X;
        int count = 0;
        ll t = ans;
        while (t > 0) {
            t /= 10;
            count++;
        }
        if (count > K) {
            ans = 1;
        }
    }
    cout << (long long)ans << endl;
    return 0;
}