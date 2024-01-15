#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll N;
    cin >> N;
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    N--;
    vector<int> A;
    while (N > 0) {
        A.push_back((N % 5) * 2);
        N /= 5;
    }
    reverse(A.begin(), A.end());
    for (auto el: A) cout << el;
    cout << endl;
    return 0;
}