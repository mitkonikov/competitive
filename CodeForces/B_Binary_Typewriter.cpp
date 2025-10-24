#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    char b = '0';
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == b) {
            ans++;
            continue;
        } else {
            ans += 2;
            b = S[i];
        }
    }
    if (N >= 2) {
        int save = 0;
        vector<int> ones(N);
        for (int i = N - 1; i >= 0; i--) {
            ones[i] = S[i] == '1';
            if (i < N - 1) ones[i] = max(ones[i], ones[i+1]);
        }
        for (int i = 0; i < N - 1; i++) {
            if (S[i] == '1' && S[i+1] == '0') {
                save = max(save, (ones[i+1] ? 2 : 1));
            }
        }
        ans -= save;
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