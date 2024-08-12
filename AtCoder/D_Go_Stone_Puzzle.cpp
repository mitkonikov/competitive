#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

unordered_map<string, int> dist;

int main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    string start = S + "..";
    dist[start] = 0;
    queue<string> q;
    q.push(start);
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        int pos = 0;
        for (int i = 0; i < cur.size() - 1; i++) {
            if (cur[i] == '.' && cur[i+1] == '.') {
                pos = i;
            }
        }
        for (int i = 0; i < cur.size() - 1; i++) {
            if (cur[i] != '.' && cur[i+1] != '.') {
                string next = cur;
                next[pos] = cur[i];
                next[pos+1] = cur[i+1];
                next[i] = '.';
                next[i+1] = '.';
                if (dist.find(next) == dist.end()) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
    string end = T + "..";
    if (dist.find(end) == dist.end()) {
        cout << -1 << endl;
    } else {
        cout << dist[end] << endl;
    }
    return 0;
}