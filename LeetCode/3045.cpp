#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

struct Trie {
    vector<Trie*> childs;
    bool end;
    int hits;

    Trie() {
        childs.resize(26, NULL);
        end = false;
        hits = 0;
    }

    void add(const string& s, int id, vector<int>& z) {
        if (id > 0 && z[s.size()-id] >= id) hits++;
        if (id >= s.size()) return;
        if (childs[s[id] - 'a'] == NULL) {
            childs[s[id] - 'a'] = new Trie();
        }
        childs[s[id] - 'a']->add(s, id + 1, z);
    }

    void remove(const string& s, int id, vector<int>& z) {
        if (id > 0 && z[s.size()-id] >= id) hits--;
        if (id >= s.size()) return;
        childs[s[id] - 'a']->remove(s, id + 1, z);
    }

    int query(const string& s, int id) {
        if (id >= s.size()) return hits;
        if (childs[s[id] - 'a'] == NULL) return 0;
        return childs[s[id] - 'a']->query(s, id + 1);
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        int N = words.size();
        vector<vector<int>> precomp(N);
        for (int i = 0; i < N; i++) {
            precomp[i] = z_function(words[i]);
            precomp[i][0] = words[i].size();
        }
        long long ans = 0;
        Trie* trie = new Trie();
        for (int i = 0; i < N; i++) {
            trie->add(words[i], 0, precomp[i]);
        }
        for (int i = 0; i < N; i++) {
            trie->remove(words[i], 0, precomp[i]);
            ans += trie->query(words[i], 0);
        }
        return ans;
    }
};