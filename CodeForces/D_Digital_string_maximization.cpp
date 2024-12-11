#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string S;
    cin >> S;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        int cur = S[i] - '0';
        int mx_id = i;
        int mx = cur;
        for (int c = 1; i+c < N && (c - 1) < 9 - cur; c++) {
            int next = S[i+c] - '0';
            if (next - c > mx) {
                mx = next - c;
                mx_id = i + c;
            }
        }
        for (int c = mx_id; c > i; c--) {
            S[c]--;
            swap(S[c], S[c-1]);
        }
    }
    cout << S << endl;
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