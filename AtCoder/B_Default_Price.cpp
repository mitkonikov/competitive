#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> eat(N);
    for (int i = 0; i < N; i++) {
        cin >> eat[i];
    }
    vector<string> colors(M);
    for (int i = 0; i < M; i++) {
        cin >> colors[i];
    }
    map<string, int> mp;
    int p0 = 0;
    for (int i = 0; i < M + 1; i++) {
        if (i) {
            int x;
            cin >> x;
            mp[colors[i-1]] = x;
        } else {
            cin >> p0;
        }
    }
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        auto it = mp.find(eat[i]);
        if (it == mp.end()) sum += p0;
        else sum += it->second;
    }
    cout << sum << endl;
    return 0;
}