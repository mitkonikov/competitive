#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < k; i++) {
        if (a.empty()) break;
        a.pop_back();
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (i < a.size()) cout << a[i] << " ";
        else cout << 0 << " ";
    }
    cout << endl;
    cout << flush;
    return 0;
}