#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline bool eraseOne(multiset<int> &s, int value) {
    auto itr = s.find(value);
    if (itr != s.end()){
        s.erase(itr);
        return true;
    }

    return false;
}

int main() {
    int q;
    cin >> q;
    multiset<int> ms;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            ms.insert(x);
        } else if (t == 2) {
            int x, c;
            cin >> x >> c;
            for (int i = 0; i < c; i++) {
                bool ok = eraseOne(ms, x);
                if (!ok) break;
            }
        } else {
            cout << *ms.rbegin() - *ms.begin() << endl;
        }
    }
    cout << flush;
    return 0;
}