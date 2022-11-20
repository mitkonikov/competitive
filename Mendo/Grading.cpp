// Task: https://mendo.mk/Task.do?id=137

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = INT_MAX;
    int time_ans = INT_MAX;
    for (ll i = 1; i <= n; i++) {
        ll time_it_took = (ll)k * ((i * (i - 1)) / 2) + (n / i + (n % i != 0));
        if (time_it_took < time_ans) {
            time_ans = time_it_took;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}