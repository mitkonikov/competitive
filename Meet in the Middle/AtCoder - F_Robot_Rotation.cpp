#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

optional<pair<int, int>> solve(vector<int>& A, int X) {
    int N = A.size();
    
    // Calculate the sums of the both halfs
    int sumFirstHalf = 0;
    int sumSecondHalf = 0;
    for (int i = 0; i < (N / 2); i++) sumFirstHalf += A[i];
    for (int i = (N / 2); i < N; i++) sumSecondHalf += A[i];

    // Compute the one half
    map<int, int> pos;
    for (int mask = 0; mask < (1 << (N / 2)); mask++) {
        int sum = 0;
        for (int i = 0; i < (N / 2); i++) {
            if ((1 << i) & mask) {
                sum += A[i];
            }
        }

        // We have picked all of sum to be positive
        // and the sumFirstHalf - sum to be negative
        int possible = sum - (sumFirstHalf - sum);
        pos[possible] = mask;
    }

    // Go through the other half
    for (int mask = 0; mask < (1 << (N - (N / 2))); mask++) {
        int sum = 0;
        for (int i = 0; i < (N - (N / 2)); i++) {
            if ((1 << i) & mask) {
                sum += A[N / 2 + i];
            }
        }

        int possible = sum - (sumSecondHalf - sum);
        auto it = pos.find(X - possible);
        if (it != pos.end()) {
            // this mask + it's mask is the solution
            int other_mask = it->second;
            return make_pair(other_mask, mask);
        }
    }

    return std::nullopt;
}

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> AY, AX;
    for (int i = 0; i < N; i += 2) AY.push_back(A[i]);
    for (int i = 1; i < N; i += 2) AX.push_back(A[i]);
    string ans(N, '.');
    auto movesY = solve(AY, Y);
    if (!movesY.has_value()) { cout << "No" << endl; return 0; }
    auto movesX = solve(AX, X);
    if (!movesX.has_value()) { cout << "No" << endl; return 0; }
    
    // Reconstruction
    auto mY = movesY.value();
    auto mX = movesX.value();

    auto getMove = [](vector<int>& A, pair<int, int> masks, int index) {
        if (index < A.size() / 2) {
            return ((1 << index) & masks.first) > 0;
        }

        return ((1 << (index - (A.size() / 2))) & masks.second) > 0;
    };

    int px = 0, py = 0;
    int dir = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) { // move Y
            auto nextMove = getMove(AY, mY, i / 2);
            if (dir == 0) {
                ans[i] = (nextMove ? 'L' : 'R');
                dir = (nextMove ? 3 : 1);
            } else if (dir == 2) {
                ans[i] = (nextMove ? 'R' : 'L');
                dir = (nextMove ? 3 : 1);
            }
        } else { // move X
            auto nextMove = getMove(AX, mX, i / 2);
            if (dir == 1) {
                ans[i] = (nextMove ? 'L' : 'R');
                dir = (nextMove ? 0 : 2);
            } else if (dir == 3) {
                ans[i] = (nextMove ? 'R' : 'L');
                dir = (nextMove ? 0 : 2);
            }
        }
    }

    cout << "Yes" << endl;
    cout << ans << endl;
    return 0;
}