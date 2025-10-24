#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int top = 0;
    int bot = 0;
    int both = 0;
    for (int i = 0; i < K; i++) {
        if (S[i] == '0') top++;
        else if (S[i] == '1') bot++;
        else both++;
    }
    string ans = string(N, '+');
    for (int i = 0; i < top; i++) {
        ans[i] = '-';
    }
    for (int i = N - 1; i > N - 1 - bot; i--) {
        ans[i] = '-';
    }
    for (int i = top; i < top + both && i < N; i++) {
        if (ans[i] == '+') ans[i] = '?';
    }
    for (int i = N - 1 - bot; i >= 0 && i > N - 1 - bot - both; i--) {
        if (ans[i] == '+') ans[i] = '?';
    }
    if (both == N - top - bot) {
        cout << string(N, '-') << endl;
    } else {
        cout << ans << endl;
    }
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