#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
 
int a, b, m;
 
inline ll modulo(ll a, ll M) {
    if (a < M) return a;
    return (a % M) + M;
}
 
ll expo(ll b, ll e, ll m) {
    ll result = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = modulo(result * b, m);
            e--;
            continue;
        }
        b = modulo(b * b, m);
        e /= 2;
    }
    return result;
}
 
ll tower(ll left, int k, vector<int>& mods) {
    if (left == 0 || k >= mods.size()) return 1;
    ll e = tower(left - 1, k + 1, mods);
    return expo(a, e, mods[k]);
}
 
int main() {
    cin >> a >> b >> m;
    vector<int> mods{m};
    while (mods.back() != 1) {
        mods.push_back(phi(mods.back()));
    }
    cout << tower(b, 0, mods) % m << endl;
    return 0;
}