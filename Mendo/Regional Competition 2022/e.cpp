#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;

    int p = 0;
    int tmp = n;
    while (tmp > 0) {
        tmp /= 2;
        p++;
    }

    p--;

    ll ans = 0;

    int level = p;
    int per_level = 1;
    int passed = 0;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) ans += x;

        ans = ans + (ll)level * x;
        ans -= x;

        passed++;
        if (prev + passed == per_level) {
            per_level *= 2;
            prev += passed;
            passed = 0;
            level--;
        }
    }

    cout << ans << endl;
    return 0;
}