#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    ll N;
    cin >> S >> N;
    ll best = 0;
    for (int i = S.size() - 1; i >= 0; i--) {
        best |= (S[i] == '1' ? (1LL << (int)(S.size()-1-i)) : 0);
    }
    if (best > N) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '?' && (best | (1LL << (int)(S.size()-1-i))) <= N) {
            best |= ((1LL << (int)(S.size()-1-i)));
        }
    }
    cout << best << endl;
    return 0;
}