#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> parties(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            parties[i].insert(x-1);
        }
    }

    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
        for (int j = 0; j < n && ok; j++) {
            if (i == j) continue;
            bool okk = false;
            for (int p = 0; p < m; p++) {
                if (parties[p].count(i) && parties[p].count(j)) {
                    okk = true;
                }
            }
            if (!okk) {
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    cout << flush;
    return 0;
}