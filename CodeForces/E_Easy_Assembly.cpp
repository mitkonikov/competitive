#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n);
    vector<int> all;
    map<pair<int, int>, int> pr;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vec[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            all.push_back(vec[i][j]);
            if (j) pr[make_pair(vec[i][j], vec[i][j - 1])]++;
        }
    }
    sort(all.begin(), all.end());
    for (int i = 1; i < all.size(); i++) {
        pr[make_pair(all[i], all[i - 1])]--;
    }
    int c = 0, d = 0;
    map<pair<int, int>, int>::iterator it;
    for (it = pr.begin(); it != pr.end(); it++) {
        int a = it->second;
        if (a > 0) c += a;
        else d -= a;
    }
    cout << c << " " << d << endl;
}