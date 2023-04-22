#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 2) {
        cout << "! 1" << endl;
        return 0;
    }
    int L = 1, R = N + 1;
    while (R - L > 1) {
        int MID = (R + L) / 2;
        cout << "? " << MID << endl;
        int ans;
        cin >> ans;
        if (ans == 0) L = MID;
        else R = MID;
    }
    cout << "! " << L << endl;
    return 0;
}