#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("dotak.in");
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k % 2)
            cout << ((n % 2) ? "Omda" : "Teemo") << endl;
        else {
            n %= k + 1;
            if (n <= 1) cout << ((n % 2) ? "Omda" : "Teemo") << endl;
            else cout << (((n + 1) % 2) ? "Omda" : "Teemo") << endl;
        }
    }
}