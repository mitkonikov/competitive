#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 300000;
ll pot[N], prec[N];

void initialize(int n) {
    for (int i = 1; i <= n; ++i) {
        prec[i] = i;
        pot[i] = 0;
    }
}
int find(int x) {
    if (prec[x] == x) return x;
    int rx = find(prec[x]);          // rx is the root of x
    pot[x] = pot[prec[x]] + pot[x];  // add all potentials along the
                                     // path,i.e.,potential calculated wrt root
    prec[x] = rx;
    return rx;
}
bool merge(int a, int b, int d) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb && pot[a] - pot[b] != d)
        return false;
    else if (ra != rb) {
        pot[ra] = d + pot[b] - pot[a];
        prec[ra] = rb;
    }
    return true;
}
int main() {
    int n;  // no. of variables
    cin >> n;
    int m;  // no. of equations
    cin >> m;
    initialize(n + 1);
    
    for (int i = 1; i <= m; ++i) {  // consider 1-based indexing of variables
        int a, b, d;                // asserting a-b=d;
        cin >> a >> b >> d;
        bool ok = merge(a, b, d);
        if (ok) cout << i << " ";
    }
    cout << endl;
    // queries of type y-x=? can be given through pot[y]-pot[x] (only when then
    // are in same component i.e., can be extracted from the information so far
    // )
    return 0;
}