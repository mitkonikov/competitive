#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> frq(200);
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        frq[X]++;
    }
    if (N < 3) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i < 200; i++) {
        ans += frq[i] / 3;
    }
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