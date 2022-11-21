#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct FenwickTree {
    vector<long long> fwt;
    
    FenwickTree(int n) {
        fwt.resize(n, 0);
    }

    void addFWT(int ind, long long val = 1) {
        for (ind++; ind < fwt.size(); ind+=ind&-ind)
            fwt[ind]+=val;
    }

    long long getFWT(int ind) {
        long long s = 0;
        for (ind++; ind > 0; ind-=ind&-ind)
            s += fwt[ind];
        return s;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> comp(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> comp[i];
        a[i] = comp[i];
    }

    int maxElement = 0;

    // index compression
    sort(comp.begin(), comp.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin() + 1;
        if (a[i] > maxElement) maxElement = a[i];
    }

    FenwickTree dp_front(maxElement + 1000);
    FenwickTree dp_back(maxElement + 1000);

    dp_front.addFWT(a[0]);
    for (int i = 2; i < n; i++) {
        dp_back.addFWT(a[i]);
    }

    int front_size = 1;

    ll ans = 0;
    for (int i = 1; i < n-1; i++) {
        ll left = front_size - dp_front.getFWT(a[i]);
        ll right = dp_back.getFWT(a[i]);

        ans += (left * right);
        
        dp_front.addFWT(a[i]);
        dp_back.addFWT(a[i+1], -1);

        front_size++;
    }

    cout << ans << endl;
    
    return 0;
}