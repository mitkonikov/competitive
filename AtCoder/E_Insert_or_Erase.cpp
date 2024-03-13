#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    list<int> A;
    map<int, list<int>::iterator> mp;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.push_back(x);
        mp[x] = prev(A.end());
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            auto it = mp[x];
            mp[y] = A.insert(next(it), y);
        } else {
            int x;
            cin >> x;
            A.erase(mp[x]);
            mp.erase(x);
        }
    }
    for (auto el: A) cout << el << " ";
    cout << endl;
    return 0;
}