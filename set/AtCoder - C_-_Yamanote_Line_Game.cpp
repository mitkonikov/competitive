#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= 2 * n + 1; i++) {
        s.insert(i);
    }

    cout << *s.begin() << endl;
    s.erase(*s.begin());
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        s.erase(k);
        cout << *s.begin() << endl;
        s.erase(*s.begin());
    }
    int t;
    cin >> t;
    return 0;
}