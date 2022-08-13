#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> parents(n);
    vector<int> depth(n);
    depth[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> parents[i];
        parents[i]--;
    }
    for (int i = 1; i < n; i++) {
        depth[i] = depth[parents[i]] + 1;
    }
    cout << depth[n-1] - 1 << endl;
    cout << flush;
    return 0;
}