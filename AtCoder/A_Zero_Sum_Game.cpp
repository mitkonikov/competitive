#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << -sum << endl;
    return 0;
}