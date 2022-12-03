#include <bits/stdc++.h>
#define ll long long

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    int ans = 0;
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            if (i * i == g) ans++;
            else ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}