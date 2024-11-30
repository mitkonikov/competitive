#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;
    int current = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            current = 0;
        } else {
            current++;
        }

        if (current == M) {
            ans++;
            i += K - 1;
            current = 0;
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