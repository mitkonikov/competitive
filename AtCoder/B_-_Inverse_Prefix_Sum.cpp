#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> pref(n);
    for (int i = 0; i < n; i++) {
        cin >> pref[i];
    }
    vector<ll> ans(n);
    ans[0] = pref[0];
    for (int i = 1; i < n; i++) {
        ans[i] = pref[i] - pref[i-1];
    }
    for (auto el: ans) {
        cout << el << " ";
    } cout << endl;
    cout << flush;
    return 0;
}