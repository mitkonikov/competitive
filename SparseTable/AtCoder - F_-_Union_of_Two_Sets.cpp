#include <bits/stdc++.h>
#define ll long long
#define sz(a) (a).size()

using namespace std;

struct RMQ {
    vector<vector<int>> jmp;
    vector<pair<int, int>> intervals;
	RMQ(int N) {
        jmp.emplace_back(N);
        for (int i = 0; i < N; i++) {
            intervals.push_back({ i, i });
            jmp[0][i] = i;
        }
		for (int pw = 1, k = 1; pw * 2 <= N; pw *= 2, ++k) {
			jmp.emplace_back(N - pw * 2 + 1);
			for (int j = 0; j < sz(jmp[k]); j++) {
                int i1 = jmp[k - 1][j];
                int i2 = jmp[k - 1][j+pw];
                int L = min(intervals[i1].first, intervals[i2].first);
                int R = max(intervals[i1].second, intervals[i2].second);
                intervals.push_back({ L, R });
                jmp[k][j] = intervals.size() - 1;
            }
		}
	}
	void query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		cout << jmp[dep][a] + 1 << " " << jmp[dep][b - (1 << dep)] + 1 << endl;
	}
    void print() {
        cout << intervals.size() << endl;
        for (int i = 0; i < intervals.size(); i++) {
            cout << intervals[i].first + 1 << " " << intervals[i].second + 1 << endl;
        }
    }
};

int main() {
    int N;
    cin >> N;
    RMQ rmq(N);
    rmq.print();
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--;
        rmq.query(L, R);
    }
    return 0;
}