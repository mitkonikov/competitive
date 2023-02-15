#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    bool pos = 0, neg = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x > 0) pos = true;
        if (x < 0) neg = true;
    }
    cout << pos + neg << endl;
}

int main() {
    freopen("hanya.in", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}