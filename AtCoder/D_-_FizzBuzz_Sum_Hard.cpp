#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = (n * (n + 1)) / 2;
    ll lcm = a * b / gcd(a, b);
    ll As = n / a;
    ll Bs = n / b;
    ll Ls = n / lcm;
    ll sumA = (As * (As + 1)) / 2 * a;
    ll sumB = (Bs * (Bs + 1)) / 2 * b;
    ll sumL = (Ls * (Ls + 1)) / 2 * lcm;
    ans = ans - sumA - sumB + sumL;
    // 5+10+15
    // (1+2+3)*5
    cout << ans << endl;
    cout << flush;
    return 0;
}