#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    double mn = LLONG_MIN, mx = LLONG_MAX;
    for (int i = 1; i <= N; i++) {
        int A, B;
        cin >> A >> B;
        mn = max(mn, (double)i / B);
        mx = min(mx, (double)i / A);
    }
    if (mn > mx) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(16) << mn << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << (i + 1) << ": ";
        testCase();
    }

    cout << flush;
    return 0;
}