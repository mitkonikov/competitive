#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct FenwickTree {
    vector<long long> fwt;

    FenwickTree(int n) {
        fwt.resize(n, 0);
    }

    void addFWT(int ind, long long val = 1) {
        for (ind++; ind < fwt.size(); ind+=ind&-ind)
            fwt[ind]+=val;
    }

    long long getFWT(int ind) {
        long long s = 0;
        for (ind++; ind > 0; ind-=ind&-ind)
            s += fwt[ind];
        return s;
    }
};

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    FenwickTree X(n + 10), Y(n + 10);
    FenwickTree XC(n + 10), YC(n + 10);
    for (int i = 0; i < q; i++) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            // x--; y--;
            XC.addFWT(x);
            YC.addFWT(y);
            int onX = X.getFWT(x) - X.getFWT(x-1);
            int onY = Y.getFWT(y) - Y.getFWT(y-1);
            X.addFWT(x, -onX+1);
            Y.addFWT(y, -onY+1);
        } else if (t == 2) {
            int x, y;
            scanf("%d%d", &x, &y);
            // x--; y--;
            XC.addFWT(x, -1);
            YC.addFWT(y, -1);
            int onX = XC.getFWT(x) - XC.getFWT(x-1);
            int onY = YC.getFWT(y) - YC.getFWT(y-1);
            if (onX <= 0) {
                X.addFWT(x, -1);
            }
            if (onY <= 0) {
                Y.addFWT(y, -1);
            }
        } else {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            // x1--; y1--; x2--; y2--;
            int diffX = X.getFWT(x2) - X.getFWT(x1 - 1);
            int diffY = Y.getFWT(y2) - Y.getFWT(y1 - 1);
            if ((diffX == x2 - x1 + 1) || (diffY == y2 - y1 + 1)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}