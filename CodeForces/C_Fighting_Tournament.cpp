#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct query {
    int id, round, ans_id;
    
    void read() {
        cin >> id >> round;
        id--;
    }

    bool operator<(const query& other) const {
        if (round == other.round) {
            return (id < other.id);
        }

        return (round < other.round);
    }
};

void testCase() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }

    vector<query> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].read();
        queries[i].ans_id = i;
    }

    sort(queries.begin(), queries.end());

    vector<int> stage1(n);
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back(a[i]);
    }

    int round = 1, pi = 0;
    vector<int> ans(q);
    while (dq.front() != n-1 && pi < q) {
        int one = dq.front(); dq.pop_front();
        int two = dq.front(); dq.pop_front();

        if (one < two) swap(one, two);
        
        stage1[one]++;
        while (pi < q && round == queries[pi].round) {
            ans[queries[pi].ans_id] = stage1[a[queries[pi].id]];
            pi++;
        }

        dq.push_front(one);
        dq.push_back(two);
        round++;
    }

    round--;

    for (;pi < q; pi++) {
        int cur_round = queries[pi].round;
        stage1[n-1] += (cur_round - round);
        round = cur_round;
        ans[queries[pi].ans_id] = stage1[a[queries[pi].id]];
    }

    for (auto el: ans) {
        cout << el << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}