#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline vector<int> mergeA(const vector<int>& a, const vector<int>& b) {
    vector<int> res(26, 0);
    for (int i = 0; i < 26; i++) res[i] = a[i] + b[i];
    return res;
}

struct SegmentTree {
    const static int pw = 1 << 18;
    const static ll def = 0;
    int N = pw;

    struct Node {
        char value = def;
        char pref = def;
        char suff = def;
        bool sorted = true;
        bool empty = false;
        vector<int> freq;
        Node(char v) {
            value = v;
            pref = v;
            suff = v;
            freq.resize(26, 0);
            if (value != '@') freq[value - 'a']++;
        }

        Node operator+(const Node &other) {
            if (other.empty) {
                return *this;
            }
            if (empty) {
                return other;
            }
            
            bool s = (sorted && other.sorted && (suff <= other.pref));
            Node res = Node('@');
            res.pref = pref;
            res.suff = other.suff;
            res.sorted = s;
            res.empty = false;
            res.freq = mergeA(freq, other.freq);            
            return res;
        }

        static Node identity() {
            Node res('@');
            res.empty = true;
            return res;
        }

        void print() {
            cout << "value: " << value << endl;
            cout << "pref: " << pref << endl;
            cout << "suff: " << suff << endl;
            cout << "s: " << sorted << endl;
            cout << "e: " << empty << endl;
            for (int i = 0; i < 26; i++) {
                cout << freq[i] << " ";
            }
            cout << endl;
        }
    };

    vector<Node> seg;
    SegmentTree(int N) { this->N = N; seg.resize(2 * pw, Node('@')); }

    void put(int i, Node v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind] = v; return; }
        int m = (l + r) / 2;
        if (i < m) put(i, v, ind * 2 + 1, l, m);
        else put(i, v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
    void build(string& S, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            SegmentTree::Node v(S[l]);
            seg[ind] = v;
            return;
        }
        int m = (l + r) / 2;
        build(S, ind * 2 + 1, l, m);
        build(S, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
    Node ask(int i, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (i + 1 >= r) return seg[ind];
        if (i < l) return Node::identity();
        int m = (l + r) / 2;
        return ask(i, ind * 2 + 1, l, m) + ask(i, ind * 2 + 2, m, r);
    }
    // result in [b,e) of node that covers [l,r)
    Node askLR(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return Node::identity();
        if (l>=b && r<=e) return seg[ind];
        int m = (l + r) / 2;
        return askLR(b, e, ind * 2 + 1, l, m) + askLR(b, e, ind * 2 + 2, m, r);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    string S;
    cin >> S;
    SegmentTree tree(N);
    tree.build(S);
    vector<int> frq(26, 0);
    for (int i = 0; i < N; i++) {
        frq[S[i] - 'a']++;
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            char c;
            cin >> x >> c;
            x--;
            frq[S[x] - 'a']--;
            S[x] = c;
            frq[S[x] - 'a']++;
            SegmentTree::Node v(S[x]);
            tree.put(x, v);
        } else {
            int L, R;
            cin >> L >> R;
            L--;
            auto res = tree.askLR(L, R); // [L, R]
            if (!res.sorted) {
                cout << "No" << endl;
                continue;
            }
            bool ok = true;
            for (int i = res.pref - 'a'; i <= res.suff - 'a'; i++) {
                if (res.freq[i] > frq[i]) {
                    ok = false;
                    break;
                }
                if (res.freq[i] < frq[i] && (i+'a'!=res.suff && i+'a'!=res.pref)) {
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "Yes" : "No") << endl;
        }
    }
    return 0;
}