#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<string>> v(2, vector<string>(N));
    vector<unordered_map<string, int>> where(2);
    for (int i = 0; i < N; i++) {
        cin >> v[0][i];
        cin >> v[1][i];
        where[0][v[0][i]] = i;
        where[1][v[1][i]] = i;
    }
    vector<vector<int>> visited(2, vector<int>(N));
    int id = 1;
    for (int rep = 0; rep < 2; rep++) {
        for (int i = 0; i < N; i++) {
            if (visited[rep][i]) continue;
            int t = i;
            visited[rep][t] = id;
            visited[rep^1][t] = id;
            int w = rep;
            auto it = where[w].find(v[w^1][t]);
            while (it != where[w].end()) {
                if (visited[w][it->second] == id) {
                    cout << "No" << endl;
                    return 0;
                }
                t = it->second;
                visited[w][t] = id;
                visited[w^1][t] = id;
                it = where[w].find(v[w^1][t]);
            }
            id++;
        }
    }
    cout << "Yes" << endl;
    return 0;
}