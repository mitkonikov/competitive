#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    auto valid = [&](int x, int y) {
        return (x >= 1 && x <= N && y >= 1 && y <= M);
    };
    cout << "? 1 1" << endl;
    int A;
    cin >> A;
    if (A == 0) {
        cout << "! 1 1" << endl;
        return;
    }
    cout << "? " << N << " " << M << endl;
    int B;
    cin >> B;
    if (B == 0) {
        cout << "! " << N << " " << M << endl;
        return;
    }
    B = (N - 1 + M - 1 - B);
    cout << "? " << N << " 1" << endl;
    int C;
    cin >> C;
    if (C == 0) {
        cout << "! " << N << " 1" << endl;
        return;
    }
    vector<pair<int, int>> cand;
    {
        int Y = (A + N - C + 2) / 2;
        int X = A - (Y-1) + 1;
        cand.push_back({ Y, X });
    }
    {
        int Y = (B + N - C + 2) / 2;
        int X = B - (Y-1) + 1;
        cand.push_back({ Y, X });
    }
    if (A == B) {
        auto [X, Y] = *cand.begin();
        cout << "! " << X << " " << Y << endl;
    } else {
        auto [X, Y] = *cand.begin();
        if (!valid(X, Y)) {
            assert(cand.size() >= 2);
            cout << "! " << cand[1].first << " " << cand[1].second << endl;
            return;
        }
        cout << "? " << X << " " << Y << endl;
        int D;
        cin >> D;
        if (D == 0) {
            cout << "! " << X << " " << Y << endl;
        } else {
            assert(cand.size() >= 2);
            cout << "! " << cand[1].first << " " << cand[1].second << endl;
        }
    }
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