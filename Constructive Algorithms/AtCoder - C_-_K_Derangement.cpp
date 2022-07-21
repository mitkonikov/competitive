#include <bits/stdc++.h>
#define ll long long

using namespace std;

// 1 2 3 4 5 6 7 8
// 4 5 6 7 8 1 2 3
// 5 6 7 8 1 2 3 4

// 1 2 3 4 5 6  7  8  9 10 11 12 13 14 15
// 4 5 6 7 8 9 10 11 12 13 14 15  1  2  3
// 4 5 6 1 2 3 10 11 12  7  8  9 13 14 15
// 4 5 6 1 2 3 10 11 12 13 14 15  7  8  9
// ..... ..... .................  .......
// f     s      t                 w

int main() {
    int n, k;
    cin >> n >> k;

    if ((n-k) * 2 < n) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans(n+1, -1);
    set<int> not_used;
    for (int i = 0; i < n; i++) not_used.insert(i+1);
    for (int i = 1; i <= n; i++) {
        if (i > k) break;
        ans[i] = i + k;
        not_used.erase(i+k);
    }

    for (int i = n - k, c = 0; c < k; i--, c++) {
        ans[i] = i + k;
        not_used.erase(i+k);
    }
    
    for (int i = k+1; i <= n; i++) {
        if (ans[i] == -1) {
            int smallest = *not_used.begin();
            if (abs(smallest - i) >= k) {
                ans[i] = smallest;
                not_used.erase(smallest);
            } else {
                smallest = *not_used.lower_bound(i+k);
                ans[i] = smallest;
                not_used.erase(smallest);
            }
        }
    }
    
    for (int i = k+1; i <= n; i++) {
        if (ans[i] == -1) {
            int smallest = *not_used.begin();
            if (abs(smallest - i) >= k) {
                ans[i] = smallest;
                not_used.erase(smallest);
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}