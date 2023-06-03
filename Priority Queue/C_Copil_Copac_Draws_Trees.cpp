#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<vector<int>> edges(N - 1);
    vector<vector<int>> where(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = { u, v };
        where[u].push_back(i);
        where[v].push_back(i);
    }
    priority_queue<int, vector<int>, greater<int>> back;
    vector<int> front;
    vector<bool> visited(N);
    for (int i = 0; i < N; i++) {
        if (edges[i][0] == 0 || edges[i][1] == 0) {
            back.push(i);
            break;
        }
    }
    int routes = 0;
    while (!back.empty()) {
        while (!back.empty()) {
            auto id = back.top();
            back.pop();
            
            for (int i = 0; i < 2; i++) {
                int u = edges[id][i];
                if (visited[u]) continue;
                for (auto w: where[u]) {
                    if (w > id) {
                        back.push(w);
                    } else if (w < id) {
                        front.push_back(w);
                    }
                }
                visited[u] = true;
            }
        }
        for (auto el: front) {
            back.push(el);
        }
        front.clear();
        routes++;
    }
    cout << routes << endl;
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