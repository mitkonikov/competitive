#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        ll cube = (ll)i * i * i;
        if (i % 2 == 1) cube *= -1;
        sum += cube;
    }
    cout << sum << endl;
    return 0;
}