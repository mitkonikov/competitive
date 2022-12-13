#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    map<pair<int, int>, int> frq;
    for (int i = 0; i < n; i++) {
        int H, S;
        cin >> H >> S;
        frq[{ H, S }]++;
    }
    int ans = 0;
    for (auto p: frq) {
        ans = max(ans, p.second);
    }
    cout << ans << endl;
    return 0;
}