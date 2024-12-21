#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int ans = 0;
    for (int interval = 1; interval <= N; interval++) {
        for (int start = 0; start < N; start++) {
            int count = 1;
            for (int k = start + interval; k < N; k += interval) {
                if (A[k] != A[k-interval]) {
                    ans = max(ans, count);
                    count = 1;
                } else {
                    count++;
                }
            }
            ans = max(ans, count);
        }
    }
    cout << ans << endl;
    return 0;
}