#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    vector<ll> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](ll a, ll b) {
        return A[a] < A[b];
    });

    vector<ll> pref(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) pref[i] = A[order[i]];
        else pref[i] = pref[i-1] + A[order[i]];
    }

    auto check = [](int i, ll pref) {
        if (i >= 0) return pref;
        return 0LL;
    };

    map<ll, ll> mp;
    ll rem = K - sum;
    for (int i = 0; i < N; i++) {
        ll me = order[i];
        if (i < N - 1 && A[order[i+1]] == A[me]) continue;
        ll L = -1, R = rem + 1;
        bool ever_won = false;
        ll ever_won_on = 0;
        while (R - L > 1) {
            ll mid = (R - L) / 2 + L;
            // me gains mid amount of votes
            ll leftover = rem - mid;

            if (leftover < 0) {
                L = mid;
                continue;
            }

            // how many are surely winning
            ll new_votes = A[me] + mid;
            auto it = upper_bound(order.begin() + i + 1, order.end(), -new_votes, [&](ll a, ll b) {
                ll ai = (a < 0 ? -a : A[a]);
                ll bi = (b < 0 ? -b : A[b]);
                return ai < bi;
            });

            ll ID = (it == order.end() ? N : it - order.begin());
            ll surely_winning = N - ID;

            // how many can we still get to win, greedy?
            ll L1 = 0, R1 = ID;
            while (R1 - L1 > 1) {
                ll MID = (L1 + R1) / 2;

                ll total_area = (ll)(ID - MID) * (new_votes + 1);
                ll already_taken = check(ID-1, pref[ID-1]) - check(MID - 1, pref[MID - 1]);
                ll new_area = total_area - already_taken;
                if (MID <= i) new_area -= mid + 1;
                if (new_area <= leftover) {
                    R1 = MID;
                } else {
                    L1 = MID;
                }
            }

            ll can_win = ID - R1 - (R1 <= i ? 1 : 0);
            if ((can_win + surely_winning) >= M) {
                L = mid;
            } else {
                ever_won = true;
                ever_won_on = mid;
                R = mid;
            }
        }

        mp[A[me]] = (ever_won ? ever_won_on : -1);
    }
    for (int i = 0; i < N; i++) {
        cout << mp[A[i]] << " ";
    }
    cout << endl;
    return 0;
}