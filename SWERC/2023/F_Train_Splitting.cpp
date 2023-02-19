#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int> > ng(m);
        vector<pair<int, int> > cnt(n);
        for (int i = 0; i < n; i++) {
            cnt[i].second = i;
        }
        for (int i = 0, u, v; i < m; i++) {
            cin >> u >> v;u--;v--;
            ng[i].first = u;
            ng[i].second = v;
            cnt[u].first++;
            cnt[v].first++;
        }
        sort(cnt.begin(), cnt.end());
        if (cnt[0].first == n - 1) {
            cout << 3 << endl;
            for (int i = 0; i < m; i++) {
                bool a = (ng[i].first == 0 || ng[i].second == 0);
                bool b = (ng[i].first == 1 || ng[i].second == 1);
                if (a ^ b)
                    if (a)
                        cout << "1 ";
                    else
                        cout << "2 ";
                else
                    cout << "3 ";
            }
        } else {
            cout << 2 << endl;
            for (int i = 0; i < m; i++) {
                if (ng[i].first == cnt[0].second || ng[i].second == cnt[0].second)
                    cout << "1 ";
                else
                    cout << "2 ";
            }
        }
        cout << endl;
    }
}