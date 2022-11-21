// Task: https://mendo.mk/Task.do?id=914

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tree(n);
    for (int i = 0; i < n; i++) {
        int deg;
        cin >> deg;

        tree[i] = { deg, i };
    }

    sort(tree.rbegin(), tree.rend());

    int ptr = 1;
    bool imp = false;
    vector<pair<int, int>> solutions;
    for (int i = 0; i < n; i++) {
        for (int j = ptr; j < n && tree[i].first > 0; j++) {
            tree[i].first--;
            tree[j].first--;
            solutions.push_back({ tree[i].second, tree[j].second });
            ptr++;
        }

        if (tree[i].first != 0) {
            imp = true;
            break;
        }
    }

    if (imp) {
        cout << "PROBLEM" << endl;
        return 0;
    }

    for (int i = 0; i < solutions.size(); i++) {
        cout << solutions[i].first + 1 << " " << solutions[i].second + 1 << "\n";
    }

    cout << flush;

    return 0;
}