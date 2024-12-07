#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, M, R, C;
    cin >> N >> M >> R >> C;
    ll down = (N - R);
    cout << down * M + down * (M - 1) + (M - C) << endl;
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