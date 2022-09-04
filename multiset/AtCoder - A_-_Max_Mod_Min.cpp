#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline void eraseOne(multiset<int> &s, int value) {
    auto itr = s.find(value);
    if (itr != s.end()){
        s.erase(itr);
    }
}

int main() {
    int n;
    cin >> n;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int op = 0;
    while (s.size() != 1) {
        auto mn = *s.begin();
        auto mx = *prev(s.end());
        eraseOne(s, mx);
        mx = mx % mn;
        if (mx > 0) {
            s.insert(mx);
        }
        op++;
    }
    cout << op << endl;
    cout << flush;
    return 0;
}