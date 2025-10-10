#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& s) {
    vector<string> result;
    const int N = s.size();
    string cur = "";
    for (int i = 1; i < N; i++) {
        if (s[i] == '/') {
            result.push_back(cur);
            cur = "";
        } else {
            cur += s[i];
        }
    }
    if (!cur.empty()) result.push_back(cur);
    return result;
}

struct Trie {
    map<string, Trie*> childs;
    bool stop = 0;

    Trie() {}

    void Add(int i, const vector<string>& folders) {
        if (i == folders.size()) {
            stop = true;
        } else {
            auto it = childs.find(folders[i]);
            if (it == childs.end()) {
                childs[folders[i]] = new Trie();
            }
            childs[folders[i]]->Add(i + 1, folders);
        }
    }

    void Query(vector<string>& q, string cur = "") {
        if (stop) {
            q.push_back(cur);
            return;
        }

        for (auto& [str, t] : childs) {
            t->Query(q, cur + "/" + str);
        }
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* root = new Trie();
        const int N = folder.size();
        for (int i = 0; i < N; i++) {
            auto dir = split(folder[i]);
            root->Add(0, dir);
        }
        vector<string> result;
        root->Query(result);
        return result;
    }
};