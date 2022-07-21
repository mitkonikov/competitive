#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;

struct SegmentTree {
    const static int pw = 1 << 19;
    const static ll def = -1L * 1e6 * 4 * 1e5 * 10;

    struct Node {
        ll mx = def;

        Node operator+(const Node other) {
            return {
                max(this->mx, other.mx)
            };
        }
    };

    vector<Node> seg;
    SegmentTree() {
        seg.resize(2 * pw);
    }

    void put(int p, Node v, int ind = 0, int l = 0, int r = pw) {
        if (r - l == 1) { seg[ind] = v; return; }
        int m = (l + r) / 2;
        if (p < m) put(p, v, ind * 2 + 1, l, m);
        else put(p, v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    Node ask(int p, int ind = 0, int l = 0, int r = pw) {
        if (p + 1 >= r) return seg[ind];
        if (p < l) return { };
        int m = (l + r) / 2;
        return ask(p, ind * 2 + 1, l, m) + ask(p, ind * 2 + 2, m, r);
    }
};

vector<long long> solve(int n, long long c, const vector<long long> &x) {
	SegmentTree g;
	SegmentTree s;
	
	vector<pair<long long, int>> order(n);
	for (int i = 0; i < n; i++) {
		order[i].first = x[i];
		order[i].second = i;
		g.put(i, { x[i] + c * (i+1) });
	}
	sort(order.begin(), order.end());
	vector<long long> rez(n);
	for (int i = 0; i < n; i++) {
		int index = order[i].second;
		long long greater = g.ask(index).mx - x[index] - c * (index+1);
		g.put(index, {g.def});
		s.put(index, {-x[index] + c * (index+1)});
		long long smaller = s.ask(index).mx + x[index] - c * (index+1);

		rez[index] = max({smaller, greater , 0LL});
	}

    return rez;
}

int main() {
    srand (time(NULL));

    int n;
    long long c;
    cin >> n >> c;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<long long> rez = solve(n, c, x);
    for (int i = 0; i < n; i++) {
        cout << rez[i] << " ";
    }
    cout << endl;

    return 0;
}