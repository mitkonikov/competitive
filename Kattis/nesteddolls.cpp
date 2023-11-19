#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)a.size())

using namespace std;

struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int v) {
		for (; pos < sz(s); pos |= pos + 1) s[pos] = max(s[pos], v);
	}
	int query(int pos) { // [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res = max(res, s[pos-1]);
		return res;
	}
};

struct FT2 {
	vector<vector<int>> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (vector<int>& v : ys) sort(all(v)), ft.emplace_back(sz(v));
	}
	int ind(int x, int y) {
		return (int)(lower_bound(all(ys[x]), y) - ys[x].begin());
    }
	void update(int x, int y, int v) {
		for (; x < sz(ys); x |= x + 1)
			ft[x].update(ind(x, y), v);
	}
	int query(int x, int y) {
		int s = 0;
		for (; x; x &= x - 1)
			s = max(s, ft[x-1].query(ind(x-1, y)));
		return s;
	}
};

void testCase() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    {
        vector<int> x(N), y(N);
        for (int i = 0; i < N; i++) {
            cin >> x[i] >> y[i];
            points[i] = { x[i], y[i] };
        }
        // Index compression
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        for (int i = 0; i < N; i++) {
            points[i].first = N - 1 - (lower_bound(all(x), points[i].first) - x.begin());
            points[i].second = (lower_bound(all(y), points[i].second) - y.begin());
        }
    }
    sort(points.begin(), points.end());

    FT2 fwt(N + 20);
    for (auto& [x, y]: points) {
        fwt.fakeUpdate(x, y);
    }
    fwt.init();

    int ans = 0;
    for (int i = 0; i < N; i++) {
        auto [x, y] = points[i];
        int q = fwt.query(x + 1, y + 1);
        fwt.update(x, y, q + 1);
        ans = max(ans, q + 1);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}