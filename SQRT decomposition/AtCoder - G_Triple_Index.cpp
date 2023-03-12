#include <bits/stdc++.h>
#define ll long long

using namespace std;

int magic = 400;

struct Query {
    int id;
    int l, r;

    bool operator<(const Query &rhs) const {
        if (l / magic == rhs.l / magic) return r < rhs.r;
        return (l / magic < rhs.l / magic);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<Query> queries(Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        queries[i] = { i, l, r };
    }
    sort(queries.begin(), queries.end());

    ll ans = 0;

    vector<int> frq(2e5 + 1000);

    auto diff = [](ll A, ll B) {
        ll DA = (A - 2) * (A - 1) * A / 6;
        ll DB = (B - 2) * (B - 1) * B / 6;
        return (DB - DA);
    };

    auto add = [&](int i) {
        ans += diff(frq[A[i]], frq[A[i]]+1);
        frq[A[i]]++;
    };

    auto remove = [&](int i) {
        ans += diff(frq[A[i]], frq[A[i]]-1);
        frq[A[i]]--;
    };

    vector<ll> ans_vec(Q);
    int cur_l = 0, cur_r = -1;
    for (int i = 0; i < Q; i++) {
        while (cur_l > queries[i].l) {
            cur_l--;
            add(cur_l);
        }

        while (cur_r < queries[i].r) {
            cur_r++;
            add(cur_r);
        }

        while (cur_l < queries[i].l) {
            remove(cur_l);
            cur_l++;
        }

        while (cur_r > queries[i].r) {
            remove(cur_r);
            cur_r--;
        }

        ans_vec[queries[i].id] = ans;
    }
    for (int i = 0; i < Q; i++) {
        cout << ans_vec[i] << endl;
    }
    return 0;
}