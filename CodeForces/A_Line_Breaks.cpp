#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    int count = 0;
    int ans = 0;
    bool ok = true;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (ok && count + S.size() <= M) {
            count += S.size();
            ans++;
        } else {
            ok = false;
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