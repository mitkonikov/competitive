#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, pair<int, int>> v;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s[i] == '1') v[x].first++;
        else v[x].second++;
    }
    int adult = 0;
    for (auto el: v) {
        adult += el.second.first;
    }
    int ans = adult;
    int mxans = adult;
    for (auto el: v) {
        ans -= el.second.first;
        ans += el.second.second;
        mxans = max(mxans, ans);
    }
    cout << mxans << endl;
    cout << flush;
    return 0;
}