#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    bool ok = true;
    vector<pair<int, int>> swaps;
    swaps.reserve(n * n);
    for (int i = 0; i < n; i++) {
        int min_id = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] <= a[min_id] && b[j] <= b[min_id]) {
                min_id = j;
            }
        }

        if (i == min_id) continue;
        swap(a[i], a[min_id]);
        swap(b[i], b[min_id]);
        swaps.push_back({ i, min_id });
    }

    ok &= is_sorted(a.begin(), a.end());
    ok &= is_sorted(b.begin(), b.end());
    if (!ok) {
        cout << -1 << endl;
    } else {
        if (swaps.empty()) {
            cout << 0 << endl;
            return;
        }

        cout << swaps.size() << endl;
        for (int i = 0; i < swaps.size(); i++) {
            cout << swaps[i].first + 1 << " " << swaps[i].second + 1 << endl;
        }
    }
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