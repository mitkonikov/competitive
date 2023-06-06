#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll N;
    cin >> N;
    while (N != 1) {
        cout << N << " ";
        if (N % 2 == 0) {
            N /= 2;
        } else {
            N = N * 3 + 1;
        }
    }
    cout << 1 << endl;
    return 0;
}