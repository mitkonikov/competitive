#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, k;
    cin >> n >> k;

    if (k % 2 == 1) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i += 2) {
            cout << i << " " << i+1 << endl;
        }
        return;
    }

    vector<bool> visited(n+1, false);
    vector<pair<int, int>> made;
    made.reserve(n);
    int count = 0;
    for (int i = 4; i <= n; i += 4) {
        made.push_back({0,i});
        visited[i] = true;
        count++;
    }

    for (int i = 1; i <= n; i++) {
        if ((i + k) % 4 == 0) {
            made.push_back({ i, 0 });
            visited[i] = true;
        }
    }

    int pi = 1;
    for (int i = 0; i < made.size(); i++) {
        while (pi < visited.size() && visited[pi]) pi++;
        if (made[i].first == 0) {
            made[i].first = pi;
        } else {
            made[i].second = pi;
        }
        visited[pi] = true;
    }

    bool ok = true;
    for (int i = 0; i < n && ok; i++) if (!visited[i+1]) ok = false;
    for (int i = 0; i < made.size() && ok; i++) {
        if ((((ll)made[i].first + k) * made[i].second) % 4 != 0) ok = false; 
    }

    if (ok) {
        cout << "YES" << endl;
        for (auto el: made) {
            cout << el.first << " " << el.second << endl;
        }
    } else {
        cout << "NO" << endl;
    }
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