#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string at = "atcoder";
    int l, r;
    cin >> l >> r;
    for (int i = l-1; i <= r-1; i++) {
        cout << at[i];
    } cout << endl;
    cout << flush;
    return 0;
}