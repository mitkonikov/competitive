#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    auto ask = [&](const vector<int>& ids) {
        cout << "? ";
        for (auto el: ids) cout << el + 1 << " ";
        cout << endl;
        int p;
        cin >> p;
        return p;
    };

    if (K == 1) {
        vector<int> color(N);
        for (int i = 0; i < N; i++) {
            color[i] = ask({ i });
        }
        cout << "! ";
        for (auto c: color) cout << c << " ";
        cout << endl;
        return 0;
    }

    int sum_xor = 0;
    vector<int> ans(N);
    for (int i = 0; i < K + 1; i++) {
        vector<int> ids;
        for (int j = 0; j < K + 1; j++) {
            if (i != j) ids.push_back(j);
        }
        ans[i] = ask(ids);
        sum_xor ^= ans[i];
    }
    for (int i = 0; i < K + 1; i++) ans[i] ^= sum_xor;

    vector<int> ids(K);
    int new_sum = 0;
    for (int i = 0; i < K - 1; i++) {
        ids[i] = i;
        new_sum ^= ans[i];
    }

    for (int i = K + 1; i < N; i++) {
        ids.back() = i;
        int p = ask(ids);
        ans[i] = p ^ new_sum;
    }

    cout << "! ";
    for (auto el: ans) cout << el << " ";
    cout << endl;
    return 0;
}
