#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<bool> up(N), down(N);
    for (int i = 1; i < N - 1; i++) {
        up[i] = A[i-1] < A[i] && A[i] > A[i+1];
        down[i] = A[i-1] > A[i] && A[i] < A[i+1];
    }
    vector<int> next_down(N), prev_down(N), next_up(N);
    prev_down[0] = 0;
    next_down[N-1] = N - 1;
    next_up[N-1] = N - 1;
    for (int i = 1; i < N; i++) {
        prev_down[i] = prev_down[i-1];
        if (down[i]) prev_down[i] = i;
    }
    for (int i = N - 2; i >= 0; i--) {
        next_down[i] = next_down[i+1];
        next_up[i] = next_up[i+1];
        if (down[i]) next_down[i] = i;
        if (up[i]) next_up[i] = i;
    }
    ll ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if (up[i]) {
            ll left = i - prev_down[i-1];
            if (next_down[i+1] + 1 < N) {
                ll right = next_up[next_down[i+1] + 1] - next_down[i+1];
                ans += left * right;
            }
        }
    }
    cout << ans << endl;
    return 0;
}