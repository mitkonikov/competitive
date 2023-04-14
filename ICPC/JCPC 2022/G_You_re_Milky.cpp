#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int inf = 1e9 + 100;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, val = inf, mmin = inf;
    Node(int lo, int hi) : lo(lo), hi(hi) {}
    int query(int L, int R) {
        if (R <= lo || hi <= L) return inf;
        if (L <= lo && hi <= R) return val;
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    void umin(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mmin = min(mmin, x);
            val = min(val, x);
        } else {
            push(), l->umin(L, R, x), r->umin(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mmin != inf)
            l->umin(lo, hi, mmin), r->umin(lo, hi, mmin), mmin = inf;
    }
    ~Node() {
        if (l) {
            delete l;
            delete r;
        }
    }
};

void testCase() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    Node* min_time_tree = new Node(0, inf);
    Node* max_time_tree = new Node(0, inf);
    int last = 0;
    for (int i = 0; i < N; i++) {
        int l = last;
        int r = A[i];
        if (l > r) swap(l, r);
        min_time_tree->umin(l, r + 1, i);
        last = A[i];
    }
    last = A[N - 1];
    for (int i = N - 2; i >= -1; i--) {
        int l = last;
        int r = (i == -1 ? 0 : A[i]);
        if (l > r) swap(l, r);
        max_time_tree->umin(l, r + 1, (N - i - 1));
        if (i >= 0) last = A[i];
    }

    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        int first = min_time_tree->query(L, L + 1);
        int last = max_time_tree->query(R, R + 1);
        if (first == inf || last == inf) {
            cout << "No" << endl;
            continue;
        }
        if (L == R) {
            cout << "Yes" << endl;
            continue;
        }
        if (first == N - last) {
            int S = (first - 1 >= 0 ? A[first - 1] : 0);
            if (S < A[first]) {
                cout << (L <= R ? "Yes" : "No") << endl;
            } else {
                cout << (L >= R ? "Yes" : "No") << endl;
            }
        } else {
            cout << ((first <= N - last) ? "Yes" : "No") << endl;
        }
    }

    delete min_time_tree;
    delete max_time_tree;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // freopen("milk.in", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}