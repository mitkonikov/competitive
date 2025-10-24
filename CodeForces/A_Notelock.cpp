#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int count = K - 1;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            if (count >= K - 1) {
                ans++;
                count = 0;
            } else {
                count = 0;
            }
        } else {
            count++;
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