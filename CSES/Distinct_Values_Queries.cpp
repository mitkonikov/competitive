#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int magic = 300;

struct Query {
    int id;
    int l, r;

    void read(int i) {
        cin >> l >> r;
        l--; r--;
        id = i;
    }

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
        queries[i].read(i);
    }
    sort(queries.begin(), queries.end());

    // index compression
    int maxElement = INT_MIN;
    vector<int> comp(A);
    sort(comp.begin(), comp.end());
    for (int i = 0; i < N; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin();
        if (A[i] > maxElement) maxElement = A[i];
    }

    vector<int> frq(maxElement + 10);
    int ans = 0;
    
    auto add = [&](int i) {
        frq[A[i]]++;
        if (frq[A[i]] == 1) ans++;
    };

    auto remove = [&](int i) {
        frq[A[i]]--;
        if (frq[A[i]] == 0) ans--;
    };

    vector<int> ans_vec(Q);
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

    for (auto el: ans_vec) {
        cout << el << endl;
    }

    return 0;
}