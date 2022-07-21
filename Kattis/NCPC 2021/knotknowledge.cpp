#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }

    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;

        a.erase(y);
    }

    cout << *a.begin() << endl;

    return 0;
}