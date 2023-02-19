#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n;r = n;
        vector<int> v(n), g(n);
        for (int i = 0; i < n; i++)cin >> v[i];
        for (int i = 0; i < n; i++)cin >> g[i];
        for (int i = n - 1, j = n - 1; i >= 0, j >= 0; i--) {
            while (j >= 0 && v[j] != g[i])j--;
            if (j < 0)break;
            else {
                r--;
            }
        }
        cout << r << endl;
    }
}