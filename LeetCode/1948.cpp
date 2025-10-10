#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct Trie {
    map<string, Trie*> childs;
    Trie* parent = nullptr;
    string up = "";
    bool stop = 0;
    bool deleted = 0;
    H hash = 1;

    Trie(Trie* p, string u) {
        parent = p;
        up = u;
    }

    void Add(int i, const vector<string>& folders) {
        if (i == folders.size()) {
            stop = true;
        } else {
            auto it = childs.find(folders[i]);
            if (it == childs.end()) {
                childs[folders[i]] = new Trie(this, folders[i]);
            }
            childs[folders[i]]->Add(i + 1, folders);
        }
    }

    void Query(vector<vector<string>>& q, vector<string>& cur) {
        if (deleted) return;
        if (stop) q.push_back(cur);

        for (auto& [str, t] : childs) {
            cur.push_back(str);
            t->Query(q, cur);
            cur.pop_back();
        }
    }

    static H Hash(const string& str) {
        H r = 1;
        for (auto& s : str) r = r * C + s;
        return r;
    }

    void ComputeHash(map<H, vector<Trie*>>& hashes) {
        for (auto& [str, t] : childs) {
            t->ComputeHash(hashes);
            hash = hash * C + t->hash * Hash(str);
        }
        if (childs.size()) hashes[hash].push_back(this);
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie* root = new Trie(nullptr, "");
        const int F = paths.size();
        for (int i = 0; i < F; i++) {
            root->Add(0, paths[i]);
        }
        map<H, vector<Trie*>> hashes;
        root->ComputeHash(hashes);
        for (auto& [h, nodes] : hashes) {
            if (nodes.size() > 1) {
                for (auto& node : nodes) {
                    node->deleted = true;
                }
            }
        }
        vector<vector<string>> result;
        vector<string> acc;
        root->Query(result, acc);
        return result;
    }
};