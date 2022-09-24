#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    s = "0" + s;

    ll cost = 0;
    vector<bool> visited(n + 1);
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        while (tmp < s.size() && s[tmp] == '0') {
            if (!visited[tmp]) cost += i;
            visited[tmp] = true;
            tmp += i;
        }
    }

    cout << cost << endl;
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