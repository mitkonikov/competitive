// Task: https://mendo.mk/Task.do?id=112

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    set<pair<int, int>> s;

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;

        s.insert({ u, v });
    }

    int count = 0;

    for (auto item: s) {
        if (!s.count({ item.second, item.first })) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}