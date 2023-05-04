#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    string S;
    cin >> S;
    auto z = z_function(S);
    vector<int> ans;
    for (int i = 0; i < S.size(); i++) {
        if (z[i] == S.size() - i) {
            ans.push_back(i);
        }
    }
    ans.push_back(S.size());
    sort(ans.begin(), ans.end());
    for (auto el: ans) {
        cout << el << " ";
    } cout << endl;
    return 0;
}