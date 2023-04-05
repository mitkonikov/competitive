#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    ll X;
    cin >> N >> X;
    map<ll, int> mp;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) mp[A[i] - X]++;
    for (int i = 0; i < N; i++) {
        if (mp[A[i]]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}