#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
T ternSearch(T a, T b, function<T(T)> f) {
	assert(a <= b);
	while (b - a >= 1e-6) {
		T mid = (b - a) / 3;
		if (f(a + mid) < f(a + mid * 2)) b = a + mid * 2;
		else a = a + mid;
	}
	return a;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = { a, b };
    }

    int best_index_got = INT_MAX;
    vector<pair<double, int>> tmp(n);
    double a = ternSearch<double>(0, 1, [&](double eval) {
        for (int i = 0; i < n; i++) {
            tmp[i] = { eval * v[i].first + (1 - eval) * v[i].second, i };
        }

        sort(tmp.rbegin(), tmp.rend());
        int index = 0;
        for (int i = 0; i < n; i++) if (tmp[i].second == 0) {
            index = i;
            break;
        }

        best_index_got = min(best_index_got, index);

        return index;
    });

    if (best_index_got != 0) {
        cout << "Slabe metrike" << endl;
    } else {
        cout << fixed << setprecision(17) << a << " " << (1 - a) << endl;
    }

    cout << flush;
    return 0;
}