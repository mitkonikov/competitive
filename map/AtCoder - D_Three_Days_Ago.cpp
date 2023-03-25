#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    map<int, int> frq;
    int current = 0;
    frq[0] = 1;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int c = S[i] - '0';
        current ^= (1 << c);
        ans += frq[current];
        frq[current]++;
    }
    cout << ans << endl;
    return 0;
}