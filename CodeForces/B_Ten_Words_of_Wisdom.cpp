#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    int mx_q = 0;
    int ans = -1;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (b > mx_q && a <= 10) {
            mx_q = b;
            ans = i + 1;
        }
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