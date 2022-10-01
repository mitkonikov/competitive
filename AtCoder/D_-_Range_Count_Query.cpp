#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 10);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    for (int i = 0; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        
        int L = lower_bound(adj[x].begin(), adj[x].end(), l) - adj[x].begin();
        int R = upper_bound(adj[x].begin(), adj[x].end(), r) - adj[x].begin();
        cout << R - L << endl;
    }

    cout << flush;
    return 0;
}