#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        if (S <= X) sum += S;
    }
    cout << sum << endl;
    return 0;
}