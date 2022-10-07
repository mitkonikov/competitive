#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct FenwickTree {
    vector<ll> fwt;
    
    FenwickTree(int n) {
        fwt.resize(n, 0);
    }
    
    void add(int i, ll value = 1) {
        for (i++; i < fwt.size(); i+=i&-i)
            fwt[i] += value;
    }

    ll sum(int i) {
        ll sum = 0;
        for (i++; i > 0; i-=i&-i)
            sum += fwt[i];
        return sum;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<int> left(n), right(n);
    map<int, int> frq_left, frq_right;
    for (int i = 0; i < n; i++) {
        frq_left[a[i]]++;
        left[i] = frq_left[a[i]];
    }
    for (int i = n - 1; i >= 0; i--) {
        frq_right[a[i]]++;
        right[i] = frq_right[a[i]];
    }
    ll ans = 0;
    FenwickTree fwt_right(1e6 + 10);
    for (int i = n - 1; i > 0; i--) {
        fwt_right.add(right[i], 1);
        int L = left[i-1];
        ans += fwt_right.sum(L - 1);
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}