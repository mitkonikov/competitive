#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<int> bits;
    for (int i = 0; i < 62; i++) {
        if (n & (1LL << i)) {
            bits.push_back(i);
        }
    }
    for (int i = 0; i < (1LL << (int)bits.size()); i++) {
        ll cur_ans = 0;
        for (int j = 0; j < (int)bits.size(); j++) {
            if (i & (1LL << j)) {
                cur_ans |= (1LL << bits[j]);
            }
        }
        cout << cur_ans << endl;
    }
    cout << flush;
    return 0;
}