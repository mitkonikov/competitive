#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, M;
    cin >> N >> M;
    vector<int> A(N * M);
    for (int i = 0; i < N * M; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll mn1 = A[0];
    ll mn2 = A[1];
    ll mx = A.back();
    ll ans = (N * M - 1) * mx;

    ll c1 = 0, c2 = 0;
    c1 -= (N - 1) * mn1;
    c1 -= (M - 1) * mn2;
    c1 -= ((N-1) * (M-1)) * min(mn1, mn2);
    
    c2 -= (N - 1) * mn2;
    c2 -= (M - 1) * mn1;
    c2 -= ((N-1) * (M-1)) * min(mn1, mn2);

    ll mx1 = A.rbegin()[0];
    ll mx2 = A.rbegin()[1];

    ll c3_1 = -(N * M - 1) * mn1;
    ll c3_2 = -(N * M - 1) * mn1;
    c3_1 += (N - 1) * mx1;
    c3_1 += (M - 1) * mx2;
    c3_1 += ((N-1) * (M-1)) * max(mx1, mx2);
    c3_2 += (N - 1) * mx2;
    c3_2 += (M - 1) * mx1;
    c3_2 += ((N-1) * (M-1)) * max(mx1, mx2);

    ans += max({ c1, c2 });
    ans = max({ ans, c3_1, c3_2 });
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