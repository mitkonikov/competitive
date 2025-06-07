#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> b(N + 1);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        b[i+1] = b[i] + (S[i] == '0' ? 1 : -1);
        sum += S[i] == '1';
    }
    int max_pref = 0, ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = min(ans, b[i] - max_pref);
        max_pref = max(max_pref, b[i]);
    }
    cout << sum + ans << endl;
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