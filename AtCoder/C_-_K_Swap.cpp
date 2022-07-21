#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> arrays(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        for (int j = 0; i + (j * k) < n; j++) {
            visited[i + (j * k)] = true;
            arrays[i].push_back(a[i + (j * k)]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (arrays[i].empty()) continue;
        sort(arrays[i].begin(), arrays[i].end());
    }
    fill(visited.begin(), visited.end(), false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        for (int j = 0; j < arrays[i].size(); j++) {
            a[i + (j * k)] = arrays[i][j];
            visited[i + (j * k)] = true;
        }
    }
    cout << (is_sorted(a.begin(), a.end()) ? "Yes" : "No") << endl;
    return 0;
}