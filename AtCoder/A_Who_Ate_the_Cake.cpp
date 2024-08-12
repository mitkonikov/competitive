#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    vector<int> frq(3, 0);
    int a, b;
    cin >> a >> b;
    a--; b--;
    frq[a]++;
    frq[b]++;
    if (a == b) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (frq[i] == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}