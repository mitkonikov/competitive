#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<pair<ll, ll>> ans;
vector<pair<ll, ll>> smallest;
int sz = INT_MAX;

void dfs(ll L, ll R) {
    ll T = L;
    int k = 0;
    while (T > 0 && (T % 2 == 0)) {
        T >>= 1;
        k++;
    }
    for (int K = (L == 0 ? 61 : k); K >= 0; K--) {
        T = L >> K;
        ll l = (1LL << K) * T;
        ll r = (1LL << K) * (T + 1);
        if (r <= R) {
            ans.push_back({ l, r });
            if (ans.size() >= sz) {
                continue;
                ans.pop_back();
            }
            if (r == R) {
                if (ans.size() < sz) {
                    sz = ans.size();
                    smallest = ans;
                    continue;
                }
            }
            dfs(r, R);
            ans.pop_back();
        }
    }
}

int main() {
    ll L, R;
    cin >> L >> R;
    dfs(L, R);
    cout << sz << endl;
    for (auto [l, r]: smallest) {
        cout << l << " " << r << endl;
    }
    return 0;
}