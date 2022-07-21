#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> frq_front(2e5 + 100, 0);
    vector<int> frq_back(2e5 + 100, 0);
    frq_front[v[0]]++;
    for (int i = 1; i < n; i++) {
        frq_back[v[i]]++;
    }

    ll ans = 0;
    ll same = frq_back[v[0]];
    for (int i = 1; i < n - 1; i++) {
        frq_back[v[i]]--;
        same -= frq_front[v[i]];

        ll all = (ll)(i) * (ll)(n - i - 1);
        ans = ans - same - (ll)frq_front[v[i]] * (ll)(n - i - 1 - frq_back[v[i]]) - (ll)frq_back[v[i]] * (ll)(i - frq_front[v[i]]) + all;

        frq_front[v[i]]++;
        same += frq_back[v[i]];
    }

    cout << ans << endl;
    return 0;
}