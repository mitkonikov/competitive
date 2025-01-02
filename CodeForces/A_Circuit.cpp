#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    int z = 0, o = 0;
    for (int i = 0; i < 2 * N; i++) {
        int x;
        cin >> x;
        if (x == 0) z++;
        else o++;
    }
    int mn = N - (o / 2) - (z / 2);
    int mx = min(o, z);
    cout << mn << " " << mx << endl;
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