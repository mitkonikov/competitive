#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct StreamMedian {
    set<int> left, right;

    void add(int value) {
        if (value <= median()) left.insert(value);
        else right.insert(value);
        balance();
    }

    void remove(int value) {
        auto it = left.find(value);
        if (it != left.end()) {
            left.erase(it);
            balance();
            return;
        }
        it = right.find(value);
        if (it != right.end()) {
            right.erase(it);
            balance();
            return;
        }
    }

    void balance() {
        while (left.size() > right.size() + 1) {
            auto it = prev(left.end());
            int v = *it;
            left.erase(it);
            right.insert(v);
        }

        while (right.size() > left.size()) {
            auto it = right.begin();
            int v = *it;
            right.erase(it);
            left.insert(v);
        }
    }

    int median() {
        if (left.empty()) return 0;
        return *prev(left.end());
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    StreamMedian stream;
    int ans = INT_MAX;
    auto updateAns = [&]() {
        ans = min(ans, stream.median());
    };

    for (int j = 0; j < K; j++) {
        for (int k = 0; k < K; k++) {
            stream.add(A[j][k]);
        }
    }
    updateAns();

    for (int i = 0; i < N - K + 1; i++) {
        if (i % 2 == 0) {
            // shift to the right
            for (int k = 0; k + K < N; k++) {
                for (int j = 0; j < K; j++) {
                    stream.remove(A[i+j][k]);
                    stream.add(A[i+j][k+K]);
                }
                updateAns();
            }

            if (i + K >= N) break;

            // shift down at the end
            for (int col = 0; col < K; col++) {
                stream.remove(A[i][N-1-col]);
                stream.add(A[i+K][N-1-col]);
            }

            updateAns();
        } else {
            // shift to the left
            for (int k = N - 1; k - K >= 0; k--) {
                for (int j = 0; j < K; j++) {
                    stream.remove(A[i+j][k]);
                    stream.add(A[i+j][k-K]);
                }
                updateAns();
            }

            if (i + K >= N) break;
            // shift down at the start
            for (int col = 0; col < K; col++) {
                stream.remove(A[i][col]);
                stream.add(A[i+K][col]);
            }

            updateAns();
        }
    }
    cout << ans << endl;
    return 0;
}