#include <bits/stdc++.h>
#define ll long long
#define ui unsigned int

using namespace std;

int dfs(int bit, vector<int> all) {
    if (bit == -1) return 0;
    vector<int> S, T;
    for (int i = 0; i < all.size(); i++) {
        if (all[i] & (1 << bit)) S.push_back(all[i]);
        else T.push_back(all[i]);
    }
    if (S.size() == 0) return dfs(bit - 1, T);
    if (T.size() == 0) return dfs(bit - 1, S);
    return min(dfs(bit - 1, S), dfs(bit - 1, T)) | (1 << bit);
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cout << dfs(29, a) << endl;
    return 0;
}