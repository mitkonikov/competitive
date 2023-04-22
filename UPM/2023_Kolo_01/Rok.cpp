#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> tasks(N);
    for (int i = 0; i < N; i++) {
        int r, d;
        cin >> r >> d;
        tasks[i] = { r, d };
    }
    sort(tasks.begin(), tasks.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    ll ans = 0;
    ll time = 0;
    for (int i = 0; i < N; i++) {
        ll r = tasks[i].first;
        ll d = tasks[i].second;
        ans += (r - (time + d));
        time += d;
    }
    cout << ans << endl;
    return 0;
}