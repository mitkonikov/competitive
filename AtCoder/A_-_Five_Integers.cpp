#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    set<int> s;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << (int)s.size() << endl;
    cout << flush;
    return 0;
}