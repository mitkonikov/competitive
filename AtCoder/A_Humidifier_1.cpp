#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    ll sum = 0;
    int prev = 0;
    for (int i = 0; i < N; i++) {
        int T, V;
        cin >> T >> V;
        int taken = T - (i == 0 ? T : prev);
        sum = max(0LL, sum - taken);
        sum += V;
        prev = T;
    }
    cout << sum << endl;
    return 0;
}