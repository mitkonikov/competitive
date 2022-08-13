#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int n, m;

void dfs(int ind, int last, vector<int>& print) {
    if (print.size() == n) {
        for (auto el: print) {
            cout << el << " ";
        } cout << endl;
        return;
    }

    for (int start = last+1; start <= m; start++) {
        print.push_back(start);
        dfs(ind+1, start, print);
        print.pop_back();
    }
}

int main() {
    cin >> n >> m;
    vector<int> print = {};
    dfs(0, 0, print);
    cout << flush;
    return 0;
}