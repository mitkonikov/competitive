#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = INT_MAX;
    for (int i = '0'; i <= '9'; i++) {
        map<int, int> times;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 10; k++) {
                if (s[j][k] == i) {
                    times[k]++;
                    break;
                }
            }
        }

        int mx_times = 0;
        int mx = 0;
        for (auto p: times) {
            mx_times = max(mx_times, p.second);
            if (p.second > 0) mx = max(mx, p.first);
        }

        if (mx_times == 1) {
            ans = min(ans, mx);
        } else {
            int who = 0;
            for (auto p: times) {
                if (p.second == mx_times) who = max(who, p.first);
            }
            ans = min(ans, (mx_times - 1) * 10 + who);
        }
    }

    cout << ans << endl;
    return 0;
}