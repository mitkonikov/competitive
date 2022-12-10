#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    ll T;
    cin >> N >> T;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    ll sum = 0;
    for (int i = 0; i < N; i++) sum += a[i];
    ll L = T % sum;
    ll listen = 0;
    for (int i = 0; i < N; i++) {
        if (listen + a[i] > L) {
            cout << i + 1 << " " << L - listen << endl;
            return 0;
        }
        listen += a[i];
    }
    return 0;
}