// LeetCode Task: https://leetcode.com/problems/word-break

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
    vector<Node> nodes;
    bool ends = false;

    void add(const string& s, int i) {
        if (i >= s.size()) {
            ends = true;
            return;
        }

        if (nodes.empty()) {
            nodes.resize(26, {});
        }

        nodes[s[i] - 'a'].add(s, i + 1);
    }

    void go(const string& s, int start, int i, vector<bool>& dp) {
        if (ends && start + i < dp.size()) dp[start+i] = true;
        if (i >= s.size()) return;
        if (nodes.empty()) return;
        nodes[s[i] - 'a'].go(s, start, i + 1, dp);
    }
};

bool wordBreak(string s, vector<string>& wordDict) {
    Node* trie = new Node();
    for (int i = 0; i < wordDict.size(); i++) {
        trie->add(wordDict[i], 0);
    }
    int n = s.size();
    vector<bool> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i]) trie->go(s.substr(i), i, 0, dp);
    }
    return dp[n];
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    cout << (wordBreak(s, d) ? "true" : "false") << endl;
    return 0;
}