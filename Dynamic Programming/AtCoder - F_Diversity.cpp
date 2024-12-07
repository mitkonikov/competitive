#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

ll ans = 0;
void update(ll& a, ll b) {
    if (b > a) a = b;
    if (a > ans) ans = a;
}

int main() {
    int N, X, K;
    cin >> N >> X >> K;
    struct Item {
        ll price, util, color;
        void read() {
            cin >> price >> util >> color;
            color--;
        }
        bool operator<(const Item& other) const {
            return color < other.color;
        }
    };
    vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        items[i].read();
    }
    sort(items.begin(), items.end());
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(N, vector<ll>(X + 10, 0)));
    if (items[0].price <= X) {
        update(dp[1][0][items[0].price], items[0].util + K);
    }
    for (int i = 1; i < N; i++) {
        if (i > 0 && items[i].color != items[i-1].color) {
            for (int j = 0; j <= X; j++) {
                update(dp[0][i-1][j], dp[1][i-1][j]);
                dp[1][i-1][j] = 0;
            }
        }
        for (int j = 0; j <= X; j++) {
            update(dp[0][i][j], dp[0][i-1][j]);
            update(dp[1][i][j], dp[1][i-1][j]);
            if (items[i].price + j <= X) {
                update(dp[1][i][items[i].price+j], dp[0][i-1][j] + items[i].util + K);
                update(dp[1][i][items[i].price+j], dp[1][i-1][j] + items[i].util);
            }
        }
    }
    cout << ans << endl;
    return 0;
}