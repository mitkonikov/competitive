#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> terms(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            terms[i].push_back(x);
        }
    }
    for (int i = 0; i < q; i++) {
        int s, t; cin >> s >> t; s--; t--;
        cout << terms[s][t] << endl;
    }
    cout << flush;
    return 0;
}