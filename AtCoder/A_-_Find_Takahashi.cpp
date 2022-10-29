#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int best = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > best) {
            best = x;
            ans = i;
        }
    }
    cout << ans + 1 << endl;
    cout << flush;
    return 0;
}