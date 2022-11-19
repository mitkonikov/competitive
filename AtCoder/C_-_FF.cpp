#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    map<pair<int, int>, bool> mp;
    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            mp[{ u, v }] = true;
        } else if (type == 2) {
            mp[{ u, v }] = false;
        } else {
            cout << (mp[{ u, v }] && mp[{ v, u }] ? "Yes" : "No") << endl;
        }
    }    

    return 0;
}