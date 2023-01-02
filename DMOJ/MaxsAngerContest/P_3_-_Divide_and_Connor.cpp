#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> dfs(vector<int>& a, int l, int r) {
    if (l >= r) {
        return { a[l] };
    }

    vector<int> result;
    int m1 = l + (r - l) / 3;
    int m2 = l + (r - l) / 3 * 2;
    vector<int> r1 = dfs(a, l, m1);
    vector<int> r2 = dfs(a, m1 + 1, m2 + 1);
    vector<int> r3 = dfs(a, m2 + 2, r);
    
    for (auto el: r3) result.push_back(el);
    for (auto el: r1) result.push_back(el);
    for (auto el: r2) result.push_back(el);
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    auto ans = dfs(a, 0, N-1);
    for (auto el: ans) {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}