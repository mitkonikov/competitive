#include <bits/stdc++.h>
#define ll long long

using namespace std;

#define sz(a) ((int)a.size())
#define rep(i,s,e) for (int i = (s); i < (e); i++)
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    RMQ rmq(A);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int sx, sy, ex, ey, k;
        cin >> sx >> sy >> ex >> ey >> k;
        sy--; ey--;
        sx = N - sx;
        ex = N - ex;
        if (sy > ey) swap(sy, ey);
        int h = rmq.query(sy, ey + 1);
        if (sx % k < (N - h) && sx % k == ex % k && sy % k == ey % k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}