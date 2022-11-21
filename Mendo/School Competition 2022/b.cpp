#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int L, X;
    cin >> L >> X;
    int ans = 0;
    for (int i = 1; i <= L; i++) {
        if (i * 100 / L < X) {
            ans = max(ans, i);
        }
    }
    cout << ans << endl;
    return 0;
}