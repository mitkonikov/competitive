#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    unsigned ll ans = 0;
    for (int i = 0; i < 64; i++) {
        int x;
        cin >> x;
        if (x) ans += (1ULL << i);
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}