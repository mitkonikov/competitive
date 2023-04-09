#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

#define MAX (int)(5e6 + 1000)

int phi[MAX];
bool pr[MAX];

void totient(){
  for(int i = 0; i < MAX; i++){
    phi[i] = i;
    pr[i] = true;
  }
  for(int i = 2; i < MAX; i++)
    if(pr[i]){
      for(int j = i; j < MAX; j+=i){
        pr[j] = false;
        phi[j] = phi[j] - (phi[j] / i);
      }
      pr[i] = true;
    }
}

struct dsu {
    vector<int> parent;

    dsu(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find_set(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find_set(parent[a]);
    }

    void merge(int a, int b) {
        int x = find_set(a), y = find_set(b);
        if (x == y) return;
        parent[x] = y;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }
};

struct SegmentTree {
    const static int pw = 1 << 19;
    const static int def = -1;
    int N = pw;

    struct Node {
        int value = def;
        int size = 0;
        int count = 0;
        Node operator+(const Node &other) {
            if (value == def) {
                return other;
            }
            if (other.value == def) {
                return *this;
            }
            int v1 = value;
            int v2 = other.value;
            int c1 = 0;
            int c2 = 0;
            while (v1 != v2) {
                if (v1 > v2) {
                    v1 = phi[v1];
                    c1++;
                } else {
                    v2 = phi[v2];
                    c2++;
                }
            }
            int fc = c1 * size + count + c2 * other.size + other.count;
            int fs = size + other.size;
            int value = v1;
            return { value, fs, fc };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) { this->N = N; seg.resize(2 * pw); }

    void put(int i, Node v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind] = v; return; }
        int m = (l + r) / 2;
        if (i < m) put(i, v, ind * 2 + 1, l, m);
        else put(i, v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
    
    void build(const vector<int>& v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind] = { v[l], 1, 0 }; return; }
        int m = (l + r) / 2;
        build(v, ind * 2 + 1, l, m);
        build(v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    Node ask(int i, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (i + 1 >= r) return seg[ind];
        if (i < l) return { };
        int m = (l + r) / 2;
        return ask(i, ind * 2 + 1, l, m) + ask(i, ind * 2 + 2, m, r);
    }
    // result in [b,e) of node that covers [l,r)
    Node askLR(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return { };
        if (l>=b && r<=e) return seg[ind];
        int m = (l + r) / 2;
        return askLR(b, e, ind * 2 + 1, l, m) + askLR(b, e, ind * 2 + 2, m, r);
    }
};

int main() {
    totient();

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    dsu DSU(N + 10);
    SegmentTree st(N);
    st.build(A);

    for (int q = 0; q < Q; q++) {
        int t, l, r;
        cin >> t >> l >> r;
        l--; r--;
        if (t == 1) {
            // brute force with DSU jumping
            for (int i = l; i <= r; i++) {
                i = DSU.find_set(i);
                if (i > r) break;
                A[i] = phi[A[i]];
                st.put(i, { A[i], 1, 0 });
                if (A[i] == 1) DSU.merge(i, i + 1);
            }
        } else {
            // segment tree
            auto node = st.askLR(l, r + 1);
            cout << node.count << endl;
        }
    }
    return 0;
}