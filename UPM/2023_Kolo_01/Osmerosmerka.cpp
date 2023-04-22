#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
struct Aho {
    vector<vector<int>> g;
    vector<int> f;
    vector<int> out;
    string text;
    vector<string> dict;
    vector<string> mat;
    vector<vector<bool>> del;
    int N, M; // size of dict
 
    void prebuild(int N) {
        this->N = N;
        g.resize(10, vector<int>(26, -1));
        f.resize(10, -1);
        out.resize(10, 0);
    }
 
    void build() {
        int nodes = 1;
 
        for (int i = 0; i < N; i++) {
            string& s = dict[i];
            int cur = 0;
            
            for (int j = 0; j < s.size(); j++) {
                if (g[cur][s[j] - 'A'] == -1) {
                    g[cur][s[j] - 'A'] = nodes++;
                    g.push_back(vector<int>(26, -1));
                    f.push_back(-1);
                    out.push_back(0);
                }
                cur = g[cur][s[j] - 'A'];
            }
            out[cur] = s.size();
        }
 
        for (int ch = 0; ch < 26; ch++) {
            if (g[0][ch] == -1) {
                g[0][ch] = 0;
            }
        }
 
        queue<int> q;
        for (int ch = 0; ch < 26; ch++) {
            if (g[0][ch] != 0) {
                f[g[0][ch]] = 0;
                q.push(g[0][ch]);
            }
        }
 
        while (!q.empty()) {
            int state = q.front(); q.pop();
 
            for (int ch = 0; ch < 26; ch++) {
                if (g[state][ch] == -1) continue;
 
                int fail = f[state];
                while(g[fail][ch] == -1) {
                    fail = f[fail];
                }
 
                f[g[state][ch]] = g[fail][ch];
                out[g[state][ch]] = max(out[g[state][ch]], out[g[fail][ch]]);
 
                q.push(g[state][ch]);
            }
        }
    }
 
    void search(vector<pair<int, int>>& put) {
        int state = 0;
        vector<pair<int, int>> intervals;
        for (int i = 0; i < text.size(); i++) {
            char c = text[i];
            if (c == '@') {
                state = 0;
                {
                    sort(intervals.begin(), intervals.end());
                    for (int i = 0; i < intervals.size(); i++) {
                        int t = i;
                        while (t < intervals.size() && intervals[t].first <= intervals[i].second) {
                            intervals[i].second = max(intervals[i].second, intervals[t].second);
                            t++;
                        }
                        for (int j = intervals[i].first; j <= intervals[i].second; j++) {
                            int x = put[j].first;
                            int y = put[j].second;
                            del[x][y] = true;
                        }
                        i = t - 1;
                    }
 
                    intervals.clear();
                }
                continue;
            }
            while (g[state][c - 'A'] == -1) {
                state = f[state];
            }
            state = g[state][c - 'A'];
            
            if (out[state] > 0) intervals.push_back({ i - out[state] + 1, i });
        }
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, D;
    cin >> N >> M >> D;
    Aho AHO;
    AHO.mat.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> AHO.mat[i];
    }
    AHO.dict.resize(D);
    for (int i = 0; i < D; i++) {
        cin >> AHO.dict[i];
    }
    string S = "";
    vector<pair<int, int>> put;
    // LEFT TO RIGHT
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            S += AHO.mat[i][j];
            put.push_back({ i, j });
        }
        S += "@";
        put.push_back({ -1, -1 });
    }
    // RIGHT TO LEFT
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            S += AHO.mat[i][M-j-1];
            put.push_back({ i, M-j-1 });
        }
        S += "@";
        put.push_back({ -1, -1 });
    }
    // TOP TO BOTTOM
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            S += AHO.mat[i][j];
            put.push_back({ i, j });
        }
        S += "@";
        put.push_back({ -1, -1 });
    }
    // BOTTOM TO TOP
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            S += AHO.mat[N-i-1][j];
            put.push_back({ N-i-1, j });
        }
        S += "@";
        put.push_back({ -1, -1 });
    }
    // MAIN DIAG
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; i + j < N && j < M; j++) {
            S += AHO.mat[i+j][j];
            put.push_back({ i + j, j });
        }
        S += "@";
        put.push_back({ -1, -1 });
    }
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N && j + i < M; i++) {
            S += AHO.mat[i][j+i];
            put.push_back({ i, j + i });
        }
        S += "@";
        put.push_back({ -1, -1 });
    }
 
    // MAIN DIAG REVERSE
    for (int i = N - 1; i >= 0; i--) {
        string t;
        vector<pair<int, int>> tp;
        for (int j = 0; i + j < N && j < M; j++) {
            t += AHO.mat[i+j][j];
            tp.push_back({ i + j, j });
        }
        reverse(t.begin(), t.end());
        reverse(tp.begin(), tp.end());
 
        S += t;
        for (auto el: tp) put.push_back(el);
        S += "@";
        put.push_back({ -1, -1 });
    }
    for (int j = 0; j < M; j++) {
        string t;
        vector<pair<int, int>> tp;
        for (int i = 0; i < N && j + i < M; i++) {
            t += AHO.mat[i][j+i];
            tp.push_back({ i, j + i });
        }
        reverse(t.begin(), t.end());
        reverse(tp.begin(), tp.end());
 
        S += t;
        for (auto el: tp) put.push_back(el);
        S += "@";
        put.push_back({ -1, -1 });
    }
 
    // OTHER DIAG
    for (int i = 0; i < N; i++) {
        for (int j = 0; i - j >= 0 && j < M; j++) {
            S += AHO.mat[i-j][j];
            put.push_back({ i - j, j });
        }
        S += "@";
        put.push_back({ -1, -1 });
    }
    for (int j = 0; j < M; j++) {
        for (int i = 0; N-1-i>=0&&j+i<M; i++) {
            S += AHO.mat[N-1-i][j+i];
            put.push_back({ N-1-i, j + i });
        }
        S += "@";
        put.push_back({ -1, -1 });
    }
 
 
    // OTHER DIAG REVERSE
    for (int i = 0; i < N; i++) {
        string t;
        vector<pair<int, int>> tp;
        for (int j = 0; i - j >= 0 && j < M; j++) {
            t += AHO.mat[i-j][j];
            tp.push_back({ i - j, j });
        }
        reverse(t.begin(), t.end());
        reverse(tp.begin(), tp.end());
        
        S += t;
        for (auto el: tp) put.push_back(el);
        S += "@";
        put.push_back({ -1, -1 });
    }
    for (int j = 0; j < M; j++) {
        string t;
        vector<pair<int, int>> tp;
        for (int i = 0; N-1-i>=0&&j+i<M; i++) {
            t += AHO.mat[N-1-i][j+i];
            tp.push_back({ N-1-i, j + i });
        }
        reverse(t.begin(), t.end());
        reverse(tp.begin(), tp.end());
        S += t;
        for (auto el: tp) put.push_back(el);
        S += "@";
        put.push_back({ -1, -1 });
    }
 
    AHO.text = S;
    AHO.prebuild(D);
    AHO.build();
    AHO.del.resize(N, vector<bool>(M, 0));
    AHO.search(put);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!AHO.del[i][j]) cout << AHO.mat[i][j];
        }
    }
    cout << endl;
    return 0;
}