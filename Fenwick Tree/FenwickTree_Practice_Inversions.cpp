#include <bits/stdc++.h>

using namespace std;

vector<long long> fwt(0);
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

int main() {
    freopen("inverse.in", "r", stdin); freopen("inverse.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> comp(n);
    int minElement = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        minElement = min(minElement, a[i]);
    }

    for (int i = 0; i < n; i++) {
        a[i] += abs(minElement);
        comp[i] = a[i];
    }

    // index compression
    int maxElement = INT_MIN;
    sort(comp.begin(), comp.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin() + 1;
        if (a[i] > maxElement) maxElement = a[i];
    }

    long long count = 0;
    fwt.resize(maxElement+10, 0);
    for (int i = n-1; i >= 0; i--) {
        count += getFWT(a[i]-1);
        addFWT(a[i], 1);
    }

    cout << count << endl;

    return 0;
}