#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

void testCase() {
    int n;
    cin >> n;

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    // 1 2 3 4 5 6 7
    // 2 1 4 3 6 5 7
    // 1 3 2 5 4 7 6

    if (n % 2 == 1) {
        for (int i = 1; i < n-1; i += 2) {
            swap(ans[i], ans[i+1]);
        }
    } else {
        for (int i = 0; i < n-1; i += 2) {
            swap(ans[i], ans[i+1]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    } cout << endl;
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