#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct FenwickTree {
    vector<int> fwt;
    int LOGN = 0;

    FenwickTree(int n) {
        fwt.resize(n, 0);
        LOGN = log2(n) + 1;
    }

    void add(int ind, int val = 1) {
        for (ind++; ind < fwt.size(); ind += ind & -ind)
            fwt[ind] += val;
    }

    int get(int ind) {
        int s = 0;
        for (ind++; ind > 0; ind -= ind & -ind)
            s += fwt[ind];
        return s;
    }

    int lower_bound(int v) {
        v++;
        int sum = 0;
        int pos = 0;
        for (int i = LOGN; i >= 0; i--) {
            if (pos + (1 << i) < fwt.size() && sum + fwt[pos + (1 << i)] < v) {
                sum += fwt[pos + (1 << i)];
                pos += (1 << i);
            }
        }
        return pos - 1;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<vector<int>> B(N, vector<int>(N, 0));
    vector<int> comp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
            comp.push_back(B[i][j]);
        }
    }
    // index compression
    sort(comp.begin(), comp.end());
    auto getCompressed = [&](int a) {
        return lower_bound(comp.begin(), comp.end(), a) - comp.begin() + 1;
    };

    auto uncompress = [&](int a) { return comp[a]; };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = getCompressed(B[i][j]);
        }
    }

    FenwickTree fwt(N * N + 100);
    int ans = INT_MAX;
    auto updateAns = [&]() {
        ans = min(ans, comp[fwt.lower_bound((K * K) / 2)]);
    };

    for (int j = 0; j < K; j++) {
        for (int k = 0; k < K; k++) {
            // add A[i+j][k]
            fwt.add(B[j][k], 1);
        }
    }
    updateAns();

    for (int i = 0; i < N - K + 1; i++) {
        if (i % 2 == 0) {
            // shift to the right
            for (int k = 0; k + K < N; k++) {
                for (int j = 0; j < K; j++) {
                    fwt.add(B[i + j][k], -1);
                    fwt.add(B[i + j][k + K], 1);
                }
                updateAns();
            }

            if (i + K >= N) break;

            // shift down at the end
            for (int col = 0; col < K; col++) {
                fwt.add(B[i][N - 1 - col], -1);
                fwt.add(B[i + K][N - 1 - col], 1);
            }

            updateAns();
        } else {
            // shift to the left
            for (int k = N - 1; k - K >= 0; k--) {
                for (int j = 0; j < K; j++) {
                    fwt.add(B[i + j][k], -1);
                    fwt.add(B[i + j][k - K], 1);
                }
                updateAns();
            }

            if (i + K >= N) break;
            // shift down at the start
            for (int col = 0; col < K; col++) {
                fwt.add(B[i][col], -1);
                fwt.add(B[i + K][col], 1);
            }

            updateAns();
        }
    }
    cout << ans << endl;
    return 0;
}