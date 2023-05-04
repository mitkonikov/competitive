#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Trie {
    vector<Trie*> childs;

    Trie() {
        childs.resize(2, nullptr);
    }

    void add(int n, int bit = 29) {
        if (bit == -1) return;
        int dir = (n & (1 << bit)) > 0;
        if (childs[dir] == nullptr) {
            childs[dir] = new Trie();
        }
        childs[dir]->add(n, bit - 1);
    }

    int query(int n, int bit = 29, int construct = 0) {
        if (bit == -1) return construct;
        int dir = (n & (1 << bit)) > 0;
        if (childs[dir ^ 1] != nullptr) {
            return childs[dir ^ 1]->query(n, bit - 1, construct | (1 << bit));
        }
        return childs[dir]->query(n, bit - 1, construct ^ (n & (1 << bit)) ^ (dir << bit));
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    Trie* trie = new Trie();
    int ans = 0;
    int pref = 0;
    trie->add(0);
    for (int i = 0; i < N; i++) {
        pref ^= A[i];
        ans = max(ans, trie->query(pref));
        trie->add(pref);
    }
    cout << ans << endl;
    return 0;
}