#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    cout << (N - M + 1 + P - 1) / P << endl;
    return 0;
}