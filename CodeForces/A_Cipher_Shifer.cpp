#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    char c = S[0];
    string ans = "";
    ans += c;
    for (int i = 1; i < N; i++) {
        if (S[i] == c) {
            if (i + 1 < N) {
                c = S[i+1];
                ans += c;
                i++;
            }
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