#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll N;
    cin >> N;
    while (N > 0 && N % 2 == 0) N /= 2;
    while (N > 0 && N % 3 == 0) N /= 3;
    cout << (N > 2 ? "No" : "Yes") << endl;
    return 0;
}