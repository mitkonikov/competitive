#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    vector<int> off(3);
    int L;
    for (int i = 0; i < 3; i++) cin >> off[i];
    cin >> L;
    vector<bool> visited(L + 10);
    fill(visited.begin() + L + 1, visited.end(), 1);
    vector<set<int>> free(L + 10);
    set<int> current_free;
    for (int j = 1; j <= 3; j++) current_free.insert(j);
    struct Problem {
        int c, l, r;
    };
    vector<Problem> ans;
    for (int i = 0; i <= L; i++) {
        for (auto el: free[i]) {
            if (el == 0) continue;
            current_free.insert(el);
        }
        for (int k = 0; k < 3; k++) {
            if (current_free.empty()) continue;
            if (off[k] > 0 && !visited[i+2+k]) {
                int take = *current_free.begin();
                current_free.erase(take);
                free[i + 2 + k].insert(take);
                ans.push_back({ take, i, i + 2 + k });
                visited[i + 2 + k] = true;
                off[k]--;
            }
        }
    }
    sort(ans.begin(), ans.end(), [&](Problem& a, Problem& b) {
        return (a.r < b.r);
    });
    cout << ans.size() << endl;
    for (auto el: ans) {
        cout << el.c << " " << el.l << " " << el.r << endl;
    }
    return 0;
}