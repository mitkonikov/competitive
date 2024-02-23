#include "bits/stdc++.h"
#define ll long long
 
using namespace std;
 
int main() {
    ll N, C;
    cin >> N >> C;
    vector<ll> diff(N);
    ll D = 0;
    for (int i = 0; i < N; i++) {
        int d, s;
        cin >> d >> s;
        diff[i] = d - s;
        D += d;
    }
    ll R = D;
    sort(diff.rbegin(), diff.rend());
    int counter = 0;
    while (R > C) {
        R -= diff[counter];
        counter++;
        if (counter == N) {
            break;
        }
    }
    if (R > C) {
        cout << -1 << endl;
        return 0;
    }
    cout << counter << endl;
    return 0;
}