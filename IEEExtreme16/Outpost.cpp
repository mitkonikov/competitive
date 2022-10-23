// 
//  This is only a solution for 30% of the points
//

#include <bits/stdc++.h>
#define ll long long

#define MAXN 50005
#define K 18
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

template<typename T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

template<typename T>
struct RMQ_MAX {
	vector<vector<T>> jmp;
	RMQ_MAX(const vector<T>& V) : jmp(1, V) {
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
    int rows, cols, t;
    cin >> rows >> cols >> t;

    vector<vector<ll>> arr(rows, vector<ll>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    vector<RMQ<ll>> rmq_min;
    vector<RMQ_MAX<ll>> rmq_max;

    for (int i = 0; i < rows; i++) {
        rmq_min.emplace_back(arr[i]);
        rmq_max.emplace_back(arr[i]);
    }
    
    int best = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int L = 0, R = j;
            while (R - L > 1) {
                int mid = (R + L) / 2;
                ll mn = rmq_min[i].query(mid, j + 1);
                ll mx = rmq_max[i].query(mid, j + 1);
                if (mx - mn <= t) {
                    R = mid;
                } else {
                    L = mid + 1;
                }
            }

            best = max(best, abs(L - j) + 1);
        }
    }

    cout << best << endl;
    return 0;
}