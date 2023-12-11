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
    vector<ll> ans(N);
    vector<pair<int, int>> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = { A[i], i };
    }
    sort(B.rbegin(), B.rend());
    ll sum = 0;
    ll running_sum = 0;
    ll running_sum_value = B.back().first;
    for (int i = 0; i < N; i++) {
        if (B[i].first != running_sum_value) {
            sum += running_sum;
            running_sum_value = B[i].first;
            running_sum = B[i].first;
        } else {
            running_sum += B[i].first;
        }
        
        ans[B[i].second] = sum;
    }
    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}