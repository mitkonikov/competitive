#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(a.begin(), a.end());
    for (auto el: a) {
        cout << el << endl;
    }
    cout << flush;
    return 0;
}