#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (a * 2 == b || a * 2 + 1 == b) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    cout << flush;
    return 0;
}