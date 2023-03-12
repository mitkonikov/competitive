#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> occ({ -1 });
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        if (X == 3) {
            occ.push_back(i);
        }
    }
    occ.push_back(N);
    int ans = 0;
    for (int i = 1; i + 3 < occ.size(); i++) {
        ans = max(ans, (occ[i+3]-1) - (occ[i-1]+1) + 1);
    }
    cout << ans << endl;
    return 0;
}