#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> sq(k);
    for (int i = 0; i < k; i++) cin >> sq[i];
    for (int qq = 0; qq < q; qq++) {
        int x;
        cin >> x;
        x--;
        if (x+1 < k && sq[x+1] == sq[x]+1) continue;
        if (sq[x] + 1 > n) continue;
        sq[x]++;
    }
    for (auto el: sq) {
        cout << el << " ";
    } cout << endl;
    cout << flush;
    return 0;
}