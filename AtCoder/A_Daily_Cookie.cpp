#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    string S;
    cin >> S;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '@') count++;
    }
    cout << (N - count + D) << endl;
    return 0;
}