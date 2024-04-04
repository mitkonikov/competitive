#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    ll A = 0, B = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        A += x;
        B += y;
    }
    if (A == B) {
        cout << "Draw" << endl;
    } else if (A > B) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
    return 0;
}