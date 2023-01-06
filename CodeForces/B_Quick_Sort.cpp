#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> O(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        O[A[i]] = i;
    }
    int mx = -1;
    int ans = 0;
    bool moved = false;
    for (int i = 0; i < N; i++) {
        if (O[i] < mx) {
            ans++;
            mx = N;
        }
        mx = max(mx, O[i]);
    }
    int a = (ans / K) + (ans % K != 0);
    cout << a << endl;
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