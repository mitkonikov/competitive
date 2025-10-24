#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    ll offset = 0;
    vector<int> A(N);
    iota(A.begin(), A.end(), 1);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            A[(offset+p)%N] = x;
        } else if (t == 2) {
            int p;
            cin >> p;
            p--;
            cout << A[(offset+p)%N] << endl;
        } else {
            int k;
            cin >> k;
            offset = (offset + k) % N;
        }
    }
    return 0;
}