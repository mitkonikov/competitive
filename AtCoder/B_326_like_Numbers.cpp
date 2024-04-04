#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = N;; i++) {
        int d1 = i / 100;
        int d2 = i / 10 % 10;
        if ((i % 10) == d1 * d2) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}