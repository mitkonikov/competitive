#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
struct FenwickTree {
    vector<ll> fwt;
 
    FenwickTree(int n) {
        fwt.resize(n, 0);
    }
 
    void addFWT(int ind, ll val = 1) {
        for (ind++; ind < fwt.size(); ind += ind & (-ind))
            fwt[ind] += val;
    }
 
    ll getFWT(int ind) {
        ll res = 0;
        for (ind++; ind > 0; ind -= ind & -ind)
            res += fwt[ind];
 
        return res;
    }
};
 
template<typename T> 
T bin(function<bool(T)> f, T start, T end) {
    if (end <= start) return end;
    if (!f(end - 1)) return end;
    while (end - start > 1) {
        T mid = (start + end) / 2;
        if (f(mid)) end = mid; else start = mid;
    }
 
    return (f(start) ? start : end);
}
 
int main(){
    int n, q;
    cin >> n;
    n--;
    vector<ll> v(n);
    FenwickTree fwt(n + 10);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        fwt.addFWT(i, v[i]);
    }
 
    cin >> q;
    for (int i = 0; i < q + 1; i++) {
        ll ans = LLONG_MAX;
        int id = bin<int>([&](int i) {
            ll c1 = fwt.getFWT(i);
            ll c2 = fwt.getFWT(n) - c1;
            ans = min(ans, abs(c2 - c1));
            return (c1 >= c2);
        }, 0, n);
 
        cout << ans << '\n';
 
        if (i == q) break;
 
        int x, y;
        cin >> x >> y;
        fwt.addFWT(x - 1, y - v[x-1]);
        v[x-1] = y; 
    }
 
    return 0;
}