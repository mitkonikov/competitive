#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<ll> sum(2);
    vector<ll> count(2);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        count[i%2]++;
        sum[i%2] += A[i];
    }
    cout << ((sum[0] % count[0] == 0 
            && sum[1] % count[1] == 0 
            && sum[0] / count[0] == sum[1] / count[1]) ? "YES" : "NO") << endl;
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