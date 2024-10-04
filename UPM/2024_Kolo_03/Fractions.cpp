#include "bits/stdc++.h"
#define ll long long
 
using namespace std;
 
const ll MOD = 1e9 + 7;
 
void test_case() {
    ll A, B;
    cin >> A >> B;
 
    ll L[2] = { 0, 1 };
    ll R[2] = { 1, 0 };
    ll M[2] = { 1, 1 };
    ll height = 0;
    vector<char> movement;
    while (true) {
        if (A * M[1] > B * M[0]) {
            L[0] = M[0];
            L[1] = M[1];
            movement.push_back('R');
        } else if (A * M[1] < B * M[0]) {
            R[0] = M[0];
            R[1] = M[1];
            movement.push_back('L');
        } else {
            break;
        }
 
        M[0] = L[0] + R[0];
        M[1] = L[1] + R[1];
        height++;
    }
 
    ll ans = 1;
    for (int i = 0; i < movement.size(); i++) {
        ans = (ans * 2) % MOD;
        if (movement[i] == 'R') ans = (ans + 1) % MOD;
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        test_case();
    }
    return 0;
}