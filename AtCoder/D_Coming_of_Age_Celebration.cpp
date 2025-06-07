#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> remove(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll rolling = 0;
    for (int i = 0; i < N; i++) {
        rolling -= remove[i];
        A[i] += rolling;
        ll take = N - i - 1;
        ll act = min(take, A[i]);
        A[i] -= act;
        rolling += 1;
        remove[i + act + 1] += 1;
    }
    for (auto el : A) cout << el << " ";
    cout << endl;
    return 0;
}