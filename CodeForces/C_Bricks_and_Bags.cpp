#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    ll ans = 0;

    vector<ll> w1, w2, w3;
    w2.push_back(a.front());
    w3.push_back(a.back());

    for (int i = n - 2; i >= 1; i--) {
        w1.push_back(a[i]);
    }

    ans = max(ans, 
        (ll)abs(w1.back() - w2.back()) + 
            abs(w2.back() - w3.back())
    );

    while (w1.size() > 1) {
        w2.push_back(w1.back());
        w1.pop_back();
        ans = max(ans, 
        (ll)abs(w1.back() - w2.back()) + 
            abs(w2.back() - w3.back())
        );
    }

    w1.clear();
    w2.clear();
    w3.clear();

    w3.push_back(a.front());
    w2.push_back(a.back());

    for (int i = 1; i < n - 1; i++) {
        w1.push_back(a[i]);
    }

    ans = max(ans, 
        (ll)abs(w1.back() - w2.back()) + 
            abs(w2.back() - w3.back())
    );

    while (w1.size() > 1) {
        w2.push_back(w1.back());
        w1.pop_back();
        ans = max(ans, 
        (ll)abs(w1.back() - w2.back()) + 
            abs(w2.back() - w3.back())
        );
    }

    cout << ans << endl;
    return;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}