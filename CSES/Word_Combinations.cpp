#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Trie {
    map<int, Trie*> childs;
    bool end = 0;

    Trie() {}

    void add(string& s, int i) {
        if (i == -1) {
            end = true;
            return;
        }
        int dir = s[i] - 'a';
        if (childs.find(dir) == childs.end()) {
            childs[dir] = new Trie();
        }
        childs[dir]->add(s, i - 1);
    }

    void query(string& s, int i, std::function<void(int)> callback) {
        if (end) callback(i);
        if (i == -1) return;
        int dir = s[i] - 'a';
        if (childs.find(dir) == childs.end()) return;
        return childs[dir]->query(s, i - 1, callback);
    }
};

int main() {
    const int MOD = 1e9 + 7;
    string S;
    cin >> S;
    int N;
    cin >> N;
    int M = S.size();
    Trie* trie = new Trie();
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s.size() > M) continue;
        trie->add(s, s.size() - 1);
    }
    S = "@" + S; M++;
    vector<int> dp(M + 100);
    dp[0] = 1;
    for (int i = 1; i < M; i++) {
        trie->query(S, i, [&](int from) {
            if (from < 0) return;
            dp[i] = (dp[i] + dp[from]) % MOD;
        });
    }
    cout << dp[M - 1] << endl;
    return 0;
}