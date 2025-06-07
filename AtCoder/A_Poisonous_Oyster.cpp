#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    if (S == "sick" && T == "fine") {
        cout << 2 << endl;
    } else if (S == "fine" && T == "sick") {
        cout << 3 << endl;
    } else if (S == "fine" && T == "fine") {
        cout << 4 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}