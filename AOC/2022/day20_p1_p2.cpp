#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<ll> r(N);
    for (ll i = 0; i < N; i++) {
        cin >> r[i];
        r[i] *= 811589153;
    }

    vector<pair<ll, ll>> b(r.size());
    for (ll i = 0; i < N; i++) {
        b[i] = { i, r[i] };
    }
    for (int rep = 0; rep < 10; rep++) {
        for (ll i = 0; i < N; i++) {
            vector<pair<ll, ll>> new_b; // { index, value }
            ll rm_id = -1;
            for (ll j = 0; j < N; j++) {
                if (b[j].first == i) {
                    rm_id = j;
                    continue;
                }
                new_b.push_back(b[j]);
            }
            ll new_position = (rm_id + r[i] + 8115891530000LL * (N - 1)) % (N - 1);
            ll where = rm_id;
            ll new_id = new_position;
            new_b.insert(new_b.begin() + new_id, { i, r[i] });
            b.swap(new_b);
        }
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        if (b[i].second == 0) {
            ans += (b[(i+1000)%N].second + b[(i+2000)%N].second + b[(i+3000)%N].second);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}