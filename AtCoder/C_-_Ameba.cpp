#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ans;
    ans.reserve(2 * n + 2);
    ans.push_back(-1);
    ans.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        int gen = ans[x];
        ans.push_back(gen + 1);
        ans.push_back(gen + 1);
    }

    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    cout << flush;
    return 0;
}