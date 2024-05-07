#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> s(N);
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        s[x-1] ^= 1;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) ans += s[i];
    cout << N - ans << endl;
    return 0;
}