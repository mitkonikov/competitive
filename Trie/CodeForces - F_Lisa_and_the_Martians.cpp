#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Trie {
    Trie* c[2] = { nullptr, nullptr };
    vector<int> frq;
    int count = 0;

    Trie() {}
    ~Trie() {
        if (c[0] != nullptr) delete c[0];
        if (c[1] != nullptr) delete c[1];
    }

    void insert(int x, int i, int bit) {
        if (bit == -1) {
            frq.push_back(i);
            count = frq.size();
            return;
        }

        int d = ((x & (1 << bit)) > 0);
        if (c[d] == nullptr) {
            c[d] = new Trie();
        }
        c[d]->insert(x, i, bit - 1);
        merge();
    }

    pair<int, int> query(int a, int i, int bit, int x = 0) {
        if (bit == -1) {
            for (int j: frq) if (j != i) return { j, x };
            return { -1, -1 };
        }

        int d = ((a & (1 << bit)) > 0);
        if (c[d] == nullptr || c[d]->count == 0) {
            return c[d^1]->query(a, i, bit - 1, x);
        }
        
        return c[d]->query(a, i, bit - 1, x ^ (d == 0 ? (1 << bit) : 0));
    }

    void merge() {
        count = 0;
        if (c[0] != nullptr) count += c[0]->count;
        if (c[1] != nullptr) count += c[1]->count;
    }

    void remove(int x, int bit) {
        if (bit == -1) {
            count--;
            return;
        }

        int d = ((x & (1 << bit)) > 0);
        c[d]->remove(x, bit - 1);
        merge();
    }

    void restore(int x, int bit) {
        if (bit == -1) {
            count++;
            return;
        }

        int d = ((x & (1 << bit)) > 0);
        c[d]->restore(x, bit - 1);
        merge();
    }
};

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    Trie* trie = new Trie();
    for (int i = 0; i < N; i++) {
        trie->insert(A[i], i, K - 1);
    }

    int ans = -1;
    int I = -1, J = -1, X = -1;
    for (int i = 0; i < N; i++) {
        trie->remove(A[i], K - 1);
        auto [j, x] = trie->query(A[i], i, K - 1);
        if (((A[i] ^ x) & (A[j] ^ x)) > ans) {
            ans = (A[i] ^ x) & (A[j] ^ x);
            I = i;
            J = j;
            X = x;
        }
        trie->restore(A[i], K - 1);
    }

    cout << I + 1 << " " << J + 1 << " " << X << endl;

    delete trie;
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