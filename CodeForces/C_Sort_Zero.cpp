#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n), init(n);
    vector<int> last_acc(n + 100, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        init[i] = a[i];
        last_acc[a[i]] = max(last_acc[a[i]], i);
    }

    vector<bool> visited(n + 100, false);
    int ans = 0;

    int first_zero = -1;
    int last_zero = -1;

    int mx = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] > mx) {
            last_zero = max(last_zero, i);
            while (true) {
                int new_last_zero = -1;
                for (int j = first_zero + 1; j <= last_zero; j++) {
                    new_last_zero = max(new_last_zero, last_acc[a[j]]);
                    a[j] = 0;
                }

                first_zero = last_zero;
                if (new_last_zero > last_zero) {
                    last_zero = new_last_zero;
                } else {
                    break;
                }
            }

            mx = 0;
        }

        mx = min(mx, a[i]);
    }

    vector<bool> changed(n+100, false);
    for (int i = 0; i < n; i++) {
        if (a[i] != init[i]) {
            changed[init[i]] = true;
        }
    }

    for (int i = 0; i < changed.size(); i++) if (changed[i]) ans++;

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}