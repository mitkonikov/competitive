#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

template<class T>
struct SparseTable {
	vector<vector<T>> jmp;
	SparseTable(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {
			jmp.emplace_back(V.size() - pw * 2 + 1);
			for (int j = 0; j < jmp[k].size(); j++)
				jmp[k][j] = gcd(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return gcd(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

void testCase() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> diff(N);
    for (int i = 1; i < N; i++) {
        diff[i] = abs(A[i] - A[i-1]);
    }
    SparseTable st(diff);
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--; R--;
        if (L == R) {
            cout << 0 << " ";
            continue;
        }
        int g = st.query(L + 1, R + 1);
        cout << g << " ";
    }
    cout << endl;
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