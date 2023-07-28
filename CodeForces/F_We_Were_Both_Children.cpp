#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> mp(N + 10);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] <= N) mp[A[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (j * j == i) sum += mp[j];
                else sum += mp[j] + mp[i/j];
            }
        }
        ans = max(ans, sum);
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