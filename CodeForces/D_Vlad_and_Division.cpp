#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (mp[((1 << 31) - 1) ^ A[i]]) {
            mp[((1 << 31) - 1) ^ A[i]]--;
        } else {
            mp[A[i]]++;
            ans++;
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