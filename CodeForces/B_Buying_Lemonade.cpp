#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    
    ll more = 0;
    ll temp = K;
    for (int i = 0; i < N; i++) {
        ll mn = A[i] - (i ? A[i-1] : 0);
        if (mn == 0) {
            more++;
            continue;
        }
        ll right = (N - i) * mn;
        temp -= right;
        if (temp <= 0) {
            cout << K + more << endl;
            return;
        }
        more++;
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