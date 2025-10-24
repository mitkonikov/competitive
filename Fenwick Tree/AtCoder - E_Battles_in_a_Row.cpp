#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct FenwickTree {
    vector<int> fwt;

    FenwickTree(int n) {
        fwt.resize(n, 0);
    }

    void addFWT(int ind, int val = 1) {
        for (ind++; ind < fwt.size(); ind+=ind&-ind)
            fwt[ind]+=val;
    }

    int getFWT(int ind) {
        int s = 0;
        for (ind++; ind > 0; ind-=ind&-ind)
            s += fwt[ind];
        return s;
    }
};

int main() {
    int N, H, M;
    cin >> N >> H >> M;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    // { x, y } such that x > x1 and y > y1
    vector<pair<int, int>> points{ make_pair(H, M) };
    
    for (int i = 0; i < N; i++) {
        // filter
        sort(points.rbegin(), points.rend());
        FenwickTree fwt(M + 10);
        vector<pair<int, int>> new_points;
        for (int j = 0; j < points.size(); j++) {
            if (fwt.getFWT(M - points[j].second)) {
                continue;
            }
            fwt.addFWT(M - points[j].second);

            auto [oldA, oldB] = points[j];
            const int newA = oldA - A[i].first;
            const int newB = oldB - A[i].second;
            if (newA >= 0) new_points.push_back({ newA, oldB });
            if (newB >= 0) new_points.push_back({ oldA, newB });
        }

        if (new_points.empty()) {
            cout << i << endl;
            return 0;
        }

        points.swap(new_points);
    }
    cout << N << endl;
    return 0;
}