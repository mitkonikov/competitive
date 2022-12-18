#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    bool ok = true;
    vector<pair<int, int>> p(3);
    for (int i = 0; i < 3; i++) cin >> p[i].first >> p[i].second;
    vector<int> order(3);
    iota(order.begin(), order.end(), 0);
    do {
        auto p1 = p[order[0]];
        auto p2 = p[order[1]];
        auto p3 = p[order[2]];
        if (p1.first == p2.first && p2.second == p3.second) {
            ok = false;
            break;
        }
    } while (next_permutation(order.begin(), order.end()));
    cout << (ok ? "YES" : "NO") << endl;
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