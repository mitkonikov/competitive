#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> frq;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        frq[x]++;
    }
    int ans = 0;
    for (auto el: frq) {
        ans += el.second / 2;
    }
    cout << ans << endl;
    return 0;
}