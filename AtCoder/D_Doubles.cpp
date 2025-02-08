#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<map<int, int>> A(N);
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < C[i]; j++) {
            int a;
            cin >> a;
            A[i][a]++;
        }
    }
    double mx_same = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double p = 0.00;
            int ii = i;
            int jj = j;
            if (A[i].size() > A[j].size()) {
                swap(ii, jj);
            }
            for (auto [key, value] : A[ii]) {
                if (value == 0) continue;
                if (A[jj].find(key) == A[jj].end()) continue;
                double p1 = (double)value / C[ii];
                double p2 = (double)A[jj][key] / C[jj];
                p += p1 * p2;
            }
            mx_same = max(mx_same, p);
        }
    }
    cout << fixed << setprecision(16) << mx_same << endl;
    return 0;
}