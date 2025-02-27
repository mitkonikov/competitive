#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> split(string& s, char del) {
    int prev = 0;
    vector<string> res;
    s += del;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == del) {
            res.push_back(s.substr(prev, i - prev));
            prev = i + 1;
        }
    }
    return res;
};

int main() {
    int N, M;
    cin >> N >> M;
    string T;
    getline(cin, T);
    vector<string> ranks;
    ranks.reserve(3 * N);
    for (int i = 0; i < N; i++) {
        string S;
        getline(cin, S);
        ranks.push_back("pod" + S);
        ranks.push_back(S);
        ranks.push_back("nad" + S);
    }
    struct General {
        string name;
        int rank;
        int parent;
        int dist = 0;
        bool operator<(const General& other) const {
            if (rank == other.rank) {
                if (dist == other.dist) {
                    return parent < other.parent;
                }

                return dist < other.dist;
            }

            return rank > other.rank;
        }
    };
    vector<General> generals;
    generals.push_back(General{"supreme", (int)1e9, 0, 0});
    for (int i = 0; i < M; i++) {
        string S_input;
        getline(cin, S_input);
        auto splitted = split(S_input, ':');
        auto name = splitted[0];
        int rank = -1;
        int kin = -1;
        int ptr = splitted[1].size() - 1;
        while ((splitted[1][ptr] >= '0' && splitted[1][ptr] <= '9') || 
                (splitted[1][ptr] == '-')) ptr--;
        kin = stoi(splitted[1].substr(ptr + 1));
        string RANK = splitted[1].substr(0, ptr);
        for (int j = 0; j < ranks.size(); j++) {
            if (ranks[j] == RANK) rank = j;
        }
        generals.push_back({ name, rank, kin, 0 });
    }
    vector<vector<int>> rev(M + 1);
    for (int i = 1; i <= M; i++) {
        if (generals[i].parent == -1) generals[i].parent = 0;
        rev[generals[i].parent].push_back(i);
    }
    auto dfs = [&](auto&& self, int u) -> void {
        for (auto v : rev[u]) {
            generals[v].dist = generals[u].dist + 1;
            self(self, v);
        }
    };
    dfs(dfs, 0);
    sort(generals.begin(), generals.end());
    for (int i = 1; i < M; i++) {
        if (generals[i].rank == generals[i+1].rank && generals[i].dist == generals[i+1].dist) {
            cout << "ZARADI SLABEGA VREMENA PARADA ODPADE" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= M; i++) {
        cout << generals[i].name << endl;
    }
    return 0;
}