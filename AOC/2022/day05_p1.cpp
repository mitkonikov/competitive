#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    vector<stack<char>> stacks(m);
    for (int s = 0; s < m; s++) {
        for (int i = n - 1; i >= 0; i--) {
            if (mat[i][s] != 'x') {
                stacks[s].push(mat[i][s]);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int many, from, to;
        cin >> many >> from >> to;
        from--; to--;
        vector<int> a;
        for (int k = 0; k < many; k++) {
            a.push_back(stacks[from].top());
            stacks[from].pop();
        }
        for (int k = 0; k < many; k++) {
            stacks[to].push(a[k]);
        }
    }
    string ans = "";
    for (int i = 0; i < m; i++) {
        if (!stacks[i].empty()) ans += stacks[i].top();
    }
    cout << ans << endl;
    return 0;
}