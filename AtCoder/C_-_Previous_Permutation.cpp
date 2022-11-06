#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    std::prev_permutation(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << " ";
    }
    cout << endl;

    cout << flush;
    return 0;
}