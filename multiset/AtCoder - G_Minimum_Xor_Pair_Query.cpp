#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline void eraseOne(multiset<int> &s, int value) {
    auto itr = s.find(value);
    if (itr != s.end()){
        s.erase(itr);
    }
}

int main() {
    int Q;
    cin >> Q;
    multiset<int> adj;
    multiset<int> mp;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            mp.insert(x);
            auto it = mp.find(x);
            int to_insert = 0;
            bool both = 1;
            if (it != mp.begin()) {
                to_insert ^= *prev(it);
                int L = *prev(it) ^ x;
                adj.insert(L);
            } else both = 0;
            if (next(it) != mp.end()) {
                to_insert ^= *next(it);
                int R = *next(it) ^ x;
                adj.insert(R);
            } else both = 0;
            if (both) eraseOne(adj, to_insert);
        } else if (t == 2) {
            int x;
            cin >> x;
            auto it = mp.find(x);
            int to_insert = 0;
            bool both = 1;
            if (it != mp.begin()) {
                to_insert ^= *prev(it);
                int L = *prev(it) ^ x;
                eraseOne(adj, L);
            } else both = 0;
            if (next(it) != mp.end()) {
                to_insert ^= *next(it);
                int R = *next(it) ^ x;
                eraseOne(adj, R);
            } else both = 0;
            if (both) adj.insert(to_insert);
            eraseOne(mp, x);
        } else {
            cout << *adj.begin() << endl;
        }
    }
    return 0;
}