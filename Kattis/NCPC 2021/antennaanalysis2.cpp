#include <bits/stdc++.h>
using namespace std;
int n;
long long big = -1L * 1e6 * 4 * 1e5 * 10;
int pw = 1 << 19;
vector<long long> s(2 * pw, big);
vector<long long> g(2 * pw, big);
void put(vector<long long>& seg, int p, long long v, int ind = 0, int l = 0, int r = pw) {
	if (r - l == 1) { seg[ind] = v;return; }
	int m = (l + r) / 2;
	if (p < m) put(seg, p, v, ind * 2 + 1, l, m);
	else put(seg, p, v, ind * 2 + 2, m, r);
	seg[ind] = max(seg[ind * 2 + 1], seg[ind * 2 + 2]);
}
long long ask(vector<long long>& seg, int p, int ind = 0, int l = 0, int r = pw) {
	if (p + 1 >= r)return seg[ind];
	if (p < l)return big;
	int m = (l + r) / 2;
	return max(ask(seg, p, ind * 2 + 1, l, m), ask(seg, p, ind * 2 + 2, m, r));
}
void put_g(int p, int v) { put(g, p, v); }
void put_s(int p, int v) { put(s, p, v); }
long long get_g(int p) { return ask(g, p); }
long long get_s(int p) { return ask(s, p); }

vector<long long> solve(int n, long long c, const vector<long long> &x) {
	vector<pair<long long, int>> order(n);
	for (int i = 0; i < n; i++) {
		order[i].first = x[i];
		order[i].second = i;
		put_g(i, x[i] + c * (i+1));
	}
	sort(order.begin(), order.end());
    cout << "def: " << get_s(n) << endl;
	vector<long long> rez(n);
	for (int i = 0; i < n; i++) {
		int index = order[i].second;
		long long greater = get_g(index) - x[index] - c * (index+1);
		put_g(index, big);
        cout << "d: " << -x[index] + c * (index+1) << endl;
		put_s(index, -x[index] + c * (index+1));
		long long smaller = get_s(index) + x[index] - c * (index+1);

		rez[index] = max(smaller, greater);
        if (rez[index] > 0) cout << "rez: " << rez[index] << " and ";
        if (rez[index] > 0) cout << "smaller: " << get_s(index) << " " << "greater: " << greater << endl;
	}
    cout << endl;

    return rez;
}

int main() {
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

    n = 6;
    for (int i = 0; i < 1000; i++) {
        vector<long long> gen(n);
        for (int j = 0; j < n; j++) {
            gen[j] = rand() % 100;
        }

        long long c = rand() % 10000;

        vector<long long> ans = solve(n, c, gen);

        for (int check = 0; check < n; check++) {
            long long best = INT_MIN;
            int best_index = -1;
            for (int j = 0; j <= check; j++) {
                long long cur = abs(gen[check] - gen[j]) - c * abs(check - j);
                if (best < cur) {
                    best = cur;
                    best_index = j;
                }
            }

            if (best != ans[check]) {
                cout << "ERROR" << endl;
                cout << "check = " << check << endl;
                cout << "gen = ";
                for (int j = 0; j < n; j++) {
                    cout << gen[j] << " ";
                }
                cout << endl;
                cout << "c = " << c << endl;
                cout << "ans = ";
                for (int j = 0; j < n; j++) {
                    cout << ans[j] << " ";
                }
                cout << endl;
                cout << "best = " << best << endl;
                return 0;
            }
        }
    }

    cout << "PASSED" << endl;

	// for (int i = 0; i < n; i++)
	// 	cout << rez[i] << " ";

    return 0;
}