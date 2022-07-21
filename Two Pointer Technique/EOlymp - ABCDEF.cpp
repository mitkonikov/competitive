#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    map<ll, int> frq1, frq2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                frq1[a[i] * a[j] + a[k]]++;
                if (a[k] != 0) frq2[(a[i] + a[j]) * a[k]]++;
            }
        }
    }
    ll ans = 0;
    auto p1 = frq1.begin();
    auto p2 = frq2.begin();
    while (p1 != frq1.end() && p2 != frq2.end()) {
        if (p1->first == p2->first) {
            ans += ((ll)p1->second * p2->second);
            p1++; p2++;
        } else if (p1->first > p2->first) {
            p2++;
        } else {
            p1++;
        }
    }
    cout << ans << endl << flush;
    return 0;
}