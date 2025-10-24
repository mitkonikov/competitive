#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    const int N = S.size();
    cout << S.substr(0, N / 2) << S.substr(N / 2 + 1) << endl;
    return 0;
}